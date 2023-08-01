#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

class A
{
    public:
        int m_a;
    A() = default;
    A(int a){m_a = a; cout<<"有参构造函数"<<endl;}
    A(const A& a) = delete;
    ~A(){cout<<"析构函数"<<endl;}
};
int main()
{
    A a1(1);
    //A a2 = a1; //报错，用=delete删除了拷贝构造函数
    cout<<endl;
    return 0;
}
