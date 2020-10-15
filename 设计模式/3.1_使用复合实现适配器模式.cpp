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

// 3、适配器模式
// 适配器模式可以将一个类的接口转换成客户端希望的另一个接口，使得原来由于接口不兼容而不能在一起工作的那些类可以在一起工作。
// 通俗的讲就是当我们已经有了一些类，而这些类不能满足新的需求，此时就可以考虑是否能将现有的类适配成可以满足新需求的类。适配器类需要继承或依赖已有的类，实现想要的目标接口。

// 缺点：过多地使用适配器，会让系统非常零乱，不易整体进行把握。比如，明明看到调用的是 A 接口，其实内部被适配成了 B 接口的实现，
// 一个系统如果太多出现这种情况，无异于一场灾难。因此如果不是很有必要，可以不使用适配器，而是直接对系统进行重构。

// 3.1、使用复合实现适配器模式
/*
* 关键代码：适配器继承或依赖已有的对象，实现想要的目标接口。
* 以下示例中，假设我们之前有了一个双端队列，新的需求要求使用栈和队列来完成。
  双端队列可以在头尾删减或增加元素。而栈是一种先进后出的数据结构，添加数据时添加到栈的顶部，删除数据时先删   除栈顶部的数据。因此我们完全可以将一个现有的双端队列适配成一个栈。
*/
​
//双端队列， 被适配类
// 我们有一个双端队列，要把它适配成栈和队列的形式，虽然使用双端队列也可以实现数据，但是并不是那么好使用，
// 所以就把它适配（包装）一下，成为栈和队列的形式对外使用


//顺序类，抽象目标类
class Sequence
{
public:
    virtual void push(int x) = 0;
    virtual void pop() = 0;
};

/* to be adatper */  //双端队列， 被适配类
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

/* LIFO */ //栈,后进先出, 适配类
class Stack: public Sequence
{
public:
    void push(int x)
    {//将元素添加到堆栈的顶部
        queue.push_front(x);
    }
    void pop()
    {//从堆栈中删除顶部元素
        queue.pop_front();
    }
private:
    Dqueue queue;
};

/* FIFO */ //队列，先进先出，适配类
class Queue: public Sequence
{
public:
//将元素添加到队列尾部
    void push(int x)
    {
        queue.push_back(x);
    }
    //从队列中删除顶部元素
    void pop()
    {
        queue.pop_front();
    }
private:
    Dqueue queue;
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

