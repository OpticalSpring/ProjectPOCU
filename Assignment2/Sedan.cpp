#include "Sedan.h"
#include "Trailer.h"
#include <iostream>
using namespace std;
namespace assignment2
{
	Sedan::Sedan() : Vehicle(4)
	{
		mTrailer = nullptr;
		cout << "SedanNew" << endl;
	}

	Sedan::Sedan(const Sedan& other) : Vehicle(other)
	{
		if (other.GetTrailer() != nullptr) 
		{
			mTrailer = new Trailer(other.GetTrailer()->GetWeight());
		}
		cout << "SedanCopy" << endl;
	}

	Sedan& Sedan::operator=(const Sedan& other)
	{
		if (&other == this)
		{
			cout << "ME" << endl;
			return *this;
		}
		Vehicle::operator=(other);
		RemoveTrailer();
		if (other.GetTrailer() != nullptr)
		{
			mTrailer = new Trailer(other.GetTrailer()->GetWeight());
		}
		cout << "Sedan=" << endl;
		return *this;
	}

	Sedan::~Sedan()
	{
		cout << "SedanDelete" << endl;
		if (mTrailer != nullptr) 
		{
			delete mTrailer;
			mTrailer = nullptr;
		}
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailer == nullptr)
		{
			cout << "SedanAddTrailer" << endl;
			mTrailer = trailer;
			return true;
		}
		return false;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == nullptr)
		{
			return false;
		}
		cout << "SedanRemoveTrailer" << endl;
		delete mTrailer;
		return true;
	}
	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
	unsigned int Sedan::GetDriveSpeed() const
	{
		double x = static_cast<double>(GetWeight());
		if (mTrailer == nullptr)
		{
		}
		else 
		{
			x += static_cast<double>(mTrailer->GetWeight());
		}
		unsigned int speed = 0;
		if (x > 350)
		{
			speed = 300;
		}
		else if (x > 260)
		{
			speed = 380;
		}
		else if (x > 160)
		{
			speed = 400;
		}
		else if (x > 80)
		{
			speed = 458;
		}
		else
		{
			speed = 480;
		}

		return speed;
	}
	void Sedan::Move()
	{
		if (mTrailer == nullptr)
		{
			switch (mCount % 6) 
			{
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
		}
		else
		{
			switch (mCount % 7) 
			{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
				mDistance += GetMaxSpeed();
				break;
			case 5:
			case 6:
				break;
			}
		}

		mCount++;
	}

	const Trailer* Sedan::GetTrailer() const
	{
		return mTrailer;
	}

	
}