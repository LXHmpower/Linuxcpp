#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int compare_little(const void *p1,const void *p2)//升序
{
    return *((int*)p1) - *((int*)p2);
}
int compare_big(const void *p1,const void *p2)//降序
{
    return *((int*)p2) - *((int*)p1);
}

int main()
{
    /*
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

第一个参数：数组的起始地址。

第二个参数：数组元素的个数（数组长度）。

第三个参数：数组元素的大小（sizeof(数组的数据类型)）。

第四个参数：回调函数的地址。

回调函数决定了排序的顺序，声明如下：

int compar(const void *p1, const void *p2);

1）如果函数的返回值< 0 ，那么p1所指向元素会被排在p2所指向元素的前面。

2）如果函数的返回值==0，那么p1所指向元素与p2所指向元素的顺序不确定。

3）如果函数的返回值> 0 ，那么p1所指向元素会被排在p2所指向元素的后面。

 

 void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

qsort()函数的其它细节：

形参中的地址用void是为了支持任意数据类型，在回调函数中必须具体化。

为什么需要第三个形参size_t size？

size_t是C标准库中定义的，在64位系统中是8字节无符号整型（unsigned long long）。

typedef unsigned long long size_t

排序的需求除了升序和降序，还有很多不可预知的情况，只能用回调函数。

    */
   int a[] = {3,2,1,4,5,9,7,8,6};
   qsort(a,sizeof(a)/sizeof(int),sizeof(int),compare_little);
   for(int i=0;i<sizeof(a)/sizeof(int);i++)
   {
        cout<<"a["<<i<<"]"<<" = "<<a[i]<<endl;
   }
   cout<<endl;
   qsort(a,sizeof(a)/sizeof(int),sizeof(int),compare_big);
   for(int i=0;i<sizeof(a)/sizeof(int);i++)
   {
        cout<<"a["<<i<<"]"<<" = "<<a[i]<<endl;
   }
    cout<<endl;
    return 0;
}
