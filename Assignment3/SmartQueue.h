#pragma once
#include <queue>
#include <limits>
namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();
	private:
		std::queue<T> mQueue;
		T mMin;
		T mMax;
		T mSum;
		double mSquaredSum;
	};
	template<typename T>
	inline SmartQueue<T>::SmartQueue()
	{
		mMin = std::numeric_limits<T>::max();
		mMax = std::numeric_limits<T>::lowest();
		mSum = static_cast<T>(0);
		mSquaredSum = 0.0;
	}
	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
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
	inline T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}
	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		if (mQueue.empty() == true)
		{
			return static_cast<T>(0);
		}
		T r = mQueue.front();
		mQueue.pop();
		mSum -= r;
		mSquaredSum -= r * r;
		if (r == mMax)
		{
			mMax = std::numeric_limits<T>::lowest();
			std::queue<T> nQueue = mQueue;
			for (size_t i = 0; i < mQueue.size(); i++)
			{
				if (mMax < nQueue.front())
				{
					mMax = nQueue.front();
				}
				nQueue.pop();
			}
		}
		if (r == mMin)
		{
			mMin = std::numeric_limits<T>::max();
			std::queue<T> nQueue = mQueue;
			for (size_t i = 0; i < mQueue.size(); i++)
			{
				if (mMin > nQueue.front())
				{
					mMin = nQueue.front();
				}
				nQueue.pop();
			}
		}
		if (mQueue.empty() == true)
		{
			mMin = std::numeric_limits<T>::max();
			mMax = std::numeric_limits<T>::lowest();
			mSum = static_cast<T>(0);
			mSquaredSum = 0.0;
		}
		return r;
	}
	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		return mMax;
	}
	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		return mMin;
	}
	template<typename T>
	inline double SmartQueue<T>::GetAverage()
	{
		return mSum / static_cast<double>(mQueue.size());
	}
	template<typename T>
	inline T SmartQueue<T>::GetSum()
	{
		return mSum;
	}
	template<typename T>
	inline double SmartQueue<T>::GetVariance()
	{
		double squaredMean = GetAverage() * GetAverage();

		double variance = mSquaredSum / mQueue.size() - squaredMean;
		return variance;
	}
	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		double standardDeviation = sqrtf(static_cast<float>(GetVariance()));
		return standardDeviation;
	}
	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue.size();
	}
}
