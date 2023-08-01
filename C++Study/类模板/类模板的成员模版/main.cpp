#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

template <class T1 , class T2>
class A
{
public:
    T1 m_a;
    T2 m_b;
    A(const T1 a ,const T2 b):m_a(a),m_b(b){}
    void show() { cout << "m_a=" << m_a << "，m_b=" << m_b << endl; }

    template<class T>
    class B
    {
        public:
         T m_a ;
         T1 m_b;
         B(){}
         void show();
         
    };

    B<string>m_bb;
   
    template<typename T>
        void show(T tt);

};

template <class T1 , class T2>
template<class T>
void A<T1,T2>::show(T tt)
{
    cout << "tt=" << tt << endl;
    cout << "m_a=" << m_a << "，m_b=" << m_b<< endl;
    m_bb.show();
}

template <class T1 , class T2>
template<class T>
void A<T1,T2>::B<T>::show()
{
    cout << "m_a=" << m_a << "，m_b=" << m_b << endl; 
}




int main()
{
    A<int, string> a(88, "abcd");
    a.show();
    a.m_bb.m_a = "1243";
    a.m_bb.show();
    a.show("qwer");
    cout<<endl;
    return 0;
}
