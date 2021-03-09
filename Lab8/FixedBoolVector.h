#pragma once

#include <cstdint>
namespace lab8 {

	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<bool, N>& rhs);
		FixedVector<bool, N>& operator=(const FixedVector<bool, N>& rhs);
		~FixedVector();

		bool Add(const bool t);
		bool Remove(const bool t);
		bool Get(unsigned int index);
		bool operator[](unsigned int index);
		int GetIndex(bool t);
		size_t GetSize();
		size_t GetCapacity();
	private:
		int32_t mArray[N];
		size_t mSize;
	};

	template<size_t N>
	inline FixedVector<bool, N>::FixedVector()
	{
		mSize = 0;
	}

	template<size_t N>
	inline FixedVector<bool, N>::FixedVector(const FixedVector<bool, N>& rhs)
	{
		mSize = rhs.mSize;
		mArray = rhs.mArray;
	}

	template<size_t N>
	inline FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector<bool, N>& rhs)
	{
		FixedVector<bool, N> newVector;
		newVector.mSize = rhs.mSize;
		newVector.mArray = rhs.mArray;
		return newVector;
	}

	template<size_t N>
	inline FixedVector<bool, N>::~FixedVector<bool, N>()
	{

	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Add(const bool t)
	{
		if (mSize >= N)
		{
			return false;
		}

		mArray[mSize] = t;
		mSize++;
		return true;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(const bool t)
	{
		if (GetIndex(t) == -1)
		{
			return false;
		}
		for (size_t i = GetIndex(t); i < mSize - 1; i++)
		{
			mArray[i] = mArray[i + 1];
		}
		mSize--;
		return true;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Get(unsigned int index)
	{
		return mArray[index];
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return mArray[index];
	}

	template<size_t N>
	inline int FixedVector<bool, N>::GetIndex(bool t)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (t == mArray[i])
			{
				return i;
			}
		}
		return -1;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetSize()
	{
		return mSize;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}
}
