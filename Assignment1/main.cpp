#include "MyString.h"
#include <iostream>
using namespace std;

using namespace assignment1;

int main()
{
	MyString s("Hello Hello World ");
	cout << s.IndexOf("Hello") << endl << s.LastIndexOf("Hello");
}