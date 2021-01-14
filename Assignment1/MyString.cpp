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

	MyString::MyString(const MyString& other) : mSize(other.GetLength() + 1)
	{
		mString = new char[mSize];
		memcpy(mString, other.GetCString(), mSize);

	}

	MyString::~MyString()
	{

		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		return mSize - 1;
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
		unsigned int nSize = mSize + other.GetLength();
		char* ns = new char[nSize];
		strcpy(ns, mString);
		strcat(ns, other.GetCString());
		return MyString(ns);
	}

	int MyString::IndexOf(const char* s)
	{
		if (strstr(mString, s) != nullptr) 
		{
			int index = static_cast<int>(strstr(mString, s) - mString);
			return index;
		}
		else 
		{
			return -1;
		}
	}

	int MyString::LastIndexOf(const char* s)
	{
		char* ns = new char[strlen(s) + 1];
		strcpy(ns, s);

		char* nString = new char[mSize];
		strcpy(nString, mString);

		for (size_t i = 0; i < (strlen(s) + 1) / 2; i++)
		{
			char temp = ns[i];
			ns[i] = ns[strlen(s) + 1 - i - 2];
			ns[strlen(s) + 1 - i - 2] = temp;
		}
		for (size_t i = 0; i < mSize / 2; i++)
		{
			char temp = nString[i];
			nString[i] = nString[mSize - i - 2];
			nString[mSize - i - 2] = temp;
		}

		if (strstr(nString, ns) != nullptr) 
		{
			int index = mSize - 1 - static_cast<int>(strstr(nString, ns) - nString) - strlen(s);
			return index;
		}
		else 
		{
			return -1;
		}
	}

	void MyString::Interleave(const char* s)
	{
		unsigned int nSize = mSize + strlen(s);
		char* ns = new char[nSize];
		unsigned int a = 0;
		unsigned int n1 = 0;
		unsigned int n2 = 0;
		while (true) 
		{
			if (n1 < mSize - 1) 
			{
				ns[a] = mString[n1];
				n1++;
				a++;
			}
			if (n2 < strlen(s)) 
			{
				ns[a] = s[n2];
				n2++;
				a++;
			}
			if (a >= nSize - 1) 
			{
				ns[a] = s[n2];
				break;
			}
		}
		mString = ns;
		mSize = nSize;
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (index >= 0 && index < mSize - 1) 
		{
			char* ns = new char[mSize - 1];
			unsigned int a = 0;
			for (size_t i = 0; i < mSize; i++)
			{
				if (i != index) 
				{
					ns[a] = mString[i];
					a++;
				}
			}

			delete[] mString;
			mString = ns;
			mSize -= 1;
			return true;
		}
		else 
		{

			return false;
		}
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if (totalLength < mSize - 1) 
		{
			return;
		}
		char* ns = new char[totalLength + 1];
		for (size_t i = 0; i <= totalLength - mSize; i++)
		{
			ns[i] = ' ';
		}
		ns[totalLength - mSize + 1] = '\0';
		strcat(ns, mString);

		mString = ns;
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength < mSize - 1) 
		{
			return;
		}
		char* ns = new char[totalLength + 1];
		for (size_t i = 0; i <= totalLength - mSize; i++)
		{
			ns[i] = c;
		}
		ns[totalLength - mSize + 1] = '\0';
		strcat(ns, mString);

		mString = ns;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if (totalLength < mSize - 1) 
		{
			return;
		}
		char* ns = new char[totalLength + 1];
		strcpy(ns, mString);
		for (size_t i = mSize - 1; i <= totalLength; i++)
		{
			ns[i] = ' ';
		}
		ns[totalLength] = '\0';

		mString = ns;
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength < mSize - 1) 
		{
			return;
		}
		char* ns = new char[totalLength + 1];
		strcpy(ns, mString);
		for (size_t i = mSize - 1; i <= totalLength; i++)
		{
			ns[i] = c;
		}
		ns[totalLength] = '\0';

		mString = ns;
	}

	void MyString::Reverse()
	{
		for (size_t i = 0; i < mSize / 2; i++)
		{
			char temp = mString[i];
			mString[i] = mString[mSize - i - 2];
			mString[mSize - i - 2] = temp;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (strcmp(mString, rhs.GetCString()) == false) 
		{
			return true;
		}
		else 
		{

			return false;
		}
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		mSize = rhs.GetLength() + 1;
		char* nString = new char[mSize];
		memcpy(nString, rhs.GetCString(), mSize);
		delete[] mString;
		mString = nString;
		return *this;
	}

	void MyString::ToLower()
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (mString[i] >= 'A' && mString[i] <= 'Z') 
			{
				mString[i] += 32;
			}
		}
	}

	void MyString::ToUpper()
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (mString[i] >= 'a' && mString[i] <= 'z') 
			{
				mString[i] -= 32;
			}
		}
	}
}