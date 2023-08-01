#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
class A 
{
    public:
        A()
        {
            cout<<"基类构造函数调用"<<endl;
        }
        virtual ~A()// 想要调用派生类的析构函数就把基类析构函数变成虚函数
        {
            cout<<"基类析构函数调用"<<endl;
        }
        virtual void func1(){
            cout<<"基类虚函数func1调用"<<endl;
        }
};
class B:public A 
{
    public:
        B()
        {
            cout<<"派生类构造函数调用"<<endl;
        }
        ~B()
        {
            cout<<"派生类析构函数调用"<<endl;
        }
        void func1()
        {
            cout<<"派生类func1函数调用"<<endl;
        }
};

int main()
{   
    B b;
    A *p_a = &b; 
    p_a->func1();
    A a;
    p_a = &a;
    p_a->func1();
    cout<<endl;
    A *aa = new B();
    delete aa;
    
    return 0;
}
