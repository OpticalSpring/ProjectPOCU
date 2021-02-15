#pragma once
namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
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

	};
}
