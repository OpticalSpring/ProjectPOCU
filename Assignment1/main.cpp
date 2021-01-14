#include <iostream>
#include <cassert>
#include "MyString.h"
using namespace std;

using namespace assignment1;
void test() {
	/* GetLength() Ex */
	cout << "-----------------------" << endl;
	cout << "GetLength()" << endl;
	MyString s1("Hello");
	cout << s1.GetLength() << endl;   // 5

	/* GetCString() Ex */
	cout << "-----------------------" << endl;
	cout << "GetCString()" << endl;
	MyString s2("Hello");
	cout << s2.GetCString() << endl;  // Hello

	/* Append() Ex */
	cout << "-----------------------" << endl;
	cout << "Append()" << endl;
	MyString s3("Hello");
	s3.Append(" World");
	cout << s3.GetCString() << endl;  // Hello World
	s3.Append("\n\tWorld\n");
	cout << s3.GetCString() << endl;

	/* operator+ Ex */
	cout << "-----------------------" << endl;
	cout << "operator+" << endl;
	MyString s41("Hello");
	MyString s42(" World");
	MyString s43 = s41 + s42;
	//s2 = s2 + s1;  소멸자 오류(이번 과제에서는 체크하지 않음)
	cout << s43.GetCString() << endl;   //Hello World

	/* IndexOf() Ex */
	cout << "-----------------------" << endl;
	cout << "IndexOf()" << endl;
	MyString s5("Hello");
	cout << s5.IndexOf("ell") << endl;   // 1
	cout << s5.IndexOf("l") << endl;     // 2
	cout << s5.IndexOf("This") << endl;  // -1
	cout << s5.IndexOf("") << endl;   // 0
	cout << s5.IndexOf("lo") << endl;   // 3

	MyString s52("");
	cout << s52.IndexOf("") << endl;   // 0
	cout << s52.IndexOf("A") << endl; // -1

	MyString s53("Hellello");
	MyString s54("Heloo");
	cout << s53.IndexOf("ell") << endl;   // 1
	cout << s54.IndexOf("ell") << endl;   // -1

	/* LastIndexOf() Ex */
	cout << "-----------------------" << endl;
	cout << "LastIndexOf()" << endl;
	MyString s6("Hello");
	cout << s6.LastIndexOf("ell") << endl;   // 1
	cout << s6.LastIndexOf("l") << endl;     // 3
	cout << s6.LastIndexOf("This") << endl;  // -1
	cout << s6.LastIndexOf("") << endl;   // 5
	cout << s6.LastIndexOf("He") << endl;   // 0

	MyString s62("");
	cout << s62.LastIndexOf("") << endl;  // 0
	cout << s62.LastIndexOf("A") << endl; // -1

	MyString s63("Hellello");
	MyString s64("Heloo");
	cout << s63.LastIndexOf("ell") << endl;   // 4
	cout << s64.LastIndexOf("ell") << endl;   // -1

	/* Interleave() Ex */
	cout << "-----------------------" << endl;
	cout << "Interleave()" << endl;
	MyString s7("Hello");
	s7.Interleave(" World");
	cout << s7.GetCString() << endl;  //H eWlolrold

	MyString s72("A");
	s72.Interleave("BCDEF");
	cout << s72.GetCString() << endl;  // ABCDEF

	MyString s73("bcdef");
	s73.Interleave("a");
	cout << s73.GetCString() << endl;  // bacdef

	/* RemoveAt() Ex */
	cout << "-----------------------" << endl;
	cout << "RemoveAt()" << endl;
	MyString s8("Hello");
	cout << boolalpha << s8.RemoveAt(0) << ", ";   // true,
	cout << s8.GetCString() << endl;               // ello
	cout << boolalpha << s8.RemoveAt(2) << ", ";   // true,
	cout << s8.GetCString() << endl;               // elo
	cout << boolalpha << s8.RemoveAt(4) << ", ";   // false,
	cout << s8.GetCString() << endl;               // elo

	MyString s82("");
	cout << boolalpha << s82.RemoveAt(0) << endl;  //false

	/* PadLeft() Ex */
	cout << "-----------------------" << endl;
	cout << "PadLeft()" << endl;
	MyString s9("Hello");
	s9.PadLeft(2);  // "Hello"
	cout << s9.GetCString() << endl;
	s9.PadLeft(8);  // "   Hello"
	cout << s9.GetCString() << endl;

	MyString s92("World");
	s92.PadLeft(3, '-');  // "World"
	cout << s92.GetCString() << endl;
	s92.PadLeft(7, '-');  // "--World"
	cout << s92.GetCString() << endl;

	/* PadRight() Ex */
	cout << "-----------------------" << endl;
	cout << "PadRight()" << endl;
	MyString s10("Hello");
	s10.PadRight(2);  // "Hello"
	cout << s10.GetCString() << endl;
	s10.PadRight(8);  // "Hello   "
	cout << s10.GetCString() << '|' << endl;// 공백 확인 위한 |

	MyString s102("World");
	s102.PadRight(3, '-');  // "World"
	cout << s102.GetCString() << endl;
	s102.PadRight(7, '-');  // "World--"
	cout << s102.GetCString() << endl;

	/* Reverse() Ex */
	cout << "-----------------------" << endl;
	cout << "Reverse()" << endl;
	MyString s11("Hello");
	s11.Reverse();  // olleH
	cout << s11.GetCString() << endl;

	MyString s112("Banana");
	s112.Reverse();   // ananaB
	cout << s112.GetCString() << endl;

	MyString s113("A");
	s113.Reverse();   // A
	cout << s113.GetCString() << endl;

	MyString s114("");
	s114.Reverse();   // 
	cout << s114.GetCString() << endl;

	/* operator== Ex */
	cout << "-----------------------" << endl;
	cout << "operator==" << endl;
	MyString s121("Hello");
	MyString s122("Hello");
	MyString s123("World");
	MyString s124("Hello ");

	cout << boolalpha << (s121 == s122) << endl;   // true
	cout << boolalpha << (s121 == s123) << endl;   // false
	cout << boolalpha << (s121 == s124) << endl;   // false

	/* ToLower() Ex */
	cout << "-----------------------" << endl;
	cout << "ToLower()" << endl;
	MyString s131("HEllo 123K");
	MyString s132("A To z");
	s131.ToLower();   // "hello 123k"
	s132.ToLower();   // "a to z"
	cout << s131.GetCString() << endl;
	cout << s132.GetCString() << endl;

	/* ToUpper() Ex */
	cout << "-----------------------" << endl;
	cout << "ToUpper()" << endl;
	MyString s141("HEllo 123K");
	MyString s142("A To z");
	s141.ToUpper();   // "HELLO 123K"
	s142.ToUpper();   // "A TO Z"
	cout << s141.GetCString() << endl;
	cout << s142.GetCString() << endl;
}

void test2() {
	MyString str(nullptr);
	str.Append("Hello");
	assert(strcmp(str.GetCString(), "Hello") == 0);
	std::cout << "nullptr 생성 이후 Append : " << str.GetCString() << std::endl;


	MyString constructorTest("Hello");
	std::cout << "문자열 생성 : " << constructorTest.GetCString() << std::endl;
	std::cout << "문자열 생성 길이 : " << constructorTest.GetLength() << std::endl;
	assert(strcmp(constructorTest.GetCString(), "Hello") == 0);
	assert(constructorTest.GetLength() == 5);


	std::cout << std::hex;
	MyString originalStr("Hello");
	MyString copyStr(originalStr);
	int originalStrAddress = reinterpret_cast<int>(originalStr.GetCString());
	int copyStrAddress = reinterpret_cast<int>(copyStr.GetCString());
	std::cout << "원본 : " << originalStr.GetCString() << ", 원본 주소 : " << originalStrAddress << std::endl;
	std::cout << "복사본 : " << copyStr.GetCString() << ", 복사본 주소 : " << copyStrAddress << std::endl;
	assert(originalStrAddress != copyStrAddress);
	assert(strcmp(originalStr.GetCString(), "Hello") == 0);
	assert(strcmp(copyStr.GetCString(), "Hello") == 0);


	MyString appendTestFunctional("Hello");
	appendTestFunctional.Append(" World");
	std::cout << "문자열 이어 붙히기 함수형 내부값 변경 : " << appendTestFunctional.GetCString() << std::endl;
	assert(strcmp(appendTestFunctional.GetCString(), "Hello World") == 0);


	MyString appendTestOperator1("Hello");
	MyString appendTestOperator2(" World");
	MyString appendTestOperator3 = appendTestOperator1 + appendTestOperator2;
	std::cout << "문자열 이어 붙히기 연산자 반환 : " << appendTestOperator3.GetCString() << std::endl;
	assert(strcmp(appendTestOperator3.GetCString(), "Hello World") == 0);


	MyString indexOfTest("Hello");
	assert(indexOfTest.IndexOf("el") == 1);
	assert(indexOfTest.IndexOf("ll") == 2);
	assert(indexOfTest.IndexOf("l") == 2);
	assert(indexOfTest.IndexOf("asd") == -1);
	assert(indexOfTest.IndexOf("") == 0);
	assert(indexOfTest.IndexOf(nullptr) == -1);
	assert(indexOfTest.IndexOf("lo") == 3);

	assert(indexOfTest.LastIndexOf("l") == 3);
	assert(indexOfTest.LastIndexOf("asd") == -1);
	assert(indexOfTest.LastIndexOf("") == indexOfTest.GetLength());
	assert(indexOfTest.LastIndexOf(nullptr) == -1);
	assert(indexOfTest.LastIndexOf("He") == 0);

	MyString emptyIndexOfTest("");
	assert(emptyIndexOfTest.IndexOf("a") == -1);
	assert(emptyIndexOfTest.IndexOf("") == 0);
	assert(emptyIndexOfTest.LastIndexOf("") == emptyIndexOfTest.GetLength());



	int previousInterLeaveTestStrAddress = reinterpret_cast<int>(interLeaveTest.GetCString());
	interLeaveTest.Interleave("");
	int currentInterLeaveTestStrAddress = reinterpret_cast<int>(interLeaveTest.GetCString());
	assert(previousInterLeaveTestStrAddress == currentInterLeaveTestStrAddress);

	std::cout << std::boolalpha;
	MyString removeTest("Hello");
	bool b1 = removeTest.RemoveAt(0); // s는 "ello", b1은 true
	std::cout << "Hello의 첫글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b1 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ello") == 0);
	assert(b1 == true);

	bool b2 = removeTest.RemoveAt(3); // s는 "ell", b2은 true
	std::cout << "ello의 네번째 글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b2 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b2 == true);

	bool b3 = removeTest.RemoveAt(4); // s는 "ell", b3은 false
	std::cout << "ell의 다섯번째 글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b3 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b3 == false);



	MyString padLeftTest1("Hello");
	int previousPadLeftTest1StrAddress = reinterpret_cast<int>(padLeftTest1.GetCString());
	padLeftTest1.PadLeft(2); // s1: "Hello"
	int currentPadLeftTest1StrAddress = reinterpret_cast<int>(padLeftTest1.GetCString());
	std::cout << padLeftTest1.GetCString() << std::endl;
	assert(previousPadLeftTest1StrAddress == currentPadLeftTest1StrAddress);
	assert(strcmp(padLeftTest1.GetCString(), "Hello") == 0);

	padLeftTest1.PadLeft(8); // s1: "   Hello"
	assert(strcmp(padLeftTest1.GetCString(), "   Hello") == 0);
	std::cout << padLeftTest1.GetCString() << std::endl;



	MyString padLeftTest2("Hello");
	int previousPadLeftTest2StrAddress = reinterpret_cast<int>(padLeftTest2.GetCString());
	padLeftTest2.PadLeft(3, '-'); // s1: "Hello"
	int currentPadLeftTest2StrAddress = reinterpret_cast<int>(padLeftTest2.GetCString());
	std::cout << padLeftTest2.GetCString() << std::endl;
	assert(previousPadLeftTest2StrAddress == currentPadLeftTest2StrAddress);
	assert(strcmp(padLeftTest2.GetCString(), "Hello") == 0);

	padLeftTest2.PadLeft(7, '-'); // s1: "   Hello"
	std::cout << padLeftTest2.GetCString() << std::endl;
	assert(strcmp(padLeftTest2.GetCString(), "--Hello") == 0);



	MyString padRightTest1("Hello");
	int previousPadRightTest1StrAddress = reinterpret_cast<int>(padRightTest1.GetCString());
	padRightTest1.PadRight(2); // s1: "Hello"
	int currentPadRightTest1StrAddress = reinterpret_cast<int>(padRightTest1.GetCString());
	std::cout << padRightTest1.GetCString() << std::endl;
	assert(previousPadRightTest1StrAddress == currentPadRightTest1StrAddress);
	assert(strcmp(padRightTest1.GetCString(), "Hello") == 0);

	padRightTest1.PadRight(8); // s1: "   Hello"
	std::cout << padRightTest1.GetCString() << "I" << std::endl;
	assert(strcmp(padRightTest1.GetCString(), "Hello   ") == 0);



	MyString padRightTest2("Hello");
	int previousPadRightTest2StrAddress = reinterpret_cast<int>(padRightTest2.GetCString());
	padRightTest2.PadRight(3, '-'); // s1: "Hello"
	int currentPadRightTest2StrAddress = reinterpret_cast<int>(padRightTest2.GetCString());
	std::cout << padRightTest2.GetCString() << std::endl;
	assert(previousPadRightTest2StrAddress == currentPadRightTest2StrAddress);
	assert(strcmp(padRightTest2.GetCString(), "Hello") == 0);

	padRightTest2.PadRight(7, '-'); // s1: "   Hello"
	std::cout << padRightTest2.GetCString() << std::endl;
	assert(strcmp(padRightTest2.GetCString(), "Hello--") == 0);



	MyString reverseTest("Hello");
	int previousReverseTestStrAddress = reinterpret_cast<int>(reverseTest.GetCString());
	reverseTest.Reverse();
	int currentReverseTestStrAddress = reinterpret_cast<int>(reverseTest.GetCString());
	std::cout << "문자를 거꾸로 : " << reverseTest.GetCString() << std::endl;
	assert(strcmp(reverseTest.GetCString(), "olleH") == 0);



	MyString equelsOperatorTest1("Hello");
	MyString equelsOperatorTest2("Hello");
	MyString equelsOperatorTest3("World");
	assert((equelsOperatorTest1 == equelsOperatorTest2) == true);
	assert((equelsOperatorTest1 == equelsOperatorTest3) == false);



	MyString toLowerTest("HEllo 123K");
	toLowerTest.ToLower(); // s1: "hello 123k"
	assert(strcmp(toLowerTest.GetCString(), "hello 123k") == 0);
	std::cout << "전체 문자 소문자로 변경 : " << toLowerTest.GetCString() << std::endl;



	MyString toUpperTest("HEllo 123K");
	toUpperTest.ToUpper(); // s1: "HELLO 123K"
	assert(strcmp(toUpperTest.GetCString(), "HELLO 123K") == 0);
	std::cout << "전체 문자 대문자로 변경 : " << toUpperTest.GetCString() << std::endl;

}

void test3() {
	//	메모리 체크용 변수
	int beforeAddress1;
	int beforeAddress2;

	MyString testString1("Happy Happy Days");
	MyString testString2("Happy Days");
	MyString testString3("Happy Days");
	MyString testString4("");

	//	Operator == 관련
	beforeAddress1 = (int)testString2.GetCString();
	beforeAddress2 = (int)testString3.GetCString();
	if (testString2 == testString3);
	assert(beforeAddress1 == (int)testString2.GetCString());
	assert(beforeAddress2 == (int)testString3.GetCString());
	cout << "D2_NoMallocInCompareSameLength 통과" << endl;

	beforeAddress1 = (int)testString1.GetCString();
	beforeAddress2 = (int)testString2.GetCString();
	if (testString1 == testString2);
	assert(beforeAddress1 == (int)testString1.GetCString());
	assert(beforeAddress2 == (int)testString2.GetCString());
	cout << "D5_NoMallocInCompareDifferentLength 통과" << endl;

	//	IndexOf, LastOfIndex 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.IndexOf("Happy");
	testString1.IndexOf("");
	assert(beforeAddress1 == (int)testString1.GetCString());

	beforeAddress1 = (int)testString1.GetCString();
	testString1.LastIndexOf("Happy");
	testString1.LastIndexOf("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "E5_NoMallocInIndexOf 통과" << endl;

	//	ToUpper, ToLower 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.ToUpper();
	testString1.ToLower();
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "F3_NoMallocInUpperLower 통과" << endl;

	//	Reverse 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Reverse();
	testString1.Reverse();
	assert(beforeAddress1 == (int)testString1.GetCString());
	beforeAddress1 = (int)testString4.GetCString();
	testString4.Reverse();
	assert(beforeAddress1 == (int)testString4.GetCString());
	cout << "G4_NoMallocInReverse 통과" << endl;

	//	Append 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Append("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "H3_NoMallocInAppendEmpty 통과" << endl;

	//	 RemoveAt 관련
	beforeAddress1 = (int)testString4.GetCString();
	testString4.RemoveAt(0);
	assert(beforeAddress1 == (int)testString4.GetCString());
	cout << "J2_RemoveAtNoMallocOnEmpty 통과" << endl;

	//	PadLeft, PadRight 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadLeft(16);
	testString1.PadLeft(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "K4_NoMallocInPadLeftShorter 통과" << endl;

	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadRight(16);
	testString1.PadRight(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "L4_NoMallocInPadRightShorter 통과" << endl;

	//	InterLeave 관련

	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadRight(16);
	testString1.PadRight(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "L4_NoMallocInPadRightShorter 통과" << endl;

	//	InterLeave 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Interleave("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "M3_NoMallocInInterleaveEmpty 통과" << endl;

}

int main()
{
	test2();
}