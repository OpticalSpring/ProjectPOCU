#include "MyString.h"
#include <iostream>
using namespace std;

using namespace assignment1;

int main()
{
	MyString s1("Hello");
	s1.Interleave(" World"); // s1�� "H eWlolrold"

	cout << s1.GetCString() << endl;
	// ���⿡ �ߴ����� �����ؼ� b ���� ���캸�ų�
	// �Ʒ��� ���� assert() �Լ��� �Ẹ����
	// assert(s == s2);	// #include <cassert>�� �ʿ�
}