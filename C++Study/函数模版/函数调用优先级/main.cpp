#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
void test(int a,int b){
    cout<<"普通函数"<<endl;
}
template<typename T>
void test(T a,T b){
    cout<<"函数模版"<<endl;
}
template<>
void test<int>(int a,int b){
    cout<<"函数模版具体化"<<endl;
}

int main()
{
    test(1,2);
    test<>(1,2);
    test('1','2');
    cout<<endl;
    return 0;
}
