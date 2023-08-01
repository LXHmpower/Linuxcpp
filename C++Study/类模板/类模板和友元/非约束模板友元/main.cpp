#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

// 非类模板约束的友元函数，实例化后，每个函数都是每个每个类的友元。
template<class T1, class T2>
class AA    
{
    template <typename T> friend void show(T& a);     // 把函数模板设置为友元。
    T1 m_x;
    T2 m_y;
public:
    AA(const T1 x, const T2 y) : m_x(x), m_y(y) { }
};

template <typename T> void show(T& a)                     // 通用的函数模板。
{
    cout << "通用：x = " << a.m_x << ", y = " << a.m_y << endl;
}

template <>void show(AA<int, string>& a)                 // 函数模板的具体版本。
{
    cout << "具体<int, string>：x = " << a.m_x << ", y = " << a.m_y << endl;
}

int main()
{
    AA<int, string> a(88, "abcd");
    show(a);         // 将使用具体化的版本。

    AA<char, string> b(88, "abcd");
    show(b);        // 将使用通用的版本。
}