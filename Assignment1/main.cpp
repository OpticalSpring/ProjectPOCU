#include "MyString.h"
#include <iostream>
using namespace std;

using namespace assignment1;

int main()
{
	MyString s("hello");
	MyString s2("helloello");

	s.Append("ello");
	bool b = (s == s2);

	cout << boolalpha <<b << endl;

	// ���⿡ �ߴ����� �����ؼ� b ���� ���캸�ų�
	// �Ʒ��� ���� assert() �Լ��� �Ẹ����
	// assert(s == s2);	// #include <cassert>�� �ʿ�
}