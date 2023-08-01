#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

//函数重载就是函数名和函数返回值相同，函数形参不同
/* 在实际开发中，视需求重载各种数据类型，不要重载功能不同的函数。

注意：

使用重载函数时，如果数据类型不匹配，C++尝试使用类型转换与形参进行匹配，如果转换后有多个函数能匹配上，编译将报错。

引用可以作为函数重载的条件，但是，调用重载函数的时候，如果实参是变量，编译器将形参类型的本身和类型引用视为同一特征。

如果重载函数有默认参数，调用函数时，可能导致匹配失败。

const不能作为函数重载的特征。

返回值的数据类型不同不能作为函数重载的特征。

C++的名称修饰：编译时，对每个函数名进行加密，替换成不同名的函数。 */


void func()
{
    cout<<"hello"<<endl;
}
void func(int a)
{
    cout<<"hello"<<a<<endl;
}
void func(int a,int b)
{
    cout<<"hello"<<a<<b<<endl;
}
int main()
{
    func();
    func(1);
    func(2,3);
    cout<<endl;
    return 0;
}
