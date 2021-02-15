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
		T mSum;
		double mSquaredSum;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
	{
		mMin = std::numeric_limits<T>::max();
		mMax = std::numeric_limits<T>::lowest();
		mSum = static_cast<T>(0);
		mSquaredSum = 0.0;
	}




	template<typename T>
	inline void SmartStack<T>::Push(T number)
	{
		mStack.push(number);
		mSum += number;
		mSquaredSum += number * number;
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
		if (mStack.empty() == true)
		{
			return static_cast<T>(0);
		}
		T r = mStack.top();
		mStack.pop();
		mSum -= r;
		mSquaredSum -= r * r;
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
			mMin = std::numeric_limits<T>::max();
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
		if (mStack.empty() == true)
		{
			mMin = std::numeric_limits<T>::max();
			mMax = std::numeric_limits<T>::lowest();
			mSum = static_cast<T>(0);
			mSquaredSum = 0.0;
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
		return mMax;
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		return mMin;
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		return mSum / static_cast<double>(mStack.size());
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		double squaredMean = GetAverage() * GetAverage();

		double variance = mSquaredSum / mStack.size() - squaredMean;
		return variance;
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		double standardDeviation = sqrtf(static_cast<float>(GetVariance()));
		return standardDeviation;
	}

	template<typename T>
	inline unsigned int SmartStack<T>::GetCount()
	{
		return mStack.size();
	}


}