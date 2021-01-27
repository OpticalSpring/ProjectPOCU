#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle() :Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}
	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double x = static_cast<double>(GetWeight());
		unsigned int speed = std::max((pow(-(x / 15), 3) + 2 * x + 400), 0.0);

		return speed;
	}
}