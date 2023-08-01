#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

template<typename T>
void add(T a,T b){
    T c = a+b;
    cout<<"add = "<<c<<endl;
}
class A
{
    public:
        template<typename T>
         A(T a)
         {
           cout<<a<<endl; 
         }
         template<typename T>
        void test(T a,T b)
        {
            cout<<a+b<<endl;
            cout<<"函数模版"<<endl;
        }
        template<>
        void test<int>(int a,int b)
        {
            cout<<a+b<<endl;
            cout<<"函数模版具体化"<<endl;
        }



};
int main()
{
    add('1','2');
    A a("hello");
    A aa(1234);
    a.test(1,2);
    a.test('1','2');
    cout<<endl;
    return 0;
}
