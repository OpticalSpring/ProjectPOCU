#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle() : Vehicle(2)
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
		double speed = std::max((pow(-(x / 15), 3) + 2 * x + 400), 0.0);

		return static_cast<unsigned int>(speed + 0.5);
	}
	void Motorcycle::Move()
	{
		switch (mCount % 6) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			mDistance += GetMaxSpeed();
			break;
		case 5:
			break;
		}
		mCount++;
	}
}