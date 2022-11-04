#include <bits/stdc++.h>

// 像指针的类，智能指针
template <class T>
class shared_ptr
{
public:
	// 指针的两个操作
	T &operator*() const { return *px; }
	T *operator->() const { return px; }
	shared_ptr(T *p) : px(p) {}

private:
	T *px;
	long *pn;
};

class Foo
{
public:
	void method()
	{
		std::cout << "233" << std::endl;
	}
};


// 迭代器


int main()
{
	shared_ptr<Foo> sp(new Foo);
	Foo f(*sp);
	sp->method(); // 智能指针记录Foo的指针到px中
	// 上面这一行类似于 px->method()
	return 0;
}