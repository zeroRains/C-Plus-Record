#ifndef __MYSTRING__
#define __MYSTRING__

// 拷贝赋值，编译器自动提供一位一位的复制粘贴
// 但是如果有指针的话，那他拷贝赋值就只拷贝赋值指针，这样和预期的效果不一样，因此一般自己写
#include <string.h>

class String
{
public:
	String(const char *cstr = 0); // 传进来的是字符串指针
	String(const String &str);	  // 传进来的是一个String object（拷贝构造）
	String &operator=(const String &str);	   // 操作符重载(拷贝复杂)，带指针的类一定要写
	~String();								   // 析构函数，object死亡时会被调用
	char *get_c_str() const { return m_data; } // 正常的成员函数

private:
	char *m_data;
};
inline String::String(const String &str) // 拷贝构造函数
{
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

inline String::String(const char *cstr)
{
	if (cstr)
	{
		m_data = new char[strlen(cstr) + 1]; // 字符创长度+1个结束符
		strcpy(m_data, cstr);
	}
	else // 如果不是0，所以放一个结束符
	{
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline String::~String() { delete[] m_data; } // 在object死亡时调用，释放已经分配的内存

// 拷贝赋值
inline String &String::operator=(const String &str)
{
	if (this == &str) // 自我检测
		return *this;
	delete[] m_data;						   // 先杀掉自己
	m_data = new char[strlen(str.m_data) + 1]; // 再重新创造自己
	strcpy(m_data, str.m_data);				   // 再拷贝
	return *this;
}

#include <iostream>

std::ostream &operator<<(std::ostream &os, const String &str)
{
	os << str.get_c_str();
	return os;
}

#endif