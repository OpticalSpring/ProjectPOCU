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
	};
	template<typename T>
	inline SmartQueue<T>::SmartQueue()
	{
	}
	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
	}
	template<typename T>
	inline T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}
	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		T r = mQueue.front();
		mQueue.pop();
		return r;
	}
	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		if (mQueue.empty() == true)
		{
			return std::numeric_limits<T>::lowest();
		}

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
	inline T SmartQueue<T>::GetMin()
	{
		if (mQueue.empty() == true)
		{
			return std::numeric_limits<T>::max();
		}

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
		float sum = 0.0f;
		float average = GetAverage();
		std::queue<T> nQueue = mQueue;
		for (size_t i = 0; i < mQueue.size(); i++)
		{
			sum += (nQueue.front() - average) * (nQueue.front() - average);
			nQueue.pop();
		}
		float variance = sum / mQueue.size();
		return variance;
	}
	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		return sqrtf(GetVariance());
	}
	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue.size();
	}
}
