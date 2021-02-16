#include <cassert>
#include <cmath>

#include "QueueStack.h"

using namespace assignment3;

int main()
{
	const double EPSILON = 0.0009765625;

	QueueStack<float> ss(3);

	ss.Enqueue(3.4999f);
	ss.Enqueue(1.2f);
	ss.Enqueue(4.6555f);
	ss.Enqueue(3.3299f);
	ss.Enqueue(10.2f);
	ss.Enqueue(1.1f);
	ss.Enqueue(-5.9f);
	ss.Enqueue(1.1f);
	ss.Enqueue(-12.4f);
	ss.Enqueue(9.2f);

	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 4.6555f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -12.4f);
	assert(std::abs(ss.GetSum() - 15.985301f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 1.599) <= EPSILON);
	assert(ss.Peek() == 4.6555f);

	float popped1 = ss.Dequeue();
	float popped2 = ss.Dequeue();

	assert(popped1 == 4.6555f);
	assert(popped2 == 1.2f);
	assert(ss.GetCount() == 8U);
	assert(ss.Peek() == 3.4999f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -12.4f);
	assert(std::abs(ss.GetSum() - 10.129801f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 1.266225125) <= EPSILON);

	return 0;
}