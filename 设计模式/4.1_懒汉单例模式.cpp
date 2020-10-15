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

// 模式动机
// 对于系统中的某些类来说，只有一个实例很重要，例如，一个系统中可以存在多个打印任务，但是只能有一个正在工作的任务；一个系统只能有一个窗口管理器或文件系统；一个系统只能有一个计时工具或ID（序号）生成器。
// 如何保证一个类只有一个实例并且这个实例易于被访问呢？定义一个全局变量可以确保对象随时都可以被访问，但不能防止我们实例化多个对象。
// 一个更好的解决办法是让类自身负责保存它的唯一实例。这个类可以保证没有其他实例被创建，并且它可以提供一个访问该实例的方法。这就是单例模式的模式动机

// 实例
// 在操作系统中，打印池(Print Spooler)是一个用于管理打印任务的应用程序，通过打印池用户可以删除、中止或者改变打印任务的优先级，在一个系统中只允许运行一个打印池对象，如果重复创建打印池则抛出异常。现使用单例模式来模拟实现打印池的设计
// 适用环境
// 在以下情况下可以使用单例模式：

// 系统只需要一个实例对象，如系统要求提供一个唯一的序列号生成器，或者需要考虑资源消耗太大而只允许创建一个对象。
// 客户调用类的单个实例只允许使用一个公共访问点，除了该公共访问点，不能通过其他途径访问该实例。
// 在一个系统中要求一个类只有一个实例时才应当使用单例模式。反过来，如果一个类可以有几个实例共存，就需要对单例模式进行改进，使之成为多例模式
// 5.11. 模式应用
// 一个具有自动编号主键的表可以有多个用户同时使用，但数据库中只能有一个地方分配下一个主键编号，否则会出现主键重复，因此该主键编号生成器必须具备唯一性，可以通过单例模式来实现



// 4、单例模式
// 单例模式顾名思义，保证一个类仅可以有一个实例化对象，并且提供一个可以访问它的全局接口。实现单例模式必须注意一下几点：

// 单例类只能由一个实例化对象。

// 单例类必须自己提供一个实例化对象。

// 单例类必须提供一个可以访问唯一实例化对象的接口。

// 单例模式分为懒汉和饿汉两种实现方式。

// 4.1、懒汉单例模式
// 懒汉：故名思义，不到万不得已就不会去实例化类，也就是说在第一次用到类实例的时候才会去实例化一个对象。在访问量较小，甚至可能不会去访问的情况下，采用懒汉实现，这是以时间换空间。

// 4.1.1、非线程安全的懒汉单例模式

/*
* 关键代码：构造函数是私有的，不能通过赋值运算，拷贝构造等方式实例化对象。
*/
​
//懒汉式一般实现：非线程安全，getInstance返回的实例指针需要delete
class Singleton
{
public:
    static Singleton* getInstance();
    ~Singleton(){}
​
private:
    Singleton(){}                                        //构造函数私有，确保用户无法通过new关键字直接实例化它
    Singleton(const Singleton& obj) = delete;            //明确拒绝
    Singleton& operator=(const Singleton& obj) = delete; //明确拒绝

    static Singleton* m_pSingleton;  // 静态私有成员变量
};
​
Singleton* Singleton::m_pSingleton = NULL;
​
Singleton* Singleton::getInstance()
{
    if(m_pSingleton == NULL)
    {
        m_pSingleton = new Singleton;
    }
    return m_pSingleton;
}


Singleton* p1 = Singleton::getInstance();
Singleton* p2 = p1->getInstance();
Singleton & ref = * Singleton::getInstance();



// 4.1.2、线程安全的懒汉单例模式
std::mutex mt;

class Singleton
{
public:
    static Singleton* getInstance();
private:
    Singleton(){}                                    //构造函数私有
    Singleton(const Singleton&) = delete;            //明确拒绝
    Singleton& operator=(const Singleton&) = delete; //明确拒绝

    static Singleton* m_pSingleton;

};
Singleton* Singleton::m_pSingleton = NULL;

Singleton* Singleton::getInstance()
{
    if(m_pSingleton == NULL)
    {
        mt.lock();
        if(m_pSingleton == NULL)
        {
            m_pSingleton = new Singleton();
        }
        mt.unlock();
    }
    return m_pSingleton;
}



// 4.1.3、返回一个reference指向local static对象
// 这种单例模式实现方式多线程可能存在不确定性：任何一种non-const static对象，不论它是local或non-local,在多线程环境下“等待某事发生”都会有麻烦。解决的方法：在程序的单线程启动阶段手工调用所有reference-returning函数。这种实现方式的好处是不需要去delete它。
class Singleton
{
public:
    static Singleton& getInstance();
private:
    Singleton(){}
    Singleton(const Singleton&) = delete;  //明确拒绝
    Singleton& operator=(const Singleton&) = delete; //明确拒绝
};
​
​
Singleton& Singleton::getInstance()
{
    static Singleton singleton;
    return singleton;
}