#pragma once

namespace lab8 {

	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<T, N>& rhs);
		FixedVector<T, N>& operator=(const FixedVector<T, N>& rhs);
		~FixedVector();

		bool Add(const T& t);
		bool Remove(const T& t);
		const T& Get(size_t index);
		T& operator[](size_t index);
		int GetIndex(const T& t);
		size_t GetSize();
		size_t GetCapacity();
	private:
		T mArray[N];
		size_t mSize;
	};

	template<typename T, size_t N>
	inline FixedVector<T, N>::FixedVector()
	{
		mSize = 0;
	}

	template<typename T, size_t N>
	inline FixedVector<T, N>::FixedVector(const FixedVector<T, N>& rhs)
	{
		mSize = rhs.mSize;
		mArray = rhs.mArray;
	}

	template<typename T, size_t N>
	inline FixedVector<T, N>& FixedVector<T, N>::operator=(const FixedVector<T, N>& rhs)
	{
		FixedVector<T, N> newVector;
		newVector.mSize = rhs.mSize;
		newVector.mArray = rhs.mArray;
		return newVector;
	}

	template<typename T, size_t N>
	inline FixedVector<T, N>::~FixedVector()
	{
	}


	template<typename T, size_t N>
	inline bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize >= N)
		{
			return false;
		}

		mArray[mSize] = t;
		mSize++;
		return true;
	}

	template<typename T, size_t N>
	inline bool FixedVector<T, N>::Remove(const T& t)
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

	template<typename T, size_t N>
	inline const T& FixedVector<T, N>::Get(size_t index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	inline T& FixedVector<T, N>::operator[](size_t index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	inline int FixedVector<T, N>::GetIndex(const T& t)
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

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetSize()
	{
		return mSize;
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetCapacity()
	{
		return N;
	}

}