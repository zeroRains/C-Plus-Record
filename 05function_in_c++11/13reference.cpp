#include <bits/stdc++.h>

using namespace std;


int main()
{
	int x = 0;
	int *p = &x; // 这个是指针指向x
	int &r = x;	 // r就代表x，x所在内存空间，r表示的部分也是x所在内存空间
	// 需要注意的是，指针可以修改其指向其他变量，但是r只能指向x了，不可以指向其他变量了
	int x2 = 5;

	r = x2; // r已经定义了，这时候，让r=x2，也就等价于同时运行x=x2，因为r就表示x，r不能被重新修改成x2的引用了
	// 这时候x,r,x2的值都相等，为5 
	cout << "x: " << x << endl;
	cout << "r: " << r << endl;
	cout << "x2: " << x2 << endl;

	int &r2 = r; // 这时候和r2是引用类型，然后他表示r，但是r表示x，所以r2也表示x
	//这时候修改r2的值，x,r也会跟诊修改
	r2 = 100;
	cout << endl;
	cout << "x: " << x << endl;
	cout << "r: " << r << endl;
	cout << "r2: " << r2 << endl;
	// reference 常用于参数传递的变量声明
	// 返回值也可以使用reference
	// 如果是打算使用reference实现函数重载，那就不能并存，因为调用端需要输入的参数相同，则不知道应该调用哪个
	// 存在歧义
	return 0;
}