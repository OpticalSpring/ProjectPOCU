#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Person.h"
namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		~Vehicle();
		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetWeight() const;
	protected:
		unsigned int mMaxPassengersCount;
		const Person* mPassengers[100];
		unsigned int mSize;
		unsigned int mWeight;
		unsigned int mDistance;
	};
}