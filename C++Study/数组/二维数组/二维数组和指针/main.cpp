#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

//行指针（数组指针）(指向二维数组一行的一维数组的指针)：数据类型 (*p)[列数]
void func(int(*p)[3],int line_size)//行指针用于二维数组的函数传参
{
    for(int i=0;i<line_size;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<*(*(p+i)+j) <<" ";
        }
        cout<<endl;
    }
}
void test(int arr[][3],int line_size)//普通二维数组作为函数参数传参
{
    for(int i=0;i<line_size;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int num[2][3] = {1,2,3,4,5,6};
    func(num,2);
    test(num,2);
    cout<<endl;
    return 0;
}
