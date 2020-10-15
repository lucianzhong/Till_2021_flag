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

// 抽象工厂模式提供创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
// 当存在多个产品系列，而客户端只使用一个系列的产品时，可以考虑使用抽象工厂模式。
// 缺点：当增加一个新系列的产品时，不仅需要现实具体的产品类，还需要增加一个新的创建接口，扩展相对困难

// 关键代码：在一个工厂里聚合多个同类产品。
// 以下代码以白色衣服和黑色衣服为例，白色衣服为一个产品系列，黑色衣服为一个产品系列。白色上衣搭配白色裤子，   
// 黑色上衣搭配黑色裤字。每个系列的衣服由一个对应的工厂创建，这样一个工厂创建的衣服能保证衣服为同一个系列。
​
// 抽象工厂模式与工厂方法模式最大的区别在于，工厂方法模式针对的是一个产品等级结构，
// 而抽象工厂模式则需要面对多个产品等级结构，一个工厂等级结构可以负责多个不同产品等级结构中的产品对象的创建 
// 当一个工厂等级结构可以创建出分属于不同产品等级结构的一个产品族中的所有对象时，
// 抽象工厂模式比工厂方法模式更为简单、有效率
// 抽象工厂模式(Abstract Factory Pattern)：提供一个创建一系列相关或相互依赖对象的接口，而无须指定它们具体的类。抽象工厂模式又称为Kit模式，属于对象创建型模式

// 抽象工厂模式包含四个角色：抽象工厂用于声明生成抽象产品的方法；
// 具体工厂实现了抽象工厂声明的生成抽象产品的方法，生成一组具体产品，这些产品构成了一个产品族，
// 每一个产品都位于某个产品等级结构中；抽象产品为每种产品声明接口，在抽象产品中定义了产品的抽象业务方法；
// 具体产品定义具体工厂生产的具体产品对象，实现抽象产品接口中定义的业务方法。



// 模式应用
// 在很多软件系统中需要更换界面主题，要求界面中的按钮、文本框、背景色等一起发生改变时，可以使用抽象工厂模式进行设计





//抽象上衣类
class Coat
{
public:
    virtual const string& color() = 0;
};
​
//黑色上衣类
class BlackCoat : public Coat
{
public:
    BlackCoat():Coat(),m_strColor("Black Coat")
    {
    }
​
    const string& color() override
    {
        cout << m_strColor.data() << endl;
        return m_strColor;
    }
private:
    string m_strColor;
};
​
//白色上衣类
class WhiteCoat : public Coat
{
public:
    WhiteCoat():Coat(),m_strColor("White Coat")
    {
    }
    const string& color() override
    {
        cout << m_strColor.data() << endl;
        return m_strColor;
    }
​
private:
    string m_strColor;
};
​
//抽象裤子类
class Pants
{
public:
    virtual const string& color() = 0;
};
​
//黑色裤子类
class BlackPants : public Pants
{
public:
    BlackPants():Pants(),m_strColor("Black Pants")
    {
    }
    const string& color() override
    {
        cout << m_strColor.data() << endl;
        return m_strColor;
    }
​
private:
    string m_strColor;
};
​
//白色裤子类
class WhitePants : public Pants
{
public:
    WhitePants():Pants(),m_strColor("White Pants")
    {
    }
    const string& color() override
    {
        cout << m_strColor.data() << endl;
        return m_strColor;
    }
​
private:
    string m_strColor;
};
​
//抽象工厂类，提供衣服创建接口
class Factory
{
public:
    //上衣创建接口，返回抽象上衣类
    virtual Coat* createCoat() = 0;
    //裤子创建接口，返回抽象裤子类
    virtual Pants* createPants() = 0;
};
​
//创建白色衣服的工厂类，具体实现创建白色上衣和白色裤子的接口
class WhiteFactory : public Factory
{
public:
    Coat* createCoat() override
    {
        return new WhiteCoat();
    }
​
    Pants* createPants() override
    {
        return new WhitePants();
    }
};
​
//创建黑色衣服的工厂类，具体实现创建黑色上衣和白色裤子的接口
class BlackFactory : public Factory
{
    Coat* createCoat() override
    {
        return new BlackCoat();
    }
​
    Pants* createPants() override
    {
        return new BlackPants();
    }
};








// 例子二
// 抽象工厂摸是的代码：
// Clothe和Shoes，分别为衣服和鞋子的抽象产品类。
// NiKeClothe和NiKeShoes，分别是耐克衣服和耐克衣服的具体产品类。

// 基类 衣服
class Clothe
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() {}
};

// 耐克衣服
class NiKeClothe : public Clothe
{
public:
    void Show()
    {
        std::cout << "我是耐克衣服，时尚我最在行！" << std::endl;
    }
};

// 基类 鞋子
class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}
};

// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是耐克球鞋，让你酷起来！" << std::endl;
    }
};
// 复制代码
// Factory为抽象工厂，提供了创建鞋子CreateShoes()和衣服产品CreateClothe()对象的接口。
// NiKeProducer为具体工厂，实现了创建耐克鞋子和耐克衣服的方式。

// 总厂
class Factory
{
public:
    virtual Shoes *CreateShoes() = 0;
	virtual Clothe *CreateClothe() = 0;
    virtual ~Factory() {}
};

// 耐克生产者/生产链
class NiKeProducer : public Factory
{
public:
    Shoes *CreateShoes()
    {
        return new NiKeShoes();
    }
	
	Clothe *CreateClothe()
    {
        return new NiKeClothe();
    }
};
// 复制代码
// main函数，构造耐克工厂对象，通过耐克工厂对象再创建耐克产品族的衣服和鞋子对象。同样，对象不再使用时，需要手动释放资源。

int main()
{
    // ================ 生产耐克流程 ==================== //
    // 鞋厂开设耐克生产线
    Factory *niKeProducer = new NiKeProducer();
    
	// 耐克生产线产出球鞋
    Shoes *nikeShoes = niKeProducer->CreateShoes();
	// 耐克生产线产出衣服
    Clothe *nikeClothe = niKeProducer->CreateClothe();
    
	// 耐克球鞋广告喊起
    nikeShoes->Show();
	// 耐克衣服广告喊起
    nikeClothe->Show();
	
    // 释放资源
    delete nikeShoes;
	delete nikeClothe;
    delete niKeProducer;


    return 0;
}
