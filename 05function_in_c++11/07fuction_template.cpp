#include <bits/stdc++.h>

using namespace std;

template <typename T> // 我不想把类型写死，我就可以先用模板占个位，当然，typename的关键字可以改为class关键字
inline const T min_test(const T &a, const T &b)
{
	return a < b ? a : b;
}

int main()
{
	cout << min_test(10, 5) << endl;
	cout << min_test(10.5, 12.5) << endl;
	cout << min_test('a', 'b') << endl;
	return 0;
}