#include <cassert>
#include <iostream>
#include "SmartStack.h"
using namespace assignment3;

int main()
{
    SmartStack<double> ss;

    ss.Push(3.4);
    ss.Push(1.2);
    ss.Push(4.6);
    ss.Push(3.32);
    ss.Push(10.2);
    ss.Push(1.1);
    ss.Push(-5.9);
    ss.Push(1.1);
    ss.Push(-12.4);
    ss.Push(9.2);

    assert(ss.GetCount() == 10U);
    assert(ss.Peek() == 9.2);
    assert(ss.GetMax() == 10.2);
    assert(ss.GetMin() == -12.4);
    std::cout << ss.GetSum() << std::endl;
    assert(ss.GetSum() == 15.82);
    assert(ss.GetAverage() == 1.582);
    assert(ss.GetVariance() == 39.983);
    assert(ss.GetStandardDeviation() == 6.323);
    assert(ss.Peek() == 9.2);

    double popped1 = ss.Pop();
    double popped2 = ss.Pop();

    assert(popped1 == 9.2);
    assert(popped2 == -12.4);

    return 0;
}
