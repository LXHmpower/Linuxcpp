#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int main()
{
    int x = 1;
    int y = 2;
    
    const int *cst_pointer1 = &x;
    cout<<"cst_pointer1 = "<<cst_pointer1<<" "; 
    cout<<"*cst_pointer1 = "<<*cst_pointer1<<endl;
    cst_pointer1 = &y;//const int * 可以修改指针指向的变量
    //*cst_pointer1 = 4;     //const int *不可修改指向变量的值 ，此语句报错  
    cout<<"cst_pointer1 = "<<cst_pointer1<<" "; 
    cout<<"*cst_pointer1 = "<<*cst_pointer1<<endl;

     
     int*  const cst_pointer2 = &y;
    cout<<"cst_pointer2 = "<<cst_pointer2<<" "; 
    cout<<"*cst_pointer2 = "<<*cst_pointer2<<endl;
    //cst_pointer2 = &y;//int* const 不可以修改指针指向的变量,此语句报错
    *cst_pointer2 = 4;     //int* const 可修改指向变量的值 
    cout<<"cst_pointer1 = "<<cst_pointer2<<" "; 
    cout<<"*cst_pointer1 = "<<*cst_pointer2<<endl;
    cout<<endl;
    return 0;
    cout<<endl;
    return 0;
}

