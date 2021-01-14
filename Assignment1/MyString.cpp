#include "MyString.h"
#include "String.h"

using namespace std;

namespace assignment1
{

	char* strrstr(const char* s1, const char* s2)
	{
		size_t l1, l2;

		l2 = strlen(s2);

		/* s2 문자열의 길이가 0이라면 무조건 매칭으로 보고 s1의 시작주소를 반환합니다. */
		if (!s2)
			return (char*)s1;

		l1 = strlen(s1);
		s1 += l1;
		/* 남은 l1의 길이가 l2 길이 보다 작다면, 비교할 의미가 없으므로 NULL을 리턴합니다. */
		while (l1 >= l2) {
			l1--;
			/*
			 * s1의 포인터 위치를 이동하면서,
			 * 현재 s1과 s2의 메모리를 s2의 사이즈만큼 비교합니다.
			 * 같으면 현재 s1의 포인터를 리턴합니다.
			 */
			if (!memcmp(s1, s2, l2))
				return (char*)s1;
			s1--;
		}
		return NULL;
	}

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
		if (strrstr(mString, s) != nullptr)
		{
			int index = static_cast<int>(strrstr(mString, s) - mString);
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