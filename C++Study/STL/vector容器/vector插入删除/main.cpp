#include<iostream>
#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;


void print(vector<int> V)//使用迭代器循环输出元素
{
    for(auto it = V.cbegin(); it != V.cend();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
   /*  for(vector<int>::iterator it = V.begin(); it != V.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl; */
}
int main()
{
    vector<int>v1 = {1,2,3,4,5,6,7,8,9};
    v1.push_back(10);
    for(auto val : v1)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    v1.pop_back();
    for(auto val : v1)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    vector<int>::iterator it1 = v1.begin();
    v1.insert(it1+2,100);
    for(auto val : v1)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    vector<int>::iterator it2 = v1.begin();
    v1.erase(it2+2);
    for(auto val : v1)
    {
        cout<<val<<" ";
    }
     cout<<endl;
    print(v1);
    cout<<endl;
    return 0;
}
