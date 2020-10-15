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
// 4.2、饿汉单例模式
// 饿汉：饿了肯定要饥不择食。所以在单例类定义的时候就进行实例化。在访问量比较大，或者可能访问的线程比较多时，采用饿汉实现，可以实现更好的性能。这是以空间换时间

//饿汉式：线程安全，注意一定要在合适的地方去delete它
class Singleton
{
public:
    static Singleton* getInstance();
private:
    Singleton(){}                                    //构造函数私有
    Singleton(const Singleton&) = delete;            //明确拒绝
    Singleton& operator=(const Singleton&) = delete; //明确拒绝
​
    static Singleton* m_pSingleton;
};
​
Singleton* Singleton::m_pSingleton = new Singleton();
​
Singleton* Singleton::getInstance()
{
    return m_pSingleton;
}