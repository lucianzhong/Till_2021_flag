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
#include <iostream>
#include <functional>

using namespace std;

// 常用设计模式


​
void adcHurt()
{
    std::cout << "Adc Hurt" << std::endl;
}
​
void apcHurt()
{
    std::cout << "Apc Hurt" << std::endl;
}
​
//环境角色类， 使用传统的函数指针
class Soldier
{
public:
    typedef void (*Function)();
    Soldier(Function fun): m_fun(fun)
    {
    }
    void attack()
    {
        m_fun();
    }
private:
    Function m_fun;
};
​
//环境角色类， 使用std::function<>
class Mage
{
public:
    typedef std::function<void()> Function;
​
    Mage(Function fun): m_fun(fun)
    {
    }
    void attack()
    {
        m_fun();
    }
private:
    Function m_fun;
};
​
int main()
{
    Soldier* soldier = new Soldier(apcHurt);
    soldier->attack();
    delete soldier;
    soldier = nullptr;
    return 0;
}