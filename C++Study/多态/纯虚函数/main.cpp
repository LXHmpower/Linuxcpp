#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
class A
{
    public:
        virtual void func1()=0;
};
class B:public A{
    public:
        void func1(){
            cout<<"派生类func1函数调用"<<endl;
        }
};
int main()
{
    //A a;//抽象类不能实例化
    A *a = new B();
    a->func1();
    cout<<endl;
    return 0;
}
