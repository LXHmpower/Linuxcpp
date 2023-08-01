#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

void func(int a=1,string c = "1",int e = 10)
{
    cout<<"a = "<<a<<" "<<"c = "<<c<<" "<<"e = "<<e<<endl;
}
/* void test(int a=1,string c ,int e = 10)
{
    cout<<"a = "<<a<<" "<<"c = "<<c<<" "<<"e = "<<e<<endl;
} */
//以上代码编译时报错，在给定缺省值的时候如果一个变量有缺省值，那么他后面的所有变量必须得有缺省值
int main()
{
    func(2,"2",2);//有缺省值，调用函数可以不填参数，但是如果调用时填了某一变量的值，那么他前面的参数必须填写。
    //如：
    //func(1,1);填了a 和 e的值，c想用缺省值，不行会报错

    cout<<endl;
    return 0;
}
