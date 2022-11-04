#include <bits/stdc++.h>

using namespace std;
// 在不同的namespace之中定义不同的函数，则可以使用namespace_name::function_name的形式调用namespace中的函数
// 这样即使不同namespace空间中的function名字相同，也可以通过namespace的名字进行区分。
namespace jj01
{
	void test_namespace1() { cout << "jj01" << endl; }
}

namespace jj02
{
	void test_namespace1() { cout << "jj02" << endl; }
}

int main()
{
	jj01::test_namespace1();
	jj02::test_namespace1();
	return 0;
}