#include <iostream>
#include "string.h"
using namespace std;

int main()
{
	String s1("init");
	String s2("hello");
	String s3(s1);
	cout << s3 << endl;
	s3 = s2;
	cout << s3 << endl;
	return 0;
}
/*
函数创建的过程中会形成一个栈，新生成的变量会存入栈中，函数结束时逐一清除。
函数中创建的对象是局部对象，或者称为自动对象，当函数运行结束时会自动清除。

但是如果是使用new的方法（指针方法）创建的对象呢，则会在堆中生成一个新的空间，需要手动进行清除。
一般清理堆中的内存空间就是调用类的析构函数进行处理。

在函数中创建的变量，如果使用static进行标记，那么，这个作用域就是整个程序的生命周期，在程序结束之前都是存活的。
全局对象，就是在main函数外部定义的对象，可以视为static object，作用域也是整个程序

new操作是先分配内存，再调用构造函数的
delete操作先调用析构函数，再释放内存 

array new一定要搭配array delete
new String[]
delete[] p; // 可以调用数组中的所有析构函数，如果不写中括号，那么只调用指针指向的析构函数 

static在数据前面或者在函数前面，就会变成静态变量或静态函数

namespace 将东西包装在一个单元里面

*/