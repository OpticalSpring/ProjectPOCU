#include "MyString.h"

namespace assignment1
{
    MyString::MyString(const char* s)
    {
    }

    MyString::MyString(const MyString& other)
    {
    }

    MyString::~MyString()
    {
    }

    unsigned int MyString::GetLength() const
    {
        return 0;
    }

    const char* MyString::GetCString() const
    {
        return 0;
    }

    void MyString::Append(const char* s)
    {
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
        return false;
    }

    MyString& MyString::operator=(const MyString& rhs)
    {
        return *this;
    }

    void MyString::ToLower()
    {
    }

    void MyString::ToUpper()
    {
    }
}