#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
void test(int a)
{
    cout<<"this is a test "<<a<<endl;
}

void func()
{ 
    cout<<"这是func函数"<<endl;
}
void FUNC_TEST(void (*test)())
{
    cout<<"start"<<endl;
    test();
    cout<<"end"<<endl;
}
int main()
{
     void (*TEST)(int);//定义函数指针
     TEST = test;//给函数指针赋值
     TEST(1);//使用函数指针调用函数

     //函数指针应用场景：回调函数 ，可以理解为将函数作为作为另一个函数的参数传入
     /*
     void func()
{ 
    cout<<"这是func函数"<<endl;
}
void FUNC_TEST(void (*test)())
{
    cout<<"start"<<endl;
    test();
    cout<<"end"<<endl;
}
     */
     FUNC_TEST(func);
    cout<<endl;
    return 0;
}
