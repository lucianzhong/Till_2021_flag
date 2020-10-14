

#include <iostream>   // std::cout, std::endl
#include <cassert>    // assert()
#include <ctime>      // clock()
#include <vector>     // std::vector

#include "MemoryPool.hpp"  // MemoryPool<T>
#include "StackAlloc.hpp"  // StackAlloc<T, Alloc>

// 插入元素个数
#define ELEMS 1000000
// 重复次数
#define REPS 100

// 我们要设计实现一个高性能的内存池，那么自然避免不了需要对比已有的内存，而比较内存池对内存的分配性能，
// 就需要实现一个需要对内存进行动态分配的结构（比如：链表栈）
int main()
{
    clock_t start;

    // 使用 STL 默认分配器
    // StackAlloc 是一个链表栈，接受两个模板参数，第一个参数是栈中的元素类型，第二个参数就是栈使用的内存分配器
    // std::allocator 是 C++标准库中提供的默认分配器，他的特点就在于我们在 使用 new 来申请内存构造新对象的时候，势必要调用类对象的默认构造函数，
    // 而使用 std::allocator 则可以将内存分配和对象的构造这两部分逻辑给分离开来，使得分配的内存是原始、未构造的。
    StackAlloc<int, std::allocator<int> > stackDefault;
    start = clock();
    for (int j = 0; j < REPS; j++) {
        assert(stackDefault.empty());
        for (int i = 0; i < ELEMS; i++)
          stackDefault.push(i);
        for (int i = 0; i < ELEMS; i++)
          stackDefault.pop();
    }
    std::cout << "Default Allocator Time: ";
    std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";

    // 使用内存池
    // 使用默认分配器的模板参数为 std::allocator，而使用内存池的模板参数为 MemoryPool
    StackAlloc<int, MemoryPool<int> > stackPool;
    start = clock();
    for (int j = 0; j < REPS; j++) {
        assert(stackPool.empty());
        for (int i = 0; i < ELEMS; i++)
          stackPool.push(i);
        for (int i = 0; i < ELEMS; i++)
          stackPool.pop();
    }
    std::cout << "MemoryPool Allocator Time: ";
    std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";

    return 0;
}

// 参考
// https://blog.csdn.net/xjtuse2014/article/details/52302083