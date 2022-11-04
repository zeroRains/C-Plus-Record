#include <bits/stdc++.h>

using namespace std;

void print() // 这个主要是处理最后一个参数结束后，没有参数了就不能调用下面的那个函数了，这样就会报错
{
	// 所以加了这个之后用于处理没有参数进来的情况
	cout << "empty arguments invoked" << endl; 
}

// 数量不定的模板参数
template <typename T, typename... Types>			// 不定模板
void print(const T &firstArg, const Types &...args) // 不定参数输入
{
	cout << firstArg << endl; 
	print(args...); // 这里是递归的方式进行参数传递
}

// auto直接在这里写了，不想写demo了
// auto就是自己推类型，经常用于自动推断迭代器的类型

// ranged-base for
// for的新写法，就是auto 声明一个变量，然后加冒号，然后遍历一个可迭代的对象
// 举个例子，现在有一个还有10个数字的vector<int> numbers，使用for遍历他的例子如下
/*
	for(auto item: numbers)
		cout<<item<<endl;
	// for会遍历这个numbers的vecotor的每一个元素，然后用auto表示这个数字， 所以auto item就可以认为是numbers中的每一个元素
*/



int main()
{
	print(7.5, 7, "hello", bitset<16>(377), 42);
	return 0;
}