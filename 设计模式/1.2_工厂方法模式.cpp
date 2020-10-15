
#include <stdio.h>
#include <string.h>

using namespace std;

// 常用设计模式

// 1.2、工厂方法模式
// 定义一个创建对象的接口，其子类去具体现实这个接口以完成具体的创建工作。如果需要增加新的产品类，
// 只需要扩展一个相应的工厂类即可。
// 缺点：产品类数据较多时，需要实现大量的工厂类，这无疑增加了代码量

// 工厂方法模式(Factory Method Pattern)又称为工厂模式，
// 也叫虚拟构造器(Virtual Constructor)模式或者多态工厂(Polymorphic Factory)模式，它属于类创建型模式
// 在工厂方法模式中，工厂父类负责定义创建产品对象的公共接口，而工厂子类则负责生成具体的产品对象，
// 这样做的目的是将产品类的实例化操作延迟到工厂子类中完成，即通过工厂子类来确定究竟应该实例化哪一个具体产品类

// 实例
// 日志记录器
// 某系统日志记录器要求支持多种日志记录方式，如文件记录、数据库记录等，且用户可以根据要求动态选择日志记录方式， 
// 现使用工厂方法模式设计该系统

// 基于工厂角色和产品角色的多态性设计是工厂方法模式的关键
// 使用工厂方法模式的另一个优点是在系统中加入新产品时，无须修改抽象工厂和抽象产品提供的接口，无须修改客户端，
// 也无须修改其他的具体工厂和具体产品，而只要添加一个具体工厂和具体产品就可以了。这样，系统的可扩展性也就变得非常好，完全符合“开闭原则”


/*
关键代码：创建过程在其子类执行。
*/

​
//产品抽象类
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

//抽象工厂类，提供一个创建接口  // 工厂父类
class TankFactory
{
public:
    //提供创建产品实例的接口，返回抽象产品类
    virtual Tank* createTank() = 0;
};
​
// 工厂子类
//具体的创建工厂类，使用抽象工厂类提供的接口，去创建具体的产品实例
class Tank56Factory : public TankFactory
{
public:
    Tank* createTank() override
    {
        return new Tank56();
    }
};
​
// 工厂子类
//具体的创建工厂类，使用抽象工厂类提供的接口，去创建具体的产品实例
class Tank96Factory : public TankFactory
{
public:
    Tank* createTank() override
    {
        return new Tank96();
    }
};
​
​
int main()
{
    TankFactory* factory56 = new Tank56Factory();
    Tank* tank56 = factory56->createTank();
    tank56->type();

    TankFactory* factory96 = new Tank96Factory();
    Tank* tank96 = factory96->createTank();
    tank96->type();
​
    delete tank96;
    tank96 = nullptr;
    delete factory96;
    factory96 = nullptr;
​
    delete tank56;
    tank56 = nullptr;
    delete factory56;
    factory56 = nullptr;
​
    return 0;
}