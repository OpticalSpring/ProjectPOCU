#include <cassert>
#include <cmath>
#include <iostream>
#include "QueueStack.h"
#include "SmartStack.h"
#include "SmartQueue.h"

using namespace assignment3;
using namespace std;
int main()
{
	QueueStack<float> qsf(3);

	qsf.Enqueue(-10.2f);
	qsf.Enqueue(10.2f);
	qsf.Enqueue(-10.2f);
	qsf.Enqueue(10.2f);
	qsf.Enqueue(-10.2f);
	qsf.Enqueue(10.2f);
	qsf.Enqueue(10.2f);
	qsf.Enqueue(10.2f);
	qsf.Enqueue(10.2f);
	qsf.Enqueue(10.2f);
	cout << "--------------------another test--------------" << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qsf.Dequeue() << endl;
	cout << "Count is : " << qsf.GetCount() << endl;
	cout << "Max is : " << qsf.GetMax() << endl;
	cout << "Min is : " << qsf.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qsf.Dequeue() << endl;
	cout << "Max is : " << qsf.GetMax() << endl;
	cout << "Min is : " << qsf.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qsf.Dequeue() << endl;
	cout << "Max is : " << qsf.GetMax() << endl;
	cout << "Min is : " << qsf.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qsf.Dequeue() << endl;
	cout << "Max is : " << qsf.GetMax() << endl;
	cout << "Min is : " << qsf.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qsf.Dequeue() << endl;
	cout << "Max is : " << qsf.GetMax() << endl;
	cout << "Min is : " << qsf.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qsf.Dequeue() << endl;
	cout << "Max is : " << qsf.GetMax() << endl;
	cout << "Min is : " << qsf.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qsf.Dequeue() << endl;
	cout << "Max is : " << qsf.GetMax() << endl;
	cout << "Min is : " << qsf.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qsf.Dequeue() << endl;
	cout << "Max is : " << qsf.GetMax() << endl;
	cout << "Min is : " << qsf.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qsf.Dequeue() << endl;
	cout << "Max is : " << qsf.GetMax() << endl;
	cout << "Min is : " << qsf.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qsf.Dequeue() << endl;
	cout << "Max is : " << qsf.GetMax() << endl;
	cout << "Min is : " << qsf.GetMin() << endl;

	QueueStack<int> ti(3);

	ti.Enqueue(3);
	ti.Enqueue(2);
	ti.Enqueue(1);
	ti.Enqueue(4);
	ti.Enqueue(5);

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << ti.Dequeue() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << ti.Dequeue() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << ti.Dequeue() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << ti.Dequeue() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << ti.Dequeue() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	QueueStack<int> qs(3);
	qs.Enqueue(1);
	qs.Enqueue(2);
	qs.Enqueue(3);
	qs.Enqueue(5);

	qs.Enqueue(5);
	qs.Enqueue(-1);
	qs.Enqueue(6);
	qs.Enqueue(7);

	qs.Enqueue(6);
	qs.Enqueue(1);
	qs.Enqueue(4);
	qs.Enqueue(0);

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << qs.Dequeue() << endl;
	cout << "Max is : " << qs.GetMax() << endl;
	cout << "Min is : " << qs.GetMin() << endl;


	/*QueueStack<int> ti(3);
	cout << "------------------------------------------" << endl;
	cout << "Count is : " << ti.GetCount() << endl;
	cout << "Sum is : " << ti.GetSum() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	ti.Enqueue(1);
	ti.Enqueue(2);
	ti.Enqueue(3);
	ti.Enqueue(4);
	ti.Enqueue(5);
	ti.Enqueue(6);
	ti.Enqueue(7);
	ti.Enqueue(8);

	cout << "------------------------------------------" << endl;
	cout << "Dequeued one is : " << ti.Dequeue() << endl;
	cout << "Count is : " << ti.GetCount() << endl;
	cout << "Sum is : " << ti.GetSum() << endl;
	cout << "StackCount is : " << ti.GetStackCount() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;


	cout << "------------------------------------------" << endl;
	cout << "Dequeued one is : " << ti.Dequeue() << endl;
	cout << "Count is : " << ti.GetCount() << endl;
	cout << "Sum is : " << ti.GetSum() << endl;
	cout << "StackCount is : " << ti.GetStackCount() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Dequeued one is : " << ti.Dequeue() << endl;
	cout << "Count is : " << ti.GetCount() << endl;
	cout << "Sum is : " << ti.GetSum() << endl;
	cout << "StackCount is : " << ti.GetStackCount() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Dequeued one is : " << ti.Dequeue() << endl;
	cout << "Count is : " << ti.GetCount() << endl;
	cout << "Sum is : " << ti.GetSum() << endl;
	cout << "StackCount is : " << ti.GetStackCount() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Dequeued one is : " << ti.Dequeue() << endl;
	cout << "Count is : " << ti.GetCount() << endl;
	cout << "Sum is : " << ti.GetSum() << endl;
	cout << "StackCount is : " << ti.GetStackCount() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Dequeued one is : " << ti.Dequeue() << endl;
	cout << "Count is : " << ti.GetCount() << endl;
	cout << "Sum is : " << ti.GetSum() << endl;
	cout << "StackCount is : " << ti.GetStackCount() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Dequeued one is : " << ti.Dequeue() << endl;
	cout << "Count is : " << ti.GetCount() << endl;
	cout << "Sum is : " << ti.GetSum() << endl;
	cout << "StackCount is : " << ti.GetStackCount() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Dequeued one is : " << ti.Dequeue() << endl;
	cout << "Count is : " << ti.GetCount() << endl;
	cout << "Sum is : " << ti.GetSum() << endl;
	cout << "StackCount is : " << ti.GetStackCount() << endl;
	cout << "Max is : " << ti.GetMax() << endl;
	cout << "Min is : " << ti.GetMin() << endl;*/

	QueueStack<int> fi(3);

	fi.Enqueue(3);

	fi = ti;

	cout << "------------------------------------------" << endl;
	cout << "Count is : " << fi.GetCount() << endl;
	cout << "Sum is : " << fi.GetSum() << endl;
	cout << "StackCount is : " << fi.GetStackCount() << endl;
	cout << "Max is : " << fi.GetMax() << endl;
	cout << "Min is : " << fi.GetMin() << endl;
	cin.get();
	return 0;
}