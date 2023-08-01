#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

class AA     // 普通类AA。
{
public:
	int m_a;
	AA(int a) :m_a(a) { cout << "调用了AA的构造函数。\n"; }
	void func1() { cout << "调用了func1()函数：m_a=" << m_a << endl;; }
};

template<class T1, class T2>
class BB:public AA      // 模板类BB。
{
public:
	T1 m_x;
	T2 m_y;
	BB(const T1 x, const T2 y,int a) : AA(a) , m_x(x), m_y(y) { cout << "调用了BB的构造函数。\n"; }
	void func2() const { cout << "调用了func2()函数：x = " << m_x << ", y = " << m_y << endl; }
};

int main()
{
	BB<int, string> bb(8, "abcd",3);
	bb.func2();
	bb.func1();
}