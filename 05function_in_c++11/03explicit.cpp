#include <bits/stdc++.h>

using namespace std;

class Fraction
{
public:
	// 这里的explicit表示的是我这里就是定义一个构造函数，如果你不是创建的话就不要来调用
	explicit Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}

	Fraction operator+(const Fraction &f)
	{
		return Fraction();
	}
	// 不改变参数就记得加const，通过explicit，这样转换函数就能解决02的问题了。
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
	 Fraction d = f + 4; // 这时候如果还是使用这样的写法就会报错，想吧4转化成Fraction是不背允许的
	return 0;
}