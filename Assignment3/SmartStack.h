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
		T mMin;
		T mMax;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
	{
		mMin = std::numeric_limits<T>::max();
		mMax = std::numeric_limits<T>::lowest();
	}




	template<typename T>
	inline void SmartStack<T>::Push(T number)
	{
		mStack.push(number);
		if (mMax < number)
		{
			mMax = number;
		}
		if (mMin > number)
		{
			mMin = number;
		}
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		T r = mStack.top();
		mStack.pop();

		if (r == mMax) 
		{
			mMax = std::numeric_limits<T>::lowest();
			std::stack<T> nStack = mStack;
			for (size_t i = 0; i < mStack.size(); i++)
			{
				if (mMax < nStack.top())
				{
					mMax = nStack.top();
				}
				nStack.pop();
			}
		}
		if (r == mMin)
		{
			mMin = std::numeric_limits<T>::lowest();
			std::stack<T> nStack = mStack;
			for (size_t i = 0; i < mStack.size(); i++)
			{
				if (mMin > nStack.top())
				{
					mMin = nStack.top();
				}
				nStack.pop();
			}
		}
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


		return mMax;
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		if (mStack.empty() == true)
		{
			return std::numeric_limits<T>::max();
		}
		

		return mMin;
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		double ave = static_cast<double>(0);
		std::stack<T> nStack = mStack;
		for (size_t i = 0; i < mStack.size(); i++)
		{
			ave += static_cast<double>(nStack.top());
			nStack.pop();
		}
		return ave / static_cast<double>(mStack.size());
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		T sum = static_cast<T>(0);
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
		double sum = static_cast<double>(0);
		double average = GetAverage();
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