#include "MyString.h"
#include <iostream>
using namespace std;

using namespace assignment1;

int main()
{
	MyString s("Hello");
	s = s;
	MyString s2(s);
	cout << s2.GetCString();
}