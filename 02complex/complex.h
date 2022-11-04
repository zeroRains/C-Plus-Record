#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>

// 前置声明
// class ostream;
class complex;

complex &__doapl(complex *ths, const complex &r);
// 模板类定义数据类型
// template <typename T>
// 类声明
class complex
{
	// 一般将构造函数写在public中，如果不想由外界创建，则写在private中，然后使用static函数调用构造函数进行创建（设计模式：单例）
public:													  // 公共属性
														  // 构造函数，会被自动调用，没有返回类型，和类名同名，构造函数可以由很多个（重载）
														  // 在下面这函数中有等号加值，表示默认参数
	complex(double r = 0, double i = 0) : re(r), im(i) {} //初值化，就是把数值设置到对应的变量中,pass by value
	// 变量设置有两个阶段：初始化和赋值，上面的例子就是使用第一阶段，如果在括号里面写就是赋值

	/*
	相同class的各个obejct互为friends
	int func(const complex& param){
		return param.re + param.im;
	}
	*/

	// return by reference 和 return by value
	complex &operator+=(const complex &); // 重写+=这个操作，pass by reference (to const)，const表示引用的内容不可修改
	double real() const { return re; }	  // 在内部定义就是inline（内联），但不一定就能被直接inline（由编译器决定）
	double imag() const { return im; }	  // 函数后面加const：表示函数不会改变数据内容，加在对象和变量前面，表示对象或者变量的内容不可改变

private: // 私有属性
	// T re, im; //使用模板
	double re, im;
	// 友元
	friend complex &__doapl(complex *, const complex &); // pass by reference
};

// 内联函数：直接在调用的位置写入整个函数结构
inline complex &__doapl(complex *ths, const complex &r)
{
	ths->re += r.re; // 因为这个函数是complex的fiend，所以可以直接调用private中的属性
	ths->im += r.im;
	return *ths;
}

// 操作符重载-1
inline complex &complex::operator+=(const complex &r) { return __doapl(this, r); }

inline double imag(const complex &x) { return x.imag(); }

inline double real(const complex &x) { return x.real(); }

// 操作符重载-2，非成员函数
// return by reference，因为他们返回的都是局部变量，离开函数后就会销毁。
inline complex operator+(const complex &x, const complex &y)
{
	return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex operator+(const complex &x, double y)
{
	return complex(real(x) + y, imag(x));
}

inline complex operator+(double x, const complex &y)
{
	return complex(x + real(y), imag(y));
}

// 正号与取反的运算
inline complex operator+(const complex &x) { return x; }
inline complex operator-(const complex &x) { return complex(-real(x), -imag(x)); }

// 等号与不等号重载
inline bool operator==(const complex &x, const complex &y)
{
	return real(x) == real(y) && imag(x) == imag(y);
}

inline bool operator==(const complex &x, double y)
{
	return real(x) == y && imag(x) == 0;
}

inline bool operator==(double x, const complex &y)
{
	return x == real(y) && 0 == imag(y);
}

inline bool operator!=(const complex &x, const complex &y)
{
	return real(x) != real(y) || imag(x) != imag(y);
}

inline bool operator!=(const complex &x, double y)
{
	return real(x) != y || imag(x) != 0;
}

inline bool operator!=(double x, const complex &y)
{
	return x != real(y) || 0 != imag(y);
}

// 共轭复数
inline complex conj(const complex &x)
{
	return complex(real(x), -imag(x));
}

#include <iostream>
// 重载输出操作符
// 这里要注意命名空间的问题
std::ostream &operator<<(std::ostream &os, const complex &x)
{
	return os << '(' << real(x) << ',' << imag(x) << ')';
}

// 类定义
// complex:function

#endif