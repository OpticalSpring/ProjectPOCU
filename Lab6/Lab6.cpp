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
		if (v.empty() == true)
		{
			return INT32_MIN;
		}
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
		if (v.empty() == true)
		{
			return INT32_MAX;
		}
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

		for (int i = 0; i < v.size() - 1; i++) 
		{
			for (int j = i + 1; j < v.size(); j++) 
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