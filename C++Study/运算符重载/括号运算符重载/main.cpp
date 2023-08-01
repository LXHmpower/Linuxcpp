#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

void show()
{
    cout<<"普通函数调用"<<endl;
}
class Example
{
   public:
    void operator()()
{
    cout<<"重载函数调用"<<endl;
} 
};
int main()
{
    Example ex;
    ex();
    Example show;
    ::show();//调用普通函数
    show();
    cout<<endl;
    return 0;
}
