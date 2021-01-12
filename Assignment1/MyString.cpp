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
		return MyString("temporary");
	}

	int MyString::IndexOf(const char* s)
	{
		return 0;
	}

	int MyString::LastIndexOf(const char* s)
	{
		return 0;
	}

	void MyString::Interleave(const char* s)
	{
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
	}

	void MyString::ToUpper()
	{
	}
}