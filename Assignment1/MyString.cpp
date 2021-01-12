#include "MyString.h"
#include "String.h"

using namespace std;

namespace assignment1
{
	MyString::MyString(const char* s) : mSize(strlen(s) + 1)
	{
		mString = new char[mSize];
		memcpy(mString, s, mSize);
	}

	MyString::MyString(const MyString& other) : mSize(other.mSize)
	{
		mString = new char[mSize];
		memcpy(mString, other.mString, mSize);
	}

	MyString::~MyString()
	{

		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		return mSize;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		mSize += strlen(s);
		char* ns = new char[mSize];
		strcpy(ns, mString);

		delete[] mString;
		strcat(ns, s);
		mString = ns;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		int nSize = mSize + other.GetLength() - 1;
		char* ns = new char[nSize];
		strcpy(ns, mString);
		strcat(ns, other.GetCString());
		return MyString(ns);
	}

	int MyString::IndexOf(const char* s)
	{
		if (strstr(mString, s) != nullptr) {
			int index = (int)(strstr(mString, s) - mString);
		}
		else {
			return -1;
		}
	}

	int MyString::LastIndexOf(const char* s)
	{ 
		return 0;
	}

	void MyString::Interleave(const char* s)
	{
		int nSize = mSize + strlen(s);
		char* ns = new char[nSize];
		int a = 0;
		int n1 = 0;
		int n2 = 0;
		while (true) {
			if (n1 < mSize-1) {
				ns[a] = mString[n1];
				n1++;
				a++;
			}
			if (n2 < strlen(s)) {
				ns[a] = s[n2];
				n2++;
				a++;
			}
			if (a >= nSize-1) {
				ns[a] = s[n2];
				break;
			}
		}
		mString = ns;
		mSize = nSize;
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		return false;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
	}

	void MyString::PadRight(unsigned int totalLength)
	{
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
	}

	void MyString::Reverse()
	{
		for (size_t i = 0; i < mSize/2; i++)
		{
			char temp = mString[i];
			mString[i] = mString[mSize - i - 2];
			mString[mSize - i - 2] = temp;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (strcmp(mString, rhs.GetCString()) == false) {
			return true;
		}
		else {

			return false;
		}
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		mSize = rhs.GetLength();

		return *this;
	}

	void MyString::ToLower()
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (mString[i] >= 'A' && mString[i] <= 'Z') {
				mString[i] += 32;
			}
		}
	}

	void MyString::ToUpper()
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (mString[i] >= 'a' && mString[i] <= 'z') {
				mString[i] -= 32;
			}
		}
	}
}