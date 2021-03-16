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
		T* Get();
		void Return(T* t);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		size_t maxPoolSize;
		queue<T*> poolObject;
	};
	template<typename T>
	inline ObjectPool<T>::ObjectPool(size_t poolSize)
	{
		maxPoolSize = poolSize;
	}
	template<typename T>
	inline T* ObjectPool<T>::Get()
	{
		if (poolObject.empty()) {
			return new T;
		}
		auto rValue = poolObject.front();
		poolObject.pop();
		return rValue;
	}
	template<typename T>
	inline void ObjectPool<T>::Return(T* t)
	{
		if (poolObject.size() == maxPoolSize) 
		{
			delete t;
			return;
		}
		poolObject.push(t);
	}
	template<typename T>
	inline size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return poolObject.size();
	}
	template<typename T>
	inline size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return maxPoolSize;
	}
}