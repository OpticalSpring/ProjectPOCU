#include "Lab2.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
		vector<int> v;


		int number;
		int sum = 0;

		while (true)
		{
			cin >> number;
			if (cin.eof())
			{
				break;
			}

			if (cin.fail())
			{
				cout << "Invalid input" << endl;
				cin.clear();
				cin.ignore(LLONG_MAX, ' ');
				continue;
			}
			v.push_back(number);
		}
		cin.clear();

		
		out << "         oct        dec      hex" << endl;
		out << "------------ ---------- --------" << endl;
		for (size_t i = 0; i < v.size(); i++)
		{
			out <<uppercase <<setfill(' ') << setw(12) <<oct << v[i] ;
			out << setw(11) << dec << v[i];
			out << setw(9) << hex << v[i] << endl;
		}
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {

    }
}