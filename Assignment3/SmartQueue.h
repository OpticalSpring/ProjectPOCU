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
	};
	template<typename T>
	inline SmartQueue<T>::SmartQueue()
	{
		mMin = std::numeric_limits<T>::max();
		mMax = std::numeric_limits<T>::lowest();
	}
	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
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
			return 0;
		}
		T r = mQueue.front();
		mQueue.pop();

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

		return r;
	}
	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		if (mQueue.empty() == true)
		{
			return std::numeric_limits<T>::lowest();
		}


		return mMax;
	}
	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		if (mQueue.empty() == true)
		{
			return std::numeric_limits<T>::max();
		}


		return mMin;
	}
	template<typename T>
	inline double SmartQueue<T>::GetAverage()
	{
		double ave = 0;
		std::queue<T> nQueue = mQueue;
		for (size_t i = 0; i < mQueue.size(); i++)
		{
			ave += mQueue.front();
			mQueue.pop();
		}
		return ave / mQueue.size();
	}
	template<typename T>
	inline T SmartQueue<T>::GetSum()
	{
		T sum = 0;
		std::queue<T> nQueue = mQueue;
		for (size_t i = 0; i < mQueue.size(); i++)
		{
			sum += mQueue.front();
			mQueue.pop();
		}
		return sum;
	}
	template<typename T>
	inline double SmartQueue<T>::GetVariance()
	{
		double sum = static_cast<double>(0);
		double average = GetAverage();
		std::queue<T> nQueue = mQueue;
		for (size_t i = 0; i < mQueue.size(); i++)
		{
			sum += (nQueue.front() - average) * (nQueue.front() - average);
			nQueue.pop();
		}
		double variance = sum / mQueue.size();
		return variance;
	}
	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		double standardDeviation = sqrtf(static_cast<float> (GetVariance()));
		return standardDeviation;
	}
	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue.size();
	}
}
