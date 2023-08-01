#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
void func1(int *arr,int size)
{
     for(int i=0;i<size;i++)
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}
void func2(int arr[],int size)
{
 for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int num[5] = {1,2,3,4,5};
    int *p = num;//在多数情况下，C++将数组名解释为数组的第0个元素的地址，但是，将sizeof运算符用于数据名时，将返回整个数组占用内存空间的字节数。
                  //可以修改指针的值，但数组名是常量，不可修改。
    for(int i=0;i<5;i++)
    {
        cout<<*(p+i)<<" ";//p+i就是指针右移i个单位，类似于数组下标
    }
    cout<<endl;
    //一维数组函数传参 1.数组形式 func(int arr[]) 2. 指针形式 func(int *arr)
    /* void func1(int *arr,int size)
{
     for(int i=0;i<size;i++)
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}
void func2(int arr[],int size)
{
 for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
} */
    int test[] = {10,20,30,40,50};
    func1(test,sizeof(test)/sizeof(int));
    func2(test,sizeof(test)/sizeof(int));
    cout<<endl;
    return 0;
}
