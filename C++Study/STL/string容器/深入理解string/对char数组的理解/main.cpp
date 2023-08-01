#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int main()
{
    char str[8];

    int *a = (int *)str;
    *a = 1234;
    int *b = (int *)str+4; 
    *b = 5678; 
    cout<<"*a="<<*a<<endl; 
    cout<<"*b="<<*b<<endl;   
    
    cout<<endl;
    return 0;
}
