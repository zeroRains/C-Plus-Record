#include <bits/stdc++.h>

using namespace std;

// 模板偏特化，个数上的偏
// 特化前先要写模板
template <typename T, typename Alloc = ...>
class vector
{
	// template中的Alloc表示分配器
};

// 个数上的偏特化

template <typename Alloc = ...>
class vector<bool, Alloc>
{
	// 在这个例子中，我们指定了T是布尔值，但是没有指定Alloc，所以还是用Alloc进行占位，这个就是个数上的偏特化
	// 个数偏只能从左到右偏
};

// 范围上的偏
template <typename T>
class C
{
};

template <typename U>
class C<U *>
{
	// 类型是指针，指向什么都行
	// 原本是任意类型的，在特化之后范围变成了指针类型，范围缩小了
};

int main()
{

	return 0;
}