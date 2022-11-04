#include <bits/stdc++.h>

using namespace std;

/*

下面定义了三个继承关系的类
对于B来说：
变量：在A含有的1和2之下，多添加了一个3，也就是B有1,2,3三个变量
虚函数

对于C来说：
变量：在B含有的1,2,3之下，C中定义了1,4，所以B中的1会被C中的1取代（如果想调用B从A继承来的1的话，需要用类似于java的super，进行父属性调用），然后含有B中的2,3，和新增的4，即包含变量1,2,3,4

类中不管有多少个虚函数，都只有一个指针(虚指针，vptr)，指向一个函数对应地址的列表头(vtbl)
如果是在子类中定义的虚函数与父类中的虚函数同名，则子类虚函数的地址与父类虚函数的地址不同，每个类内的函数都是占用不同的空间的
但是如果是在父类中定义的虚函数，但是子类中没有定义虚函数，那么子类也会集成这个虚函数，继承的虚函数与父类的虚函数地址相同。

面的例子中涉及到的函数可以写为：
A::vfun1()
A::vfun2()
B::vfun1()
C::vfun1()

A::fun1()
A::fun2()
B::fun1()
C::fun2()

符合动态绑定函数地址的条件：指针调用，指针向上转型，调用的是虚函数（也称虚机制）
静态绑定一定会调用固定的地址，动态绑定要看具体执行哪个函数。

多态：上转型指针调用的函数，可以有不同的实现(根据上转的子类中定义的函数不同，产生不同的实现)

const相关

const member function可以被const object和non-const object函数调用
non-const member fucntion只能被non-const object函数调用

当成员函数的const和non-const版本同时存在时，const object只能调用const版本，non-const object只能调用non-const版本

::operator new, ::operator delete, ::operator new[]，::operator delete[]
上面这四个函数是可以重载的，主要就是使用底层的malloc和free，重载之后可以写上一些自己的操作
但是new和delete是不可以重载的，因为new和delete是表达式而不是函数。
但是在重载这些操作的适合，要注意，这些东西都是无远无界的。
还要注意的是上面所重载的方法是不能写在namespace里面的

成员 operator new/delete 和new[]/delete[]也是可以重载的。
如果一定要使用系统原本的new和delete，而不是调用在类内重载的new和delete，则可以使用::new和::delete直接强制指定使用系统内部的对应函数




*/

class A
{
public:
	virtual void vfun1();
	virtual void vfun2();
	void func1();
	void func2();
	// 加const和不加const的函数定义是可以重载的，也就是说除了参数那部分是函数签名的一部分外，连const那部分也是函数签名的一部分
	A operator[](A &a) const {};
	A operator[](A &a){};

private:
	int m_data1, m_data2;
};

class B : public A
{
public:
	virtual void vfun1();
	void func2();

private:
	int m_data3;
};

class C : public B
{
public:
	virtual void vfunc1();
	void func2();

private:
	int m_data1, m_data4;
};

int main()
{

	return 0;
}