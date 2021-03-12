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
		bool Get(size_t index);
		bool operator[](size_t index);
		int GetIndex(bool t);
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
	inline FixedVector<bool, N>::FixedVector(const FixedVector<bool, N>& rhs)
	{
		mSize = rhs.mSize;
		mArray = rhs.mArray;
	}

	template<size_t N>
	inline FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector<bool, N>& rhs)
	{
		mSize = rhs.mSize;
		mArray = rhs.mArray;
		return *this;
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

		size_t index = mSize / 32;

		if (t)
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
	inline bool FixedVector<bool, N>::Remove(const bool t)
	{
		if (GetIndex(t) == -1)
		{
			return false;
		}
		if (mSize == 0)
		{
			return false;
		}
		for (size_t i = GetIndex(t); i < mSize - 1; i++)
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
	inline int FixedVector<bool, N>::GetIndex(bool t)
	{
		if (t == true)
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
