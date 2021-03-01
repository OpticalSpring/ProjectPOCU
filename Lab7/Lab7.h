#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		if (keys.size() < values.size()) {
			for (size_t i = 0; i < keys.size(); i++)
			{
				m.insert(std::pair<K, V>(keys[i], values[i]));
			}
		}
		else {
			for (size_t i = 0; i < values.size(); i++)
			{
				m.insert(std::pair<K, V>(keys[i], values[i]));
			}
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		for (auto i = m.begin(); i != m.end(); i++)
		{
			v.push_back(i->first);
		}
		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		for (auto i = m.begin(); i != m.end(); i++)
		{
			v.push_back(i->second);
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		for (size_t i = v.size(); i > 0; --i)
		{
			rv.push_back(v[i - 1]);
		}


		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		for (size_t i = 0; i < v1.size(); i++)
		{
			combined.push_back(v1[i]);
		}
		for (size_t j = 0; j < v2.size(); j++)
		{
			bool c = false;
			for (size_t i = 0; i < v1.size(); i++)
			{
				if (v1[i] == v2[j])
				{
					c = true;
				}
			}
			if (c == false)
			{
				combined.push_back(v2[j]);
			}
		}
		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		for (auto i = m1.begin(); i != m1.end(); i++)
		{
			combined.insert(std::pair<K, V>(i->first, i->second));
		}

		for (auto i = m2.begin(); i != m2.end(); i++)
		{
			combined.insert(std::pair<K, V>(i->first, i->second));
		}


		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		return os;
	}
}