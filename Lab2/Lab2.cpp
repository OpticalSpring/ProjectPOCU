#include "Lab2.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out) 
	{
		vector<int> v;
		int number;
		string trash;

		while (true)
		{
			in >> number;
			if (!in.fail())
			{
				v.push_back(number);
				continue;
			}

			if (in.eof())
			{
				break;
			}
			in.clear();
			in >> trash;
		}
		in.clear();


		out << "         oct        dec      hex" << endl;
		out << "------------ ---------- --------" << endl;
		for (size_t i = 0; i < v.size(); i++)
		{
			out << uppercase << setfill(' ') << setw(12) << oct << v[i];
			out << setw(11) << dec << v[i];
			out << setw(9) << hex << v[i] << endl;
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out) 
	{
		vector<float> v;
		float number;
		string trash;

		while (true)
		{
			in >> number;
			if (!in.fail())
			{
				v.push_back(number);
				continue;
			}

			if (in.eof())
			{
				break;
			}
			in.clear();
			in >> trash;
		}
		in.clear();


		for (size_t i = 0; i < v.size(); i++)
		{
			out << showpos << showpoint << fixed;
			out.precision(3);
			out << "     " << setw(14) << internal << v[i] << endl;
		}
		sort(v.begin(), v.end());
		out << "max: " << setw(14) << internal << v.back() << endl;
	}
}