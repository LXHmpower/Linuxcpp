#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
class A
{
    public:
        int A_a ;
        int A_b;
        A(int a,int b):A_a(a),A_b(b){}
        void show()
        {
            cout<< "A_a:"<<A_a<<endl;
            cout<< "A_b:"<<A_b<<endl;
        }
    protected:
        char A_c = 'C';
    private:
        int A_d = 3;
        void show_d()
        {
            cout<< "A_d:"<<A_d<<endl;
        }

};
class B : public A
{
    public:
        int B_a ;
        B(int a,int b,int c):A(b,c),B_a(a){}
        void show()
        {
            cout<< "B_a:"<<B_a<<endl;
        }
        using A::A_c;
       // using A::A_d;//private关键字修饰的成员不能被using更改权限
    private:
        using A::A_b;
};
class  C:public B
{
    public:
        void show()
        {
            cout<<A_c<<endl;
        }    
};

int main()
{
    A aa(1,2);
    cout<<"A_a:"<<aa.A_a<<endl;
    cout<<"A_b:"<<aa.A_b<<endl;
    aa.show();
    B bb(1,2,3);
    cout<<"B_a:"<<bb.B_a<<endl;
    //cout<<"A_b:"<<bb.A_b<<endl;//子类可通过using 类名::成员来更改基类非私有成员变量的权限
    bb.show();
    cout<<"bb.A::A_a:"<<bb.A::A_a<<endl;//子类通过 基类::成员名来调用父类的成员
    return 0;
}
