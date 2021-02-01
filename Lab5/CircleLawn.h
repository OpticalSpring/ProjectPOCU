#pragma once
#include "Lawn.h"
namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned int input);
		virtual ~CircleLawn();

		virtual unsigned int GetArea() const;
	private:
		unsigned int mInput;
	};

}