#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
#include<map>
using namespace std;

void print(map<int,string> &m)
{
    for(auto &val : m)
    {
        cout<<val.first<<"   "<<val.second<<endl;
    }
}
int main()
{
    map<int,string> m1 = {{1,"张三"},{2,"李四"},{3,"王五"}};
    print(m1);
    cout<<m1[2]<<" "<<m1[3]<<endl;
    m1[2] = "赵六";
    print(m1);
    cout<<endl;
    return 0;
}
