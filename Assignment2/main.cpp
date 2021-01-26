
#include <cassert>
#include <iostream>
#include <iomanip>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "UBoat.h"
#include "Trailer.h"
#include "DeusExMachina.h"
#include "Person.h"


#define STR(name) #name

using namespace assignment2;
using namespace std;

int main()
{
	const char* MAX_SPEED_LABLE = "Max Speed: ";
	const char* CUR_P_LABLE = "Current Person: ";
	const unsigned int MAX_CAPACITY = 10;

	Vehicle* air = new Airplane(MAX_CAPACITY);

	Person* toAdd;
	const unsigned int personWeight = 10;

	for (size_t i = 0; i < MAX_CAPACITY + 10; i++)
	{
		toAdd = new Person(STR(i), i);
		if (air->AddPassenger(toAdd) == false)
		{
			delete toAdd;
		}

		cout << MAX_SPEED_LABLE << air->GetMaxSpeed() << endl
			<< CUR_P_LABLE << air->GetPassengersCount() << endl;
	}

	while (air->RemovePassenger(0))
	{
		cout << CUR_P_LABLE << air->GetPassengersCount() << endl;;
	}

	Person* overlapTest = new Person("Overlap Test", 100);
	air->AddPassenger(overlapTest);
	air->AddPassenger(overlapTest);
	assert(air->GetPassengersCount() == 1); // 빌드봇은 이런 테스트 안함

	toAdd = NULL;
	assert(air->AddPassenger(toAdd) == false); // 빌드봇은 이런 테스트 안함

	delete air;

	Airplane dockingTest1(10);
	Boat dockingTest2(10);

	for (size_t i = 0; i < 5; i++)
	{
		dockingTest1.AddPassenger(new Person(STR(i), i));
		dockingTest2.AddPassenger(new Person(STR(i), i));
	}

	const Person* comp1 = dockingTest1.GetPassenger(0);

	Boatplane bp1 = dockingTest1 + dockingTest2;
	Boatplane bp2 = dockingTest2 + dockingTest1;

	const Person* comp2 = bp1.GetPassenger(0);

	assert(comp1 == comp2); // 빌드봇은 이런 테스트 안함
	assert(dockingTest1.GetPassengersCount() == 0);
	assert(dockingTest2.GetPassengersCount() == 0);
	assert(bp1.GetPassengersCount() == 10);
	assert(bp2.GetPassengersCount() == 0);

	Boatplane copyConstuctorTest(bp1);

	for (size_t i = 0; i < bp1.GetPassengersCount(); i++)
	{
		const Person* p1 = bp1.GetPassenger(i);
		const Person* p2 = copyConstuctorTest.GetPassenger(i);
		assert(p1 != p2);
	}
	assert(bp1.GetMaxPassengersCount() == copyConstuctorTest.GetMaxPassengersCount());
	assert(bp1.GetPassengersCount() == copyConstuctorTest.GetPassengersCount());
	assert(bp1.GetMaxSpeed() == copyConstuctorTest.GetMaxSpeed());

	Sedan sedanTest;
	Trailer* t1 = new Trailer(10);
	Trailer* t2 = new Trailer(20);

	assert(sedanTest.AddTrailer(t1));
	assert(!sedanTest.AddTrailer(t1));
	assert(!sedanTest.AddTrailer(t2));
	assert(sedanTest.RemoveTrailer());
	assert(sedanTest.AddTrailer(t2));
	assert(sedanTest.RemoveTrailer());

	DeusExMachina* d = DeusExMachina::GetInstance();
	Vehicle* demAirplain = new Airplane(MAX_CAPACITY);
	Vehicle* demBoat = new Airplane(MAX_CAPACITY);
	Vehicle* demBoatplain = new Boatplane(MAX_CAPACITY);
	Vehicle* demMotorcycle = new Motorcycle();
	Vehicle* demSedan1 = new Sedan();
	Vehicle* demSedan2 = new Sedan();
	Trailer* demTrailer = new Trailer(10);
	static_cast<Sedan*>(demSedan2)->AddTrailer(demTrailer);
	Vehicle* demUBoat = new UBoat();

	d->AddVehicle(demAirplain);
	d->AddVehicle(demBoat);
	d->AddVehicle(demBoatplain);
	d->AddVehicle(demMotorcycle);
	d->AddVehicle(demSedan1);
	d->AddVehicle(demSedan2);
	d->AddVehicle(demUBoat);

	/*for (size_t i = 0; i < 7; i++)
	{
		Vehicle* tempVPointer = d->GetVehicle(i);
		for (size_t j = tempVPointer->GetPassengersCount(); j < tempVPointer->GetMaxPassengersCount(); j++)
		{
			tempVPointer->AddPassenger(new Person(STR((i + j)), 10));
		}
	}

	for (size_t i = 0; i < 10; i++)
	{
		d->Travel();
	}*/

	delete d;
}
