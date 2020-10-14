#include "LeakDetector.h"

int main()
{

    // 忘记释放指针 b 申请的内存, 从而导致内存泄露
    int *a = new int;
    int *b = new int[12];

    delete a;
    // .内存泄露产生于 new/new[] 操作进行后没有执行 delete/delete[]
    return 0;
}
