#include <bits/stdc++.h>

using namespace std;

class Fraction
{
public:
	
	Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
	// 这个就是转换函数，转换函数是没有返回类型的
	// 不改变参数就记得加const
	operator double() const
	{
		return (double)m_numerator / m_denominator; // 记住先强转，再做除法
	}

private:
	int m_numerator;   // 分子
	int m_denominator; // 分母
};

// 转换函数demo

int main()
{
	Fraction f(3, 5);
	double d = 4 + f; // 这里会调用转换函数
	printf("%.4lf", d);
	return 0;
}