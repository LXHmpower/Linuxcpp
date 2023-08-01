#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
template<typename T1,typename T2 = string>
class A
{
public:
    T1 m_a;
    T2 m_b;
    A(){}
    A(T1 a,T2 b): m_a(a),m_b(b){}
    void show()
    {
        cout<<"m_a:"<<m_a<<" "<<"m_b:"<<m_b<<endl;
    }
    void show_a();
};
template<typename T1,typename T2 >
  void A<T1,T2>::show_a()
{
    cout<<"show_a"<<endl;
}
int main()
{
    A<int ,string> *a1 = new A<int ,string>(1,"hello");
    a1->show();
    A <int> *a2 = new A<int>(2,"world");
    a2->show();
    a2->show_a();
    cout<<endl;
    return 0;
}
