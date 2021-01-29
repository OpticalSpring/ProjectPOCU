#include "DeusExMachina.h"
#include "Vehicle.h"
#include <iostream>
using namespace std;
namespace assignment2
{
	DeusExMachina::DeusExMachina()
	{
		mSize = 0;
		for (size_t i = 0; i < 10; i++)
		{
			mVehicle[i] = nullptr;
		}
		cout << "����" << endl;
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		cout << "�ν��Ͻ��ޱ�" << endl;
		static DeusExMachina ins;
		return &ins;
	}

	DeusExMachina::~DeusExMachina()
	{
		for (size_t i = 0; i < mSize; i++)
		{
			delete mVehicle[i];
			mVehicle[i] = nullptr;
		}
		delete mVehicle;
		cout << "�Ҹ�" << endl;
	}

	void DeusExMachina::Travel() const
	{
		cout << "����" << endl;
		for (size_t i = 0; i < mSize; i++)
		{
			mVehicle[i]->Move();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mSize >= 10)
		{
			return false;
		}
		mVehicle[mSize] = vehicle;
		mSize++;
		cout << "�߰�" << endl;
		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mSize || i < 0)
		{
			return false;
		}
		delete mVehicle[i];
		for (size_t j = i; j < mSize - 1; j++)
		{
			mVehicle[j] = mVehicle[j + 1];
		}
		mSize--;
		mVehicle[mSize] = nullptr;
		cout << "����" << endl;
		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mSize == 0) 
		{
			return nullptr;
		}
		unsigned int dis = 0;
		int a = 0;
		for (size_t i = 0; i < mSize; i++)
		{
			if (mVehicle[i]->GetDistance() > dis) 
			{
				dis = mVehicle[i]->GetDistance();
				a = i;
			}
		}
		cout << "����" << endl;
		return mVehicle[a];
	}
}