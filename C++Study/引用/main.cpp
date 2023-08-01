#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
void func1(int **p)
{
    *p = new int(3);
    cout<<**p<<endl;
}
void func2(int *&p)//和func1对比，引用作为参数时可以避免使用二级指针
{
    p = new int(3);
     cout<<*p<<endl;
}

int &func3(int &s)//引用作为函数返回值可以返回函数形参的值
{
    s++;
    return s;
}

int main()
{
    int a = 3;
    int &ra = a;//引用可以给变量起别名
    cout<<"ra = "<<ra<<endl;
    cout<<"a = "<<a<<endl;

    //引用的本质是指针常量 ：数据类型 *const 指针变量
    // int& b = 8;  这段代码报错，8是常量，不能使用引用
    const int&b  = 8;//这段代码正确，原因是在C++中，const int&会被C++经过特殊处理，C++会创建临时变量，让引用指向这个变量
    //等同于以下代码
    /*
    int tmp = 8;
    int &a = tmp;
    */
   int *p;
   func1(&p);
   func2(p);
    int t = func3(a);
    cout<<t<<endl;
    cout<<endl;
    return 0;
}
