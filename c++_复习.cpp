1. 
new operator(即 new 操作符)总是做这两件事，无论如何你是不能改变其行为。
new操作符是由C++语言内建的, 就像sizeof那样, 不能改变意义, 总是做相同的事情:
    调用operator new (sizeof(A))
    调用A:A()
    返回指针

第一: 它分配足够的内存, 用来放置某类型的对象.
void * operator new (size_t size);
其返回类型void*. 即返回一个指针, 指向一块原始的, 未设置初始值的内存。
函数中的size_t参数表示需要分配多少内存, 你可以将operator new 重载, 加上额外的参数, 但第一个参数类型必须总是size_t.

第二: 它调用一个构造函数, 为刚才分配的内存中的那个对象设定初始值。

第三: 对象被分配了空间并构造完成, 返回一个指向该对象的指针


同样, delete关键字做两件事:
第一: 调用对象析构函数
第二: 调用operator delete( )释放对象所占用的内存

string* pte = new string("KobeBryant");
delete ptr -> ptr->~string -> operator delete( ptr )
void operator delete(void* memoryToBeDeallocated);
同样, 我们能做的也只有重载operator delete( void* ) 来自己手动管理内存释放


2. 
类中静态数据成员与静态类方法: 
静态数据成员: 属于所有对象而不是特定对象, 为了实现共享数据
静态类方法: 通过类名::FunName( )调用, 不能通过对象调用.
它们不能通过对象调用是因为它们没有隐含的this指针

class LeakDetector{
public:
	// LeakDetector.cpp和被测试的.cpp都会包 LeakDetector.h头文件
	// 因此两个源文件中会创建两个静态LeakDetector类对象 exitCounter (两个静态类对象同名, 但是它们的链接属性均为内链接(只在当前源文件有效), 因此不会重定义), 
    // 如果此时两个对象析构, 会调用两次析构函数, 调用两次内存泄漏检测函数. 而我们的预期是只调用一次内存泄漏检测函数. 所以我们声明一个所有类对象共享的静态变量来实现我们的目的
	static size_t _callCount;
 
	LeakDetector( ){ ++_callCount; }
	~LeakDetector( ){ if(0 == --_callCount) _LeakDetector( ); }
 
private:
	void _LeakDetector( );
};
 
// 静态对象
static LeakDetector exitCounter;

// 初始化 LeakDetector类中定义的静态变量
size_t LeakDetector::_callCount = 0;