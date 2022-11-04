#include <bits/stdc++.h>

using namespace std;

class Fraction
{
public:
	// 这里只有一个要传入的参数，另一个参数有默认值，所以这个构造函数可以说是non-explicit-one-argument constructor
	Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
	// 与转换函数的区别在于，转换函数是想要将对象转化成别的东西，而这个non-explicit-one-argument是将别的东西转化成对象
	// 这两个最好不要同时用，不然可能会出现一定的问题（二义性）
	Fraction operator+(const Fraction &f)
	{
		return Fraction();
	}

private:
	int m_numerator;   // 分子
	int m_denominator; // 分母
};

// 转换函数demo

int main()
{
	Fraction f(3, 5);
	Fraction d = f + 4; // 这里课以看到f要加一个Fraction，但是4不是，因此考虑能不能把4转换成Fraction，创建Fraction对象只用一个参数，所以4是可以转化的
	return 0;
}