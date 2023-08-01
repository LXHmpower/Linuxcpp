#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int main()
{
    int *p = new int(3);
    cout<<*p<<endl;
    delete p;
    p = nullptr;
    cout<<endl;
    return 0;
}
