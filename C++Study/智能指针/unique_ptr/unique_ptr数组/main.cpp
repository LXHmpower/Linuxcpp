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
    A(){cout<<"调用构造函数 "<<endl;}
    A(int a):m_a(a){cout<<"调用构造函数 "<<endl;}
    ~A(){cout<<"调用析构函数 "<<endl;}
};
int main()
{
    unique_ptr<A[]> p(new A[2]);
    p[0].m_a = 1;
    cout<<p[0].m_a<<endl;
    p[1].m_a = 2;
    cout<<p[1].m_a<<endl;

    cout<<endl;
    return 0;
}
