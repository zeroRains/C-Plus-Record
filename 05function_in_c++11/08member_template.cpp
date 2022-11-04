#include <bits/stdc++.h>

using namespace std;

template <class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;
	pair() : first(T1()), second(T2()) {}
	pair(const T1 &a, const T2 &b) : first(a), second(b) {}

	// 这个就是成员模板的示例
	// 比如T1和T2当做鱼类和鸟类
	// 然后U1和U2当做鲫鱼类和麻雀类
	// 然后在执行下面的初始化的适合，由于T1和T2是U1和U2的父类，所以可以直接借助他们进行初始化
	template <class U1, class U2>
	pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}
}

int
main()
{

	return 0;
}