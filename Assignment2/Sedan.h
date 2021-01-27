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
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDriveSpeed() const;
	private:
		const Trailer* mTrailer;
	};
}