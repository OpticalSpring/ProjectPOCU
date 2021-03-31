#pragma once

#include <memory>


using namespace std;
namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(Storage<T>&& rhs);
		Storage<T>& operator=(Storage<T>&& rhs);
		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
	private: 
		std::unique_ptr<T[]> mData;
		unsigned int mSize;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
	{
		mData = make_unique<T[]>(length);
		mSize = length;
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
	{
		mData = make_unique<T[]>(length);
		mSize = length;
		for (size_t i = 0; i < mSize; i++)
		{
			mData[i] = initialValue;
		}
	}

	template<typename T>
	inline Storage<T>::Storage(Storage<T>&& rhs)
	{
		mData = move(rhs.mData);
		mSize = rhs.mSize;
		rhs.mSize = 0;
		rhs.mData = nullptr;
	}

	template<typename T>
	inline Storage<T>& Storage<T>::operator=(Storage<T>&& rhs)
	{
		if (rhs == this) return this;
		mData = move(rhs.mData);
		mSize = rhs.mSize;
		rhs.mSize = 0;
		rhs.mData = nullptr;
		return this;
	}


	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index < mSize) 
		{
			mData[index] = data;
			return true;
		}
		return false;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		
		return std::move(mData);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mSize;
	}
}