#include <bits/stdc++.h>

template <class T>
struct identity 
{
	const T &;
	operato()(const T &x) const { return x; }
}
// 这些结构体都是继承了unary_function<T,T>，还有一个binary_fuction
// 他们都继承了奇特的base classes

template <class Pair>
struct select1st
{
	const typename Pair::first_type &;
	operator()(const Pair &x) const
	{
		return x.first;
	}
}

template <class Pair>
struct select2st
{
	const typename Pair::second_type &;
	operator()(const Pair &x) const
	{
		return x.second;
	}
}

int
main()
{

	return 0;
}