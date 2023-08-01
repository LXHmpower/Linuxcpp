#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
class A
{
    public:
        int A_a;
        virtual void func() = 0;
};
class B:public A{
    public:
        int B_a;   
};

int main()
{
    A *a = nullptr;
    B *b = (B*)a;//c风格指针类型转换，不安全
    B *b1 = dynamic_cast<B*>(a);//c++风格使用dynamic_cast运算符实现指针类型转换，确保指针类型能安全转换
    //注意:dynamic_cast运算符要求必须是多态类型
    cout<<endl;
    return 0;
}
