#include <bits/stdc++.h>

// using namespace std;
// 首先要定义泛化，然后才能定义特化
template <class Key>
struct hash
{
};

// 特化模板
template <>		  //这里不像之前的模板一样直接写内容了
struct hash<char> // 类型写到这里来（然后感觉像是重载一样，对不同的类型做不同的处理）
{
	size_t operator()(char x) const { return x; }
};

template <>
struct hash<int>
{
	size_t operator()(int x) const { return x; }
};

template <>
struct hash<long>
{
	size_t operator()(long x) const { return x; }
};

int main()
{
	std::cout << hash<long>()(1000000000) << std::endl; // 第一个括号表示生成一个struct的对象，然后第二个括号表示重载的操作符
	std::cout << hash<char>()('a') << std::endl;
	std::cout << hash<int>()(10) << std::endl;
	return 0;
}