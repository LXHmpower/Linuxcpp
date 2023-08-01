#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

template<class T1, class T2>
class AA    // 模板类AA。
{
public:
    T1 m_x;
    T2 m_y;
    AA(const T1 x, const T2 y) : m_x(x), m_y(y) { }
    void show() const { cout << "show()  x = " << m_x << ", y = " << m_y << endl; }
};

// 采用普通函数，参数和返回值是模板类AA的实例化版本。
AA<int, string> func(AA<int, string>& aa)
{
    aa.show();
    cout << "调用了func(AA<int, string> &aa)函数。\n";
    return aa;
}

// 函数模板，参数和返回值是的模板类AA。
template <typename T1,typename T2>
AA<T1, T2> func(AA<T1, T2>& aa)
{
    aa.show();
    cout << "调用了func(AA<T1, T2> &aa)函数。\n";
    return aa;
}

// 函数模板，参数和返回值是任意类型。
template <typename T>
T func(T &aa)
{
    aa.show();
    cout << "调用了func(AA<T> &aa)函数。\n";
    return aa;
}

int main()
{
    AA<int, string> aa(3, "abcd");
    func(aa);
}