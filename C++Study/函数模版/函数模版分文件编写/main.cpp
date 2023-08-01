#include<iostream>
#include"test.h"
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int main()
{
    test(1,2);
    test<>(1,2);
    test('1','2');
    cout<<endl;
    return 0;
}
