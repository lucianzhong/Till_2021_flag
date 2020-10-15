

// 并发代码设计
// 并发代码的设计比基本数据结构的设计和使用要频繁的多，要将眼界放宽，才能构建出能有效工作的更大的架构。
// 在写多线程代码时，你不仅需要考虑一般因素，如封装、继承、友元等等，你还需要考虑哪些数据需要被共享、如何同步这些数据、哪些线程需要等待哪些另外的线程，等等。

// 在代码设计时，你需要考虑要用多少个线程、每个线程做什么工作、是使用“全能”(什么工作都能做)的线程还是“专业”(只能做一种工作)的线程，还是混合着使用，这些选择将决定你代码的性能和清晰度。

// 基于数据的工作划分
// 最简单的并行算法是std::for_each，它对一个数据集中的每个元素执行相同的操作。为了并发这个算法，你可以为每个元素都分配一个处理线程。
// 如何划分才能获得最大的优化性能很大程度上决定于数据结构的实现细节。最简单的方式是为每个线程分配最多N个元素，但是不管如何划分，每个线程都只管自己分配到的元素，直到操作完成前，没有任何与其他线程的通信。
// 使用过MPI(Message Passing Interface)或openMP架构的人应该非常熟悉：一个任务被划分为一个并行任务集，工作线程独立的执行这些任务，并将结果合并到最终的还原步骤中去。
// 还原步骤就像accumulate一样，只不过accumulate是累加，结果的合并可能会有所不同。

// 有时候任务并不能被整洁的划分，因为数据可能只有在运行时才能被明确的划分，但这非常适用于递归算法，如快速排序。
// 快速排序的基本思想是：随意挑选一个元素，然后将集合中的所有元素按小于该元素和大于该元素分为两组，对两组元素分别再执行上诉操作，如此递归循环，最后将排序集合并，即为最终排序后的集合。
// 你不能简单的划分数据来使其并行，因为分组是运行时才决定的，如果你一定要并行这种算法的话，很自然的你就会想到递归。
// 由于不得不对前后两组分别进行排序，所以每次递归都会更多次的调用quick_sort函数，这些递归调用是完全独立的，因为它们访问的是不同元素的数据集，所以可以并发调用。

// 在基础篇中，我们实现了一个并发的快速排序，使用std::async可以要求C++标准库来决定何时在一个新线程上执行任务，以及何时同步执行它。这是非常重要的，因为太多线程可能会导致你的应用程序变得很慢。
// 在递归函数中使用这样的方式是非常好的，你只需要注意线程的数量，而std::async可以帮你处理这个问题，但这不是唯一的方式。

// 一个替代的方案就是使用std::thread::hardware_concurrency()函数来选择线程的数量，然后，除了为每个递归调用开启一个新线程，你可以将要排序的数据块push到一个线程安全stack中去，如果一个线程没有事做，
// 它要么已经完成了交给它的数据块的排序，要么正在等待数据块进行排序，它可以从stack中获取一个数据块，并对它们进行排序。


#include <random>
#include <cstdlib>

#include "myQuickSort.h"

int main()
{
	// 随机数生成
	std::list<int> myList;
	std::uniform_int_distribution<unsigned> u(0, 1000);
	std::default_random_engine e;
	for (int i = 0; i < 1000; ++i) {
		myList.push_back(u(e));
	}

	auto start = std::chrono::high_resolution_clock::now();
	auto res1 = sequential_quick_sort<int>(myList);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "seq: " 
		<< std::chrono::duration<double, std::milli>(end - start).count() 
		<< "ms\n";

	start = std::chrono::high_resolution_clock::now();
	auto res2 = parallel_quick_sort<int>(myList);
	end = std::chrono::high_resolution_clock::now();
	std::cout << "par: " 
		<< std::chrono::duration<double, std::milli>(end - start).count() 
		<< "ms\n";

	/*for (auto &i : res2)
	{
	std::cout << i << std::ends;
	}*/
}