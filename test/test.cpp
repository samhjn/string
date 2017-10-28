/*
	string类测试程序
	编译参数: 
		使用原版string类: g++ -O3 -o main.exe main.cpp --std=c++11 -Wall -D ORIGIN_STRING
		使用测试string类: g++ -O3 -o main.exe main.cpp string.cpp --std=c++11 -Wall
	性能测试Tips:
	    利用管道功能可以在同等状态下比较输入时间
*/
#include <iostream>
#include <time.h>

#ifdef ORIGIN_STRING //根据编译参数选择使用的类

#include <string>
using std::string;

#else

#include "string.hpp"
using test::string;

#endif

using std::cin;
using std::cout;
using std::endl;

void test_constructor()
{
	cout << "Constructor test" << endl;

	string s2 = "Test string";
	cout << "s1=" << s2 << endl;

	string s3 = s2;
	cout << "s2=" << s3 << endl;
}

void test_input()
{
	cout << "String input test" << endl;

	cout << "Please input two strings" << endl;
	string s1, s2;
	cin >> s1 >> s2;
	cout << "s1   =" << s1 << endl;
	cout << "s2   =" << s2 << endl;
	cout << "s1+s2=" << s1+s2 << endl;
}

void test_calc()
{
	cout << "String calculate test" << endl;

	string s1 = "This is";
	string s2 = "a test.";
	char c = ' ';

	cout << "s1      =" << s1 << endl;
	cout << "s2      =" << s2 << endl;
	cout << "c+s2    =" << c+s2 << endl;
	cout << "s1+c+s2 =" << s1+c+s2 << endl;

	string s3;
	string s4;
	for (char i='A'; i<='Z'; ++i)
	{
		s3+=i;
		s4+=i+'a'-'A';
	}

	cout << endl;
	cout << "s3     =" << s3 << endl;
	cout << "s4     =" << s4 << endl;
	cout << "s3+=s4 =" << (s3+=s4) << endl;

	string s5 = "foobar";
	string s6 = "foo";
	string s7 = "bar";

	cout << endl;
	cout << "s5        =" << s5 << endl;
	cout << "s6        =" << s6 << endl;
	cout << "s7        =" << s7 << endl;
	cout << "s5>s6     =" << (s5>s6) << endl;
	cout << "s5<s6     =" << (s5<s6) << endl;
	cout << "s5==s6    =" << (s5==s6) << endl;
	cout << "s7>s5     =" << (s7>s5) << endl;
	cout << "s7<s5     =" << (s7<s5) << endl;
	cout << "s7==s5    =" << (s7==s5) << endl;
	cout << "s6+s7>s5  =" << (s6+s7>s5) << endl;
	cout << "s6+s7<s5  =" << (s6+s7<s5) << endl;
	cout << "s6+s7==s5 =" << (s6+s7==s5) << endl;
}

void test_iterator()
{
	cout << "iterator test" << endl;

	string s = "This is a test text.";

	for (string::const_iterator it=s.cbegin(); it!=s.cend(); ++it)
	{
		cout << *it;
	}
	cout << endl;

	for (string::const_reverse_iterator it=s.crbegin(); it!=s.crend(); ++it)
	{
		cout << *it;
	}
	cout << endl;

	for (string::iterator it=s.begin(); it!=s.end(); ++it)
	{
		if (*it!=' ') (*it)++;
	}
	cout << s << endl;

	for (string::reverse_iterator it=s.rbegin(); it!=s.rend(); ++it)
	{
		if (*it!=' ') (*it)--;
	}
	cout << s << endl;
}

void (*tests[])() = {
	test_constructor, test_input, test_calc, test_iterator
};

int main()
{
	for (int i=0; i<int(sizeof(tests)/sizeof(void (*)())); ++i)
	{
		clock_t start_time, stop_time;
		double duration;

		#ifndef WIN32
		cout << "\033[37;1m";  // 高亮
		#endif

		cout << "==========" << "Test Case " << i << "==========" << endl;

		#ifndef WIN32
		cout << "\033[0m";  // 关闭高亮效果
		#endif

		start_time = clock();
		tests[i]();
		stop_time = clock();
		duration = (double)(stop_time - start_time) / CLOCKS_PER_SEC * 1000;

		cout << endl << "Test " << i << " duration: " << duration << "ms" << endl << endl;
	}
	return 0;
}
