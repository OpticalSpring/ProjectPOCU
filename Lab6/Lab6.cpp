#include "Lab6.h"
#include <unordered_map>

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;
		for (auto it = v.begin(); it != v.end(); it++)
		{
			sum += *it;
		}
		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		
		int min = INT32_MAX;
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (min > *it)
			{
				min = *it;
			}
		}
		return min;
	}

	int Max(const std::vector<int>& v)
	{
		
		int max = INT32_MIN;
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (max < *it)
			{
				max = *it;
			}
		}
		return max;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.empty() == true)
		{
			return 0;
		}
		float ave = Sum(v) / static_cast<float>(v.size());
		return ave;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.empty() == true)
		{
			return 0;
		}
		std::unordered_map<int, int> cmap;
		cmap.reserve(v.size());
		for (auto it = v.begin(); it != v.end(); it++)
		{
			cmap[*it]++;
		}
		int c = 0;
		auto cit = cmap.begin();
		for (auto it = cmap.begin(); it != cmap.end(); it++)
		{
			if (c < it->second)
			{
				c = it->second;
				cit = it;
			}
		}

		return cit->first;
	}

	void SortDescending(std::vector<int>& v)
	{
		if (v.empty() == true)
		{
			return;
		}
		for (size_t i = 0; i < v.size() - 1; i++) 
		{
			for (size_t j = i + 1; j < v.size(); j++)
			{
				if (v[i] < v[j]) 
				{
					int temp = v[j];
					v[j] = v[i];
					v[i] = temp;
				}
			}
		}
	}

}