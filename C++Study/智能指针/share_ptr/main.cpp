#include<iostream>
#include<memory>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

class A
{
public:
    int m_a;
    A(int a):m_a(a){cout<<"调用构造函数 "<<m_a<<endl;}
    ~A(){cout<<"调用构造函数 "<<m_a<<endl;}
};

void func(shared_ptr<A> &p)
{
   cout<<p.get()<<endl;
}
int main()
{
    shared_ptr<A> p1(new A(10));
    cout<<p1<<endl;
    cout<<p1.get()<<endl;
    func(p1);
    cout<<endl;
    return 0;
}
 