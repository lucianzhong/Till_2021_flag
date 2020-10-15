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

// 1. 工厂模式
// 在工厂模式中，我们在创建对象时不会对客户端暴露创建逻辑，并且是通过使用一个共同的接口来指向新创建的对象
// 工厂模式作为一种创建模式，一般在创建复杂对象时，考虑使用，在创建简单对象时，建议直接new完成一个实例对象的创建

// 1.1简单工厂模式
// 主要特点是需要在工厂类中做判断，从而创造相应的产品，当增加新产品时，需要修改工厂类
// 使用简单工厂模式，我们只需要知道具体的产品型号就可以创建一个产品
// 缺点：工厂类集中了所有产品类的创建逻辑，如果产品量较大，会使得工厂类变的非常臃肿


// 模式动机
// 考虑一个简单的软件应用场景，一个软件系统可以提供多个外观不同的按钮（如圆形按钮、矩形按钮、菱形按钮等）， 这些按钮都源自同一个基类，
// 不过在继承基类后不同的子类修改了部分属性从而使得它们可以呈现不同的外观，
// 如果我们希望在使用这些按钮时，不需要知道这些具体按钮类的名字，只需要知道表示该按钮类的一个参数，并提供一个调用方便的方法，
// 把该参数传入方法即可返回一个相应的按钮对象，此时，就可以使用简单工厂模式

// 简单工厂模式(Simple Factory Pattern)：又称为静态工厂方法(Static Factory Method)模式，它属于类创建型模式。
// 在简单工厂模式中，可以根据参数的不同返回不同类的实例。简单工厂模式专门定义一个类来负责创建其他类的实例，被创建的实例通常都具有共同的父类

// 简单工厂模式包含如下角色:
// Factory:工厂角色
// 工厂角色负责实现创建所有实例的内部逻辑
// Product：抽象产品角色
// 抽象产品角色是所创建的所有对象的父类，负责描述所有实例所共有的公共接口
// ConcreteProduct：具体产品角色
// 具体产品角色是创建目标，所有创建的对象都充当这个角色的某个具体类的实例


// 将对象的创建和对象本身业务处理分离可以降低系统的耦合度，使得两者修改起来都相对容易。
// 在调用工厂类的工厂方法时，由于工厂方法是静态方法，使用起来很方便，可通过类名直接调用，而且只需要传入一个简单的参数即可，在实际开发中，还可以在调用时将所传入的参数保存在XML等格式的配置文件中，修改参数时无须修改任何源代码。
// 简单工厂模式最大的问题在于工厂类的职责相对过重，增加新的产品需要修改工厂类的判断逻辑，这一点与开闭原则是相违背的。
// 简单工厂模式的要点在于：当你需要什么，只需要传入一个正确的参数，就可以获取你所需要的对象，而无须知道其创建细节


// 1.11. 模式应用
// JDK类库中广泛使用了简单工厂模式，如工具类java.text.DateFormat，它用于格式化一个本地日期或者时间。
// public final static DateFormat getDateInstance();
// public final static DateFormat getDateInstance(int style);
// public final static DateFormat getDateInstance(int style,Locale
// locale);
// Java加密技术
// 获取不同加密算法的密钥生成器:

// KeyGenerator keyGen=KeyGenerator.getInstance("DESede");
// 创建密码器:

// Cipher cp=Cipher.getInstance("DESede");


// 关键代码：创建过程在工厂类中完成
​
//定义产品类型信息

typedef enum
{
    Tank_Type_56,
    Tank_Type_96,
    Tank_Type_Num
}Tank_Type;
​
//抽象产品类
class Tank
{
public:
    virtual const string& type() = 0;
};
​
//具体的产品类
class Tank56 : public Tank
{
public:
    Tank56():Tank(),m_strType("Tank56")
    {
    }
​
    const string& type() override
    {
        cout << m_strType.data() << endl;
        return m_strType;
    }
private:
    string m_strType;
};
​
//具体的产品类
class Tank96 : public Tank
{
public:
    Tank96():Tank(),m_strType("Tank96")
    {
    }
    const string& type() override
    {
        cout << m_strType.data() << endl;
        return m_strType;
    }
​
private:
    string m_strType;
};
​
//工厂类
class TankFactory
{
public:
    //根据产品信息创建具体的产品类实例，返回一个抽象产品类
    Tank* createTank(Tank_Type type)
    {
        switch(type)
        {
        case Tank_Type_56:
            return new Tank56();
        case Tank_Type_96:
            return new Tank96();
        default:
            return nullptr;
        }
    }
};
​
​
int main()
{
    TankFactory* factory = new TankFactory();
    Tank* tank56 = factory->createTank(Tank_Type_56);
    tank56->type();
    Tank* tank96 = factory->createTank(Tank_Type_96);
    tank96->type();
​
    delete tank96;
    tank96 = nullptr;
    delete tank56;
    tank56 = nullptr;
    delete factory;
    factory = nullptr;
​
    return 0;
}

