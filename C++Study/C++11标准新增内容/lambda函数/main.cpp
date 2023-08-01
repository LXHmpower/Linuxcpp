#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int main()
{
    int b = 3 , c = 2;
    auto f1 = [=](int a) -> int {
        cout<<"b="<<b<<endl;
        cout<<"c="<<c<<endl;
       return a * a;       
    };

    auto f2 = [&]() -> void {
        b++;c++;
        cout<<"b="<<b<<endl;
        cout<<"c="<<c<<endl;
    };

    auto f3 = [=,&b]() -> void {
        b++; //c++； //报错
        cout<<"b="<<b<<endl;
    };
    cout<<f1(2)<<endl;
    f2();
    f3();
    cout<<endl;
    return 0;
}
