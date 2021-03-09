#pragma once

#include <cstdint>
namespace lab8 {

	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<bool, N>& bRhs);
		FixedVector<bool, N>& operator=(const FixedVector<bool, N>& bRhs);
		~FixedVector();

		bool Add(const bool bT);
		bool Remove(const bool bT);
		bool Get(unsigned int index);
		bool operator[](unsigned int index);
		int GetIndex(bool bT);
		size_t GetSize();
		size_t GetCapacity();
	private:
		int32_t mArray[N / 32 + 1];
		size_t mSize;
	};

}
