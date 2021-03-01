#include <cassert>

#include "Lab7.h"

using namespace lab7;

int main()
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	std::vector<char> v2;
	v2.push_back('a');
	v2.push_back('b');
	v2.push_back('c');

	std::vector<int> v3;
	v3.push_back(3);
	v3.push_back(2);
	v3.push_back(4);

	std::map<char, int> m1;
	m1['a'] = 1;
	m1['b'] = 2;
	m1['c'] = 3;

	std::map<char, int> m2;
	m2['d'] = 4;
	m2['e'] = 5;
	m2['f'] = 6;

	

	std::vector<int> combinedVector = v1 + v3;
	

	
	std::cout << combinedVector << std::endl;
	std::cout << m1 << std::endl;
	

	return 0;
}