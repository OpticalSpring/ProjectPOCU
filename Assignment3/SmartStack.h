#pragma once
#include <stack>
#include <limits>
namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		void Push(T number);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();
	private:
		std::stack<T> mStack;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
	{
	}




	template<typename T>
	inline void SmartStack<T>::Push(T number)
	{
		mStack.push(number);
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		T r = mStack.top();
		mStack.pop();
		return r;
	}

	template<typename T>
	inline T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMax()
	{
		if (mStack.empty() == true)
		{
			return std::numeric_limits<T>::lowest();
		}

		T max = std::numeric_limits<T>::lowest();
		std::stack<T> nStack = mStack;
		for (size_t i = 0; i < mStack.size(); i++)
		{
			if (max < nStack.top()) 
			{
				max = nStack.top();
			}
			nStack.pop();
		}

		return max;
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		if (mStack.empty() == true)
		{
			return std::numeric_limits<T>::max();
		}
		T min = std::numeric_limits<T>::max();
		std::stack<T> nStack = mStack;
		for (size_t i = 0; i < mStack.size(); i++)
		{
			if (min > nStack.top())
			{
				min = nStack.top();
			}
			nStack.pop();
		}

		return min;
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		double ave = 0;
		std::stack<T> nStack = mStack;
		for (size_t i = 0; i < mStack.size(); i++)
		{
			ave += nStack.top();
			nStack.pop();
		}
		return ave / mStack.size();
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		T sum = 0;
		std::stack<T> nStack = mStack;
		for (size_t i = 0; i < mStack.size(); i++)
		{
			sum += nStack.top();
			nStack.pop();
		}
		return sum;
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		float sum = 0.0f;
		float average = GetAverage();
		std::stack<T> nStack = mStack;
		for (size_t i = 0; i < mStack.size(); i++)
		{
			sum += (nStack.top() - average) * (nStack.top() - average);
			nStack.pop();
		}
		float variance = sum / mStack.size();
		return variance;
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		return sqrtf(GetVariance());
	}

	template<typename T>
	inline unsigned int SmartStack<T>::GetCount()
	{
		return mStack.size();
	}


}