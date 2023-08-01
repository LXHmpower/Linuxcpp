#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

void func(int **s)
{
        *s = new int(10);
}

int main()
{
    int i=1;
    int *pi = &i;
    int **pii = &pi;//二级指针是存放一级指针的地址
    cout<<"pi  = "<<pi<<",  *pi = "<<*pi<<endl;
    cout<<"pii = "<<pii<<", *pii = "<<*pii<<endl;
    cout<<"**pii = "<<**pii<<endl;
    
    //二级指针应用场景：完成一个函数，功能是给指针分配内存，此时 二级指针作为函数参数传入(相当于传入指针变量的地址)
    //解释一下：要想在函数中修改实参的值，只能通过地址传递，而实参是个指针，所以传入参数应该是指针的地址，即为二级指针
    /*void func(int *s)
    {
        int **ss = &s;
        *ss = new int(10);
    }
    */
   int *p = nullptr;
    func(&p);
    cout<<"p  = "<<p<<",  *p = "<<*p<<endl;
 
    cout<<endl;
    return 0;
}
