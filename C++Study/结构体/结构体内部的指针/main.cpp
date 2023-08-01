#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

struct S{
 int a ;
 int *p;
};
int main()
{
    S s;
    memset(&s,0,sizeof(s));
    s.a = 3;
    s.p = new int[100];
    cout<<"a = "<<s.a<<" "<<"s.p = "<<s.p<<endl;
    s.p = new int[100];
   // memset(&s,0,sizeof(s));在结构体内部指针动态内存分配之之后使用memset对结构体清空会造成内存泄露和空指针，注意！！！！！，如需在动态内存分配之之后使用memset，请分开处理
    cout<<"a = "<<s.a<<" "<<"s.p = "<<s.p;
    cout<<endl;
    return 0;
}
