#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

/* C++将内联函数的代码组合到程序中，可以提高程序运行的速度。

语法：在函数声明和定义前加上关键字inline。

通常的做法是将函数声明和定义写在一起。

注意：

内联函数节省时间，但消耗内存。

如果函数过大，编译器可能不将其作为内联函数。

内联函数不能递归。 */
inline void func()
{
    cout<<"hello";
}
int main()
{
    func();
    cout<<endl;
    return 0;
}
