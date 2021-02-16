#pragma once
#include <queue>
#include <stack>
#include <limits>
namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();
	private:
		std::queue<std::stack<T>> mQueueStack;
		unsigned int mMaxStackSize;
	};
	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
	{
		mMaxStackSize = maxStackSize;
	}
	template<typename T>
	inline void QueueStack<T>::Enqueue(T number)
	{
		if (mQueueStack.empty() == true || mQueueStack.back().size() == mMaxStackSize)
		{
			std::stack<T> st;
			mQueueStack.push(st);
			mQueueStack.back().push(number);
		}
		else
		{
			mQueueStack.back().push(number);
		}
	}
	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return mQueueStack.front().top();
	}
	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		T r = mQueueStack.front().top();
		mQueueStack.front().pop();
		if (mQueueStack.front().size() == 0) 
		{
			mQueueStack.pop();
		}
		return r;
	}
	template<typename T>
	inline T QueueStack<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();
		auto nQueueStack = mQueueStack;
		for (size_t i = 0; i < mQueueStack.size(); i++)
		{
			size_t c = nQueueStack.front().size();
			for (size_t j = 0; j < c; j++)
			{
				if (max < nQueueStack.front().top()) 
				{
					max = nQueueStack.front().top();
				}
				nQueueStack.front().pop();
			}
			nQueueStack.pop();
		}
		return max;
	}
	template<typename T>
	inline T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		auto nQueueStack = mQueueStack;
		for (size_t i = 0; i < mQueueStack.size(); i++)
		{
			size_t c = nQueueStack.front().size();
			for (size_t j = 0; j < c; j++)
			{
				if (min > nQueueStack.front().top())
				{
					min = nQueueStack.front().top();
				}
				nQueueStack.front().pop();
			}
			nQueueStack.pop();
		}
		return min;
	}
	template<typename T>
	inline double QueueStack<T>::GetAverage()
	{
		double ave = static_cast<double>(GetSum()) / static_cast<double>(GetCount());
		return ave;
	}
	template<typename T>
	inline T QueueStack<T>::GetSum()
	{
		T sum = 0;
		auto nQueueStack = mQueueStack;
		for (size_t i = 0; i < mQueueStack.size(); i++)
		{
			size_t c = nQueueStack.front().size();
			for (size_t j = 0; j < c; j++)
			{
				sum += nQueueStack.front().top();
				nQueueStack.front().pop();
			}
			nQueueStack.pop();
		}
		return sum;
	}
	template<typename T>
	inline unsigned int QueueStack<T>::GetCount()
	{
		unsigned int count = 0;
		auto nQueueStack = mQueueStack;
		for (size_t i = 0; i < mQueueStack.size(); i++)
		{
			count += nQueueStack.front().size();
			nQueueStack.pop();
		}
		return count;
	}
	template<typename T>
	inline unsigned int QueueStack<T>::GetStackCount()
	{
		return mQueueStack.size();
	}
}
