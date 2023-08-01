#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

template<class T1, class T2>
class BB      // 模板类BB。
{
public:
	T1 m_x;
	T2 m_y;
	BB(const T1 x, const T2 y) : m_x(x), m_y(y) { cout << "调用了BB的构造函数。\n"; }
	void func2() const { cout << "调用了func2()函数：x = " << m_x << ", y = " << m_y << endl; }
};

template<class T1, class T2>
class AA:public BB<T1,T2>     // 普通类AA变成了模板类，才能继承模板类。
{
public:
	int m_a;
	AA(int a, const T1 x, const T2 y) : BB<T1,T2>(x,y),m_a(a) { cout << "调用了AA的构造函数。\n"; }
	void func1() { cout << "调用了func1()函数：m_a=" << m_a << endl;; }
};

template<class T, class T1, class T2>
class CC :public BB<T1, T2>   // 模板类继承模板类。
{
public:
	T m_a;
	CC(const T a, const T1 x, const T2 y) : BB<T1, T2>(x, y), m_a(a) { cout << "调用了CC的构造函数。\n"; }
	void func3() { cout << "调用了func3()函数：m_a=" << m_a << endl;; }
};

int main()
{
	CC<int,int,string> cc(3,8, "abcd");
	cc.func3();
	cc.func2();
}
