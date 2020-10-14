#ifndef __BANK_H__
#define __BANK_H__


// #ifdef：如果预处理变量己定义，返回true
// #ifndef：如果预处理量未定义，返回true
// 只有测试为true时，才继续预处理直到#endif

#include <queue>
#include <list>

struct Event
{
    int _occur_time; // 事件发生的时刻
    int _type;       // 事件类型，0表示到达事件，1到
                     // 4 表示四个窗口的离开事件
    bool operator<(const Event &rhs)
    {
        return _occur_time < rhs._occur_time;
    }
};

struct QueueNode
{
    int _arrival_time;  // 客户到达时间
    int _duration_time; // 客户需要的服务员时间
};

class Bank
{
public:
    explicit Bank(int window_number = 4,
                  int close_time = 8 * 3600);
    ~Bank();
    void Simulation();

private:
    int _queue_number;    // 队列个数
    int _close_time;      // 关门时间
    int _total_time;      // 累计客户逗留时间
    int _customer_number; // 客户总数

    std::list<Event> _event_list;       // 事件链表
    std::queue<QueueNode> *_work_queue; // 工作队列

    void OpenForDay(); // 开门营业
    void CustomerArrived(Event *event); // 处理客户到达事件
    void CustomerDeparture(Event *event); // 处理客户离开事件
    int FindShortestQueue(); // 帮助客户选择一个最短的队列
    void SortEventList(); // 确保按照事件发生的时间顺序处理事件
};

#endif