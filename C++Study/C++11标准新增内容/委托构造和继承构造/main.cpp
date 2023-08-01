#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

class A
{
public:
    int m_a;
    int m_b;
    A(int a):m_a(a){cout<<"A一个参数构造函数调用"<<endl;}    
    A(int a,int b):m_a(a),m_b(b){ cout<<"A两个参数构造函数调用"<<endl;}
    A(int a,int b,const string &str):A(a,b){//委托构造
        cout<<"m_a = "<<m_a<<" m_b = "<<m_b<<"str="<<str<<endl;
    }
     A(int a,const string &str):A(a){//委托构造
        cout<<"m_a = "<<m_a<<"str="<<str<<endl;
    }
};

class B :public A{

public:
    int _m_c;
    using A::A;//继承构造
    B(int a,int b,int c):A(a,b),_m_c(c){
        cout<<"B一个参数构造函数调用"<<endl;
    }
};

int main()
{
    A a1(1);
    A a2(1,2);
    A a3(1,2,"hello");
    A a4(1,"hello");
    
    B b1(1);
    B b2(2,3,"hello");
    B b3(1,2,3);

    cout<<endl;
    return 0;
}
