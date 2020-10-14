// 参考
// https://www.cnblogs.com/carsonzhu/p/5528901.html


#include "bank.h"
#include <iostream>
#include <clocale>
#include <chrono>
#include <cstdlib>


Bank::Bank(int window, int close_time)
    : _queue_number(window), _close_time(close_time),
      _total_time(0), _customer_number(0)
{
    _work_queue = new std::queue<QueueNode>[window];

    srand(std::chrono::system_clock ::to_time_t(std::chrono::system_clock::now()));
}

Bank::~Bank()
{
    delete[] _work_queue;
}

void Bank::OpenForDay()
{
    // 第一个客户到达
    _event_list.push_back({0, 0});
}

// 客户到达事件
// 客户到达时，有三件事需要做：
// １：为此时刻到达的客户随机产生一个办理事务需要时间
// ２：随机产生下一客户到达的时间间隔
// ３：把到达的客户放入一个最短的工作队列
void Bank::CustomerArrived(Event *event)
{
    ++_customer_number;

    int duration_time, inter_time;

    // 此时刻到达客户办理事务需要时间
    duration_time = rand() % 1800 + 1; //一个客户最多要30分钟
    // 下一个客户在从event->_occur_time+inter_time时刻到来
    inter_time = rand() % 600 + 1; // 最多10分钟来一个客户

    // 下一个客户到达时间
    int t = event->_occur_time + inter_time;

    // 银行还没有关门
    if (t < _close_time)
    {
        _event_list.push_back({t, 0});
        // 按到达时间排序事件表，早前晚后
        SortEventList();
    }
    // 选一个最短队列排队
    int i;
    i = FindShortestQueue();

    _work_queue[i].push({event->_occur_time, duration_time});

    if (_work_queue[i].size() == 1)
    {
        // 这个i队列第一个客户，生成他的离开事件
        _event_list.push_back(
            {event->_occur_time + duration_time, i + 1});
        SortEventList();
    }
}

void Bank::CustomerDeparture(Event *event)
{
    int i = event->_type - 1;

    QueueNode customer;

    // 客户事务处理完毕，离开
    customer = _work_queue[i].front();
    _work_queue[i].pop();

    _total_time += event->_occur_time - customer._arrival_time;

    // 第i个队列的一个离开事件
    if (!_work_queue[i].empty())
    {
        customer = _work_queue[i].front();
        _event_list.push_back(
            {customer._duration_time + event->_occur_time, i + 1});
        SortEventList();
    }
}

int Bank::FindShortestQueue()
{
    int result = 0;
    for (int i = 0; i < _queue_number; ++i)
    {
        if (_work_queue[result].size() > _work_queue[i].size())
            result = i;
    }
    return result;
}

void Bank::SortEventList()
{
    // 方法一，Lambda表达式：
    _event_list.sort(
        [](const Event &e1, const Event &e2) -> bool { return e1._occur_time < e2._occur_time; });

    // 方法二：
    // 你知道怎么写一个函数来比较两个event吗？
    // 其实就是把Lambda表达式写成一个函数，把
    // 这个函数作为sort的参数就可以了。

    // 方法三，使用 struct Event::operator< ：
    _event_list.sort();

    // 注意：上面的方法一和方法二可以注释掉任何一个，
    // 写两个，只是为了演示。
}

void Bank::Simulation()
{
    OpenForDay();
    Event event;
    while (!_event_list.empty())
    {
        event = _event_list.front();
        _event_list.pop_front();
        if (event._type == 0) // 到达事件
            CustomerArrived(&event);
        else
            CustomerDeparture(&event);
    }
    // 计算并输出平均逗留时间
    std::cout << "客户数：" << _customer_number << std::endl
               << "总逗留时间（小时）：" << (double)_total_time / 3600.0
               << std::endl
               << "平均逗留时间（分钟）："
               << (double)_total_time / (double)(_customer_number * 60)
               << std::endl;
}

int main(int argc, wchar_t *argv[], wchar_t *env[])
{
    // _wsetlocale(LC_ALL, L"");

    Bank bank;
    bank.Simulation();
    return 0;
}