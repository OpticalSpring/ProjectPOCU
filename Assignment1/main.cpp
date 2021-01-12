#include "MyString.h"
#include <iostream>
using namespace std;

using namespace assignment1;

int main()
{
	MyString s("Hello");
	s.PadRight(3, 'a');
	cout << s.GetCString();
}