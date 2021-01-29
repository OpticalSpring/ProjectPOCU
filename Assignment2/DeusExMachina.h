#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private:
		DeusExMachina();
		DeusExMachina(const DeusExMachina& ref);
		DeusExMachina& operator=(const DeusExMachina& ref);
		~DeusExMachina();
		Vehicle* mVehicle[10];
		unsigned int mSize;
	};
}