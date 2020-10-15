#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <cstdlib>
#include <new>
#include <typeinfo>
#include <list>
#include <thread> // std::thread
#include <mutex>  // std::mutex
#include <stdio.h>
#include <string.h>

using namespace std;

// 常用设计模式

// 3.2、使用继承实现适配器模式

//顺序类，抽象目标类
class Sequence
{
public:
    virtual void push(int x) = 0;
    virtual void pop() = 0;
};

/* to be adatper */  //双端队列，被适配类
class Dqueue
{
public:
    void push_back(int x)
    {
        cout << "Dqueue push back " << x << endl;
    }
    void push_front(int x)
    {
        cout << "Dqueue push front " << x << endl;
    }
    void pop_back()
    {
        cout << "Dqueue pop back" << endl;
    }
    void pop_front()
    {
        cout << "Dqueue pop front" << endl;
    }
};

/* LIFO */  //栈,后进先出, 适配类
class Stack: public Sequence,private Dqueue
{
public:
    void push(int x)
    {
        push_front(x);
    }
    void pop()
    {
        pop_front();
    }
};

/* FIFO */  //队列，先进先出，适配类
class Queue: public Sequence, private Dqueue
{
public:
    void push(int x)
    {
        push_back(x);
    }
    void pop()
    {
        pop_front();
    }
};

int main()
{
    Sequence *st = new Stack();
    Sequence *qe = new Queue();
    st->push(1);
    st->pop();
    qe->push(2);
    qe->pop();
    delete st;
    delete qe;
    st = NULL;
    qe = NULL;
    return 0;
}

