#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

// 约束模板友元：模板类实例化时，每个实例化的类对应一个友元函数。
template <typename T>
void show(T& a);                                                 // 第一步：在模板类的定义前面，声明友元函数模板。

template<class T1, class T2>
class AA    // 模板类AA。
{
    friend void show<>(AA<T1, T2>& a);          // 第二步：在模板类中，再次声明友元函数模板。
    T1 m_x;
    T2 m_y;

public:

    AA(const T1 x, const T2 y) : m_x(x), m_y(y) { }
};

template<class T1, class T2>
class BB    // 模板类BB。
{
    friend void show<>(BB<T1, T2>& a);          // 第二步：在模板类中，再次声明友元函数模板。
    T1 m_x;
    T2 m_y;

public:

    BB(const T1 x, const T2 y) : m_x(x), m_y(y) { }
};

template <typename T>                                 // 第三步：友元函数模板的定义。
void show(T& a)
{
    cout << "通用：x = " << a.m_x << ", y = " << a.m_y << endl;
}

template <>                                                    // 第三步：具体化版本。
void show(AA<int, string>& a)
{
    cout << "具体AA<int, string>：x = " << a.m_x << ", y = " << a.m_y << endl;
}

template <>                                                    // 第三步：具体化版本。
void show(BB<int, string>& a)
{
    cout << "具体BB<int, string>：x = " << a.m_x << ", y = " << a.m_y << endl;
}

int main()
{
    AA<int, string> a1(88, "我是一只傻傻鸟。");
    show(a1);         // 将使用具体化的版本。

    AA<char, string> a2(88, "我是一只傻傻鸟。");
    show(a2);        // 将使用通用的版本。

    BB<int, string> b1(88, "我是一只傻傻鸟。");
    show(b1);         // 将使用具体化的版本。

    BB<char, string> b2(88, "我是一只傻傻鸟。");
    show(b2);        // 将使用通用的版本。
}