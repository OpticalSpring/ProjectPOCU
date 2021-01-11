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

		while (true)
		{
			in >> number;
			if (in.eof())
			{
				break;
			}

			if (in.fail())
			{
				//out << "Invalid input" << endl;
				in.clear();
				in.ignore(LLONG_MAX, ' ');
				continue;
			}
			v.push_back(number);
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

		while (true)
		{
			in >> number;
			if (in.eof())
			{
				break;
			}

			if (in.fail())
			{
				//out << "Invalid input" << endl;
				in.clear();
				in.ignore(LLONG_MAX, ' ');
				continue;
			}
			v.push_back(number);
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