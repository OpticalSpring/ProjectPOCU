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
		
		T mSum;
		double mSquaredSum;
	};
	template<typename T>
	inline SmartQueue<T>::SmartQueue()
	{
		
		mSum = static_cast<T>(0);
		mSquaredSum = 0.0;
	}
	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
		mSum += number;
		mSquaredSum += number * number;
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
		
		if (mQueue.empty() == true)
		{
			mSum = static_cast<T>(0);
			mSquaredSum = 0.0;
		}
		return r;
	}
	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		std::queue<T> nQueue = mQueue;
		for (size_t i = 0; i < mQueue.size(); i++)
		{
			if (min > nQueue.front()) 
			{
				min = nQueue.front();
			}
			nQueue.pop();
		}
		return min;
	}
	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();
		std::queue<T> nQueue = mQueue;
		for (size_t i = 0; i < mQueue.size(); i++)
		{
			if (max < nQueue.front())
			{
				max = nQueue.front();
			}
			nQueue.pop();
		}
		return max;
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
