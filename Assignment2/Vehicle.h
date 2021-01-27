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
		Vehicle(const Vehicle* other);
		~Vehicle();
		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		bool ReplacePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		Vehicle& operator=(const Vehicle& other);
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetWeight() const;
		unsigned int GetDistance() const;
		unsigned int GetCount() const;
		virtual void Move() = 0;
	protected:
		unsigned int mMaxPassengersCount;
		const Person* mPassengers[100];
		unsigned int mSize;
		unsigned int mWeight;
		unsigned int mDistance;
		unsigned int mCount;
	};
}