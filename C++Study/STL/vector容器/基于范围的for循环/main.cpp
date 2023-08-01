#include<iostream>
#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,5};
    for(auto val : v)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    for(auto val : {9,8,7,6,5,4,3,2,1})
    {
        cout<<val<<" ";
    }
    cout<<endl;


    return 0;
}
