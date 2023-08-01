#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

class A
{
public:
    int m_a = 9;
    A(){cout<<"A构造函数调用"<<endl;}
    ~A(){cout<<"A析构函数调用"<<endl;}
};
A getA()
{
    return A();
}

int main()
{
    int &&a = 3;//3是右值，用&&表示右值引用
    int b = 8;
    A &&aa = getA();//getA()返回一个匿名对象，本应该在语句执行完就终结，但是右值引用延长了对象的生命周期
    cout<<endl;
    return 0;
}
