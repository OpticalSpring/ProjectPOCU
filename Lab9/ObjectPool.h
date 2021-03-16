#pragma once
#include<queue>
using namespace std;
namespace lab9
{
	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool<T>(size_t poolSize);
		~ObjectPool<T>();
		T* Get();
		void Return(T* t);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		size_t mMaxPoolSize;
		queue<T*> mPoolObject;
	};
	template<typename T>
	inline ObjectPool<T>::ObjectPool(size_t poolSize)
	{
		mMaxPoolSize = poolSize;
	}
	template<typename T>
	inline ObjectPool<T>::~ObjectPool()
	{
		while (mPoolObject.empty() == false)
		{
			T* r = mPoolObject.front();
			mPoolObject.pop();
			delete r;
		}
	}
	template<typename T>
	inline T* ObjectPool<T>::Get()
	{
		if (mPoolObject.empty()) {
			return new T;
		}
		auto rValue = mPoolObject.front();
		mPoolObject.pop();
		return rValue;
	}
	template<typename T>
	inline void ObjectPool<T>::Return(T* t)
	{
		if (mPoolObject.size() == mMaxPoolSize)
		{
			delete t;
			return;
		}
		mPoolObject.push(t);
	}
	template<typename T>
	inline size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mPoolObject.size();
	}
	template<typename T>
	inline size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}
}