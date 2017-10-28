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
 */
#include <iostream>
#include <cstring>
#include <string.hpp>

namespace test{
	string::string() //空字符串构造函数
	{
		this->len = 0;
		this->str = new char[1];
		this->str[0] = 0;
	}

	string::string(const string &s) //拷贝构造函数
	{
		this->len = s.len;
		this->str = new char[this->len+1];
		memcpy(this->str, s.str, this->len+1);
	}

	string::string(const char *s) //根据char*创建对象的构造函数
	{
		if (s==NULL) //空串判定
		{
			this->len = 0;
			this->str = new char[1];
			this->str[0] = 0;
			return;
		}
		this->len = strlen(s); //不考虑不合法字符串
		this->str = new char[this->len+1];
		memcpy(this->str, s, this->len+1);
	}

	string& string::operator= (const string &s) //重载赋值操作
	{
		if (this==&s) return *this; //避免自我赋值造成混乱
		delete[] this->str; //释放内存
		this->len = s.len;
		this->str = new char[this->len+1];
		memcpy(this->str, s.str, this->len+1);
		return *this;
	}

	string::iterator string::begin()
	{
		return this->str;
	}

	string::iterator string::end()
	{
		return this->str + this->len;
	}

	string::const_iterator string::cbegin()
	{
		return this->str;
	}

	string::const_iterator string::cend()
	{
		return this->str + this->len;
	}

	string::reverse_iterator string::rbegin()
	{
		return string::reverse_iterator(this->str + this->len);
	}

	string::reverse_iterator string::rend()
	{
		return string::reverse_iterator(this->str);
	}

	string::const_reverse_iterator string::crbegin()
	{
		return string::const_reverse_iterator(this->str + this->len);
	}

	string::const_reverse_iterator string::crend()
	{
		return string::const_reverse_iterator(this->str);
	}

	string::~string()  //析构函数
	{
		delete[] this->str;
	}

	bool string::operator== (const string &s) //字符串比较
	{
		if (this->len!=s.len) return false;
		for (unsigned long long i=0; i<this->len; ++i)
		{
			if (this->str[i]!=s.str[i]) return false;
		}
		return true;
	}

	bool string::operator< (const string &s) //字典序小于
	{
		for (unsigned long long i=0; i<std::min(this->len, s.len); ++i)
		{
			if (this->str[i]<s.str[i]) return true;
			if (this->str[i]>s.str[i]) return false;
		}
		if (this->len < s.len) return true;
		return false;
	}

	bool string::operator> (const string &s) //字典序大于
	{
		for (unsigned long long i=0; i<std::min(this->len, s.len); ++i)
		{
			if (this->str[i]<s.str[i]) return false;
			if (this->str[i]>s.str[i]) return true;
		}
		if (this->len > s.len) return true;
		return false;
	}

	string operator+ (const string &lhs, const string &rhs) // string + string
	{
		string ret;
		ret.len = lhs.len+rhs.len;
		ret.str = new char[ret.len+1];
		memcpy(ret.str, lhs.str, lhs.len);
		memcpy(ret.str+lhs.len, rhs.str, rhs.len+1);
		return ret;
	}

	string operator+ (const string &lhs, const char &rhs)  // string + char
	{
		string ret;
		ret.len = lhs.len+1;
		ret.str = new char[lhs.len+2];
		memcpy(ret.str, lhs.str, lhs.len);
		ret.str[lhs.len] = rhs;
		ret.str[ret.len] = 0;
		return ret;
	}

	string operator+ (const char &lhs, const string &rhs) // char + string
	{
		string ret;
		ret.len = rhs.len+1;
		ret.str = new char[rhs.len+2];
		memcpy(ret.str+1, rhs.str, rhs.len);
		ret.str[0] = lhs;
		ret.str[ret.len] = 0;
		return ret;
	}

	// char * 与 string 的连接为隐式调用

	string& string::operator+= (const string &s) // 调用+处理+=
	{
		return *this=*this+s;
	}

	string& string::operator+= (const char &c)
	{
		return *this=*this+c;
	}

	std::istream& operator>> (std::istream &in, string &s) // 处理输入
	{
		char c;
		s = ""; // 先清空
		while((in.get(c))&&((c==' ')||(c=='\n')||(c=='\r')));
		s += c;
		while((in.get(c))&&(c!=' ')&&(c!='\n')&&(c!='\r'))
			s += c;
		return in;
	}

	std::ostream& operator<< (std::ostream &out, const string &s)  // 处理输出
	{
		out << s.str;
		return out;
	}

	unsigned long long string::size()
	{
		return this->len;
	}

	unsigned long long string::length()
	{
		return this->len;
	}

	unsigned long long string::capacity()
	{
		return this->len;
	}

	const char * string::c_str()
	{
		return this->str;
	}

	char * string::data()
	{
		char *ret;
		ret = new char[this->len+1];
		memcpy(ret, this->str, this->len+1);
		return ret;
	}
}
