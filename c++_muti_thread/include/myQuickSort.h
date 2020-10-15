// myQuickSort.h
#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <atomic>
#include <algorithm>
#include <future>
//#include <boost\smart_ptr\shared_ptr.hpp>

#include "myStack.h"

template<typename T>
struct sorter
{
	struct chunk_to_sort
	{
		std::list<T> data;
		std::promise<std::list<T> > promise;
	};

	threadsafe_stack<chunk_to_sort> chunks;
	std::vector<std::thread> threads;
	unsigned const max_thread_count;
	std::atomic<bool> end_of_data;

	sorter() :
		max_thread_count(std::thread::hardware_concurrency() - 1),
		end_of_data(false)
	{}

	~sorter()
	{
		end_of_data = true;
		for (unsigned i = 0; i<threads.size(); ++i)
		{
			threads[i].join();
		}
	}

	void try_sort_chunk()
	{
		try {
			auto chunk = chunks.pop();
			if (chunk)
			{
				sort_chunk(chunk);
			}
		}
		catch (empty_stack &e)
		{
			//std::cout << e.what();
			e.what(); // 删除会跳出warning: 未引用的局部变量
		}
	}

	std::list<T> do_sort(std::list<T>& chunk_data)
	{
		if (chunk_data.empty())
		{
			return chunk_data;
		}

		std::list<T> result;
		// l.splice(iterator pos,list& x, iterator i)
		// 将x中i指向的元素移动插入到l中pos指向的位置之前
		result.splice(result.begin(), chunk_data, chunk_data.begin());
		T const& partition_val = *result.begin();

		// std::partition(iterator beg, iterator end, func)
		// 将[beg,end)中的元素按func分为两组，第一组使func返回true，第二组使func返回false
		// 返回分组后指向第二组的第一个元素的迭代器，不保证原有元素的顺序
		auto divide_point =
			std::partition(chunk_data.begin(), chunk_data.end(),
				[&](T const& val) {return val < partition_val; });

		chunk_to_sort new_lower_chunk;
		// l.splice(iterator pos, list& x, iterator beg, iterator end)
		// 将x中[beg,end)范围内元素移动插入到l中pos指向的位置之前
		new_lower_chunk.data.splice(new_lower_chunk.data.end(),
			chunk_data, chunk_data.begin(), divide_point);

		std::future<std::list<T> > new_lower =
			new_lower_chunk.promise.get_future();
		chunks.push(std::move(new_lower_chunk)); // 将new_lower_chunk压入到stack

		// 如果当前线程数小于允许的最大线程数，就继续开启一个排序线程
		if (threads.size()<max_thread_count)
		{
			threads.push_back(std::thread(&sorter<T>::sort_thread, this));
		}

		std::list<T> new_higher(do_sort(chunk_data));
		// l.splice(iterator pos, list& x)
		// 将x中所有元素移动插入到l中pos指向的位置之前
		result.splice(result.end(), new_higher);

		// 等待lower part完成排序。如果lower part还未完成或者还没开始，
		// 反正没事做，不如尝试在本线程内把别人的或自己的lower part也做了
		// 如果chunks为空，但是lower part还未完成，chunks.pop就会抛出empty_stack异常
		while (new_lower.wait_for(std::chrono::seconds(0)) !=
			std::future_status::ready)
		{
			try_sort_chunk();
		}
		result.splice(result.begin(), new_lower.get());
		return result;
	}

	void sort_chunk(std::shared_ptr<chunk_to_sort > const& chunk)
	{
		chunk->promise.set_value(do_sort(chunk->data));
	}

	void sort_thread()
	{
		while (!end_of_data)
		{
			try_sort_chunk();
			std::this_thread::yield();
		}
	}
};

template<typename T>
std::list<T> parallel_quick_sort(std::list<T> input)
{
	if (input.empty())
	{
		return input;
	}
	sorter<T> s;
	return s.do_sort(input);
}


// 一般的递归程序
template<typename T>
std::list<T> sequential_quick_sort(std::list<T> input)
{
	if (input.empty())
	{
		return input;
	}
	std::list<T> result;
	// l.splice(iterator pos,list& x, iterator i)
	// 将x中i指向的元素移动插入到l中pos指向的位置之前
	result.splice(result.begin(), input, input.begin());
	T const& pivot = *result.begin();

	// std::partition(iterator beg, iterator end, func)
	// 将[beg,end)中的元素按func分为两组，第一组使func返回true，第二组使func返回false
	// 返回分组后指向第二组的第一个元素的迭代器，不保证原有元素的顺序
	auto divide_point = std::partition(input.begin(), input.end(),
		[&](T const& t) {return t<pivot; });

	std::list<T> lower_part;
	// l.splice(iterator pos,list& x, iterator beg, iterator end)
	// 将x中[beg,end)范围内元素移动插入到l中pos指向的位置之前
	lower_part.splice(lower_part.end(), input, input.begin(), divide_point);

	auto new_lower(
		sequential_quick_sort(std::move(lower_part)));
	auto new_higher(
		sequential_quick_sort(std::move(input)));

	// l.splice(iterator pos,list& x)
	// 将x中所有元素移动插入到l中pos指向的位置之前
	result.splice(result.end(), new_higher);
	result.splice(result.begin(), new_lower);
	return result;
}