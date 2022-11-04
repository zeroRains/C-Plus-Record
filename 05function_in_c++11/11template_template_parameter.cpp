#include <bits/stdc++.h>

using namespace std;

// 这个就是模板模板参数
template <typename T,
		  template <typename T>
		  class Container>
class XCLs
{
private:
	Container<T> c;
};

template <typename T>
using Lst = list<T, allocator<T>>;

int main()
{
	XCLs<string, Lst> mylst2;
	return 0;
}