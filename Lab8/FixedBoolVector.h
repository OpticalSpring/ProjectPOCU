#pragma once

#include <cstdint>
namespace lab8 
{

	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<bool, N>& brhs);
		FixedVector<bool, N>& operator=(const FixedVector<bool, N>& brhs);
		~FixedVector();

		bool Add(const bool bt);
		bool Remove(const bool bt);
		bool Get(size_t index);
		bool operator[](size_t index);
		int GetIndex(bool bt);
		size_t GetSize();
		size_t GetCapacity();
	private:
		int32_t mArray[N / 32 + 1];
		size_t mSize;
	};

	template<size_t N>
	inline FixedVector<bool, N>::FixedVector()
	{
		mSize = 0;
	}

	template<size_t N>
	inline FixedVector<bool, N>::FixedVector(const FixedVector<bool, N>& brhs)
	{
		mSize = brhs.mSize;
		mArray = brhs.mArray;
	}

	template<size_t N>
	inline FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector<bool, N>& brhs)
	{
		mSize = brhs.mSize;
		mArray = brhs.mArray;
		return *this;
	}

	template<size_t N>
	inline FixedVector<bool, N>::~FixedVector<bool, N>()
	{

	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Add(const bool bt)
	{
		if (mSize >= N)
		{
			return false;
		}

		size_t index = mSize / 32;

		if (bt)
		{
			mArray[index] |= (1 << mSize++);
		}
		else
		{
			mArray[index] &= ~(1 << mSize++);
		}

		return true;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(const bool bt)
	{
		if (GetIndex(bt) == -1)
		{
			return false;
		}
		if (mSize == 0)
		{
			return false;
		}
		for (size_t i = GetIndex(bt); i < mSize - 1; i++)
		{
			int32_t tmp = mArray[(i + 1) / 32] & (1 << (i + 1) % 32);
			tmp >>= ((i + 1) % 32);
			mArray[i / 32] &= ~(1 << i % 32);
			mArray[i / 32] |= (tmp << i);
		}
		mSize--;
		return true;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Get(size_t index)
	{
		return static_cast<bool>(mArray[index / 32] & (1 << (index % 32)));
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::operator[](size_t index)
	{
		return static_cast<bool>(mArray[index / 32] & (1 << (index % 32)));
	}

	template<size_t N>
	inline int FixedVector<bool, N>::GetIndex(bool bt)
	{
		if (bt == true)
		{
			for (unsigned int i = 0; i < mSize; i++)
			{
				if (mArray[i / 32] & (1 << (i % 32)))
				{
					return static_cast<int>(i);
				}
			}
		}
		else
		{
			for (unsigned int i = 0; i < mSize; i++)
			{
				if ((~mArray[i / 32]) & (1 << (i % 32)))
				{
					return static_cast<int>(i);
				}
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
