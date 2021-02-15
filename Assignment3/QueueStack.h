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
	};
	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
	{
	}
	template<typename T>
	inline void QueueStack<T>::Enqueue(T number)
	{
	}
	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return T();
	}
	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		return T();
	}
	template<typename T>
	inline T QueueStack<T>::GetMax()
	{
		return T();
	}
	template<typename T>
	inline T QueueStack<T>::GetMin()
	{
		return T();
	}
	template<typename T>
	inline double QueueStack<T>::GetAverage()
	{
		return 0.0;
	}
	template<typename T>
	inline T QueueStack<T>::GetSum()
	{
		return T();
	}
	template<typename T>
	inline unsigned int QueueStack<T>::GetCount()
	{
		return 0;
	}
	template<typename T>
	inline unsigned int QueueStack<T>::GetStackCount()
	{
		return 0;
	}
}
