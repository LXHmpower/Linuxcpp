#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

template<class T1, class T2>
class AA    
{
    T1 m_x;
    T2 m_y;
public:
    AA(const T1 x, const T2 y) : m_x(x), m_y(y) { }
    // 非模板友元：友元函数不是模板函数，而是利用模板类参数生成的函数，只能在类内实现。
    friend void show(const AA<T1, T2>& a)
    {
        cout << "x = " << a.m_x << ", y = " << a.m_y << endl;
    }
   /* friend void show(const AA<int, string>& a);
    friend void show(const AA<char, string>& a);*/
};

//void show(const AA<int, string>& a)
//{
//    cout << "x = " << a.m_x << ", y = " << a.m_y << endl;
//}
//
//void show(const AA<char, string>& a)
//{
//    cout << "x = " << a.m_x << ", y = " << a.m_y << endl;
//}

int main()
{
    AA<int, string> a(88,"abcd");
    show(a);

    AA<char, string> b(88, "abcd");
    show(b);
}