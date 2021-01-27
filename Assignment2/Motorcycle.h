#pragma once
#include "Motorcycle.h"
#include "Vehicle.h"
#include "IDrivable.h"
namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		~Motorcycle();
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDriveSpeed() const;
		virtual void Move();
	};
}