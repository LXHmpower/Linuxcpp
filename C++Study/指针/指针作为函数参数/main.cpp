#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

void func1(int *a , int *b)//通过指针传参可修改实参(地址传递)
{
    *a = 1;
    *b = 2;

}

int main()
{
    int x = 3 ;
    int y = 3;
    cout<<"修改前："<<x<<" "<<y<<endl;
    func1(&x,&y);//注意传参的参数是地址
    cout<<"修改后："<<x<<" "<<y<<endl;
    return 0;

}
