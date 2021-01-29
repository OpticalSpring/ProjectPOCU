#pragma once
#include "Vehicle.h"
#include "IDrivable.h"
namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(const Sedan& other);
		Sedan& operator=(const Sedan& other);
		~Sedan();
		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDriveSpeed() const;
		virtual void Move();
		const Trailer* GetTrailer() const;
	private:
		const Trailer* mTrailer;
	};
}