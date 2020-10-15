

// 5_适配器模式

// 将一个类的接口转换成客户希望的另外一个接口。适配器模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。好比日本现在就只提供110V的电压，而我的电脑就需要220V的电压，那怎么办啦？
// 适配器就是干这活的，在不兼容的东西之间搭建一座桥梁，让二者能很好的兼容在一起工作

// 意图：

//        将一个类的接口转换成客户希望的另外一个接口。Adapter 模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。 
// 适用性：

//        你想使用一个已经存在的类，而它的接口不符合你的需求。

//        你想创建一个可以复用的类，该类可以与其他不相关的类或不可预见的类（即那些接口可能不一定兼容的类）协同工作。

//       （仅适用于对象Adapter ）你想使用一些已经存在的子类，但是不可能对每一个都进行子类化以匹配它们的接口。对象适配器可以适配它的父类接口。


// 适配器有两种实现方式：类适配器和对象适配器


//  模式应用
// Sun公司在1996年公开了Java语言的数据库连接工具JDBC，JDBC使得Java语言程序能够与数据库连接，并使用SQL语言来查询和操作数据。JDBC给出一个客户端通用的抽象接口，每一个具体数据库引擎（如SQL Server、Oracle、MySQL等）的JDBC驱动软件都是一个介于JDBC接口和数据库引擎接口之间的适配器软件。抽象的JDBC接口和各个数据库引擎API之间都需要相应的适配器软件，这就是为各个不同数据库引擎准备的驱动程序



#include <iostream>
using namespace std;
 

// 类的适配器
// Targets
class Target
{
public:
	virtual void Request()    // Methods  
	{
		cout << "Target::Request" << endl;
	}
};
 
// Adaptee  // 被适配的
class Adaptee
{
public:
	void SpecificRequest()   // Methods 
	{
		cout << "Adaptee::SpecificRequest" << endl;
	}
};
 
// Adapter
class Adapter : public Target, Adaptee
{
public:
	void Request()        // Implements ITarget interface
	{
		// Possibly do some data manipulation  
		// and then call SpecificRequest   
		this->Request();
		this->SpecificRequest();
	}
};
 

// Client
int main(int argc, char *argv[])
{
	Target *targetObj = new Adapter();
	targetObj->Request();
 
	delete targetObj;
	targetObj = NULL;
 
	return 0;
}




// 对象适配器
class Target
{
public:
	Target(){}
	virtual ~Target(){}
	virtual void Request()
	{
		cout << "Target::Request" << endl;
	}
};

// 被适配
class Adaptee
{
public:
	void SpecificRequest()
	{
		cout << "Adaptee::SpecificRequest" << endl;
	}
};


class Adapter : public Target
{
public:
	Adapter() : m_Adaptee(new Adaptee) {}
 
	~Adapter()
	{
		if (m_Adaptee != NULL)
		{
			delete m_Adaptee;
			m_Adaptee = NULL;
		}
	}
 
	void Request()
	{
		m_Adaptee->SpecificRequest();
	}
 
private:
	Adaptee *m_Adaptee;
};
 
 
int main(int argc, char *argv[])
{
	Target *targetObj = new Adapter();
	targetObj->Request();
 
	delete targetObj;
	targetObj = NULL;
 
	return 0;
}



// 适配器模式很容易理解和实现，在以后的项目中，多多的进行实践，将学到的理论知识运用到实际的项目中去，写出漂亮的代码
// 这里列举一个c++ STL中的适配器例子，这是只是简单模型，想要深入请看STL源码剖析
// 这里target: Sequence
// adaptee是: deque
// 而被实现的适配器是queue和stack
// 在以后学习和开发中中要好好体会适配器原理，这个例子很简单导致不是很好理解，实际上这个例子很强大。需要仔细品味，掌握设计模式真正的精髓

//双端队列
class Deque
{
public:
	void push_back(int x) { cout << "Deque push_back" << endl; }
	void push_front(int x) { cout << "Deque push_front" << endl; }
	void pop_back() { cout << "Deque pop_back" << endl; }
	void pop_front() { cout << "Deque pop_front" << endl; }
};
//顺序容器
class Sequence
{
public:
	virtual void push(int x) = 0;
	virtual void pop() = 0;
};
//栈
class Stack : public Sequence
{
public:
	void push(int x) { deque.push_back(x); }
	void pop() { deque.pop_back(); }
private:
	Deque deque; //双端队列
};
//队列
class Queue : public Sequence
{
public:
	void push(int x) { deque.push_back(x); }
	void pop() { deque.pop_front(); }
private:
	Deque deque; //双端队列
};
int main()
{
	Sequence *s1 = new Stack();
	Sequence *s2 = new Queue();
	s1->push(1); s1->pop();
	s2->push(1); s2->pop();
	delete s1; delete s2;
	return 0;
}