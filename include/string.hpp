/*
 *** WARNING!!!  警告！！！ ***
 * The library is a test library. It may not as efficient and safety as C++ standard library.
 * 该库文件仅供测试使用。此库有可能无法达到C++标准库的效率与安全性。
 * This is not for production systems. Please use std::string instead.
 * 它不是为生产系统设计的。请使用std::string替代它。
 *****

 Author: ShadowMov

 Feature:
 1. 实现了多种构造函数
 2. 实现了迭代器
 3. 实现了字符串比较、字符串连接的符号重载
 4. 通过memcpy()获得了尚可的效率
 5. 部分支持iostream输入输出

 Shortcoming:
 1. 未实现动态容量控制
 2. 未实现对iostream中getline()的支持
 3. 未实现find()等字符串操作
 4. 未提供Makefile
 */
#ifndef __TEST_STRING
#define __TEST_STRING

#include <iostream>
#include <iterator>

namespace test
{
	class string
	{
	private:  // private变量
		char* str;  
		unsigned long long len;
	public:
		typedef char * iterator; // 迭代器定义
		typedef const char * const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		string ();  // 构造函数
		string (const string &s);
		string (const char *s);
		string& operator= (const string &s);
		string& operator+= (const string &s); //运算符重载-连接并赋值
		string& operator+= (const char &c);

		iterator begin(); // 获取迭代器
		iterator end();
		const_iterator cbegin();
		const_iterator cend();
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator crbegin();
		const_reverse_iterator crend();

		~string ();  // 析构函数

		string operator[] (long long i); //运算符重载-取指定字符

		bool operator== (const string &s);  //运算符重载-比较类
		bool operator< (const string &s);
		bool operator> (const string &s);

		unsigned long long length();
		unsigned long long size();
		unsigned long long capacity();
		const char * c_str();
		char * data();

		friend std::istream& operator>> (std::istream &in, string &s);  //运算符重载-输入输出
		friend std::ostream& operator<< (std::ostream &out, const string &s);

		friend string operator+ (const string &lhs, const string &rhs); //运算符重载-字符串连接
		friend string operator+ (const char &lhs, const string &rhs);
		friend string operator+ (const string &lhs, const char &rhs);
		// char * 与 string 的连接为隐式调用
	};
}

#endif
