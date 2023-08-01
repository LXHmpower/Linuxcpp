#include<iostream>
#include<vector>
//#include<string>
#include<algorithm>

using namespace std;

template<typename T>
void test(const T& t)
{
    cout<<"hello :"<<t<<endl;
}

template<class T>
class Test
{
    public:
    void operator()(const T& t)
    {
         cout<<"hello :"<<t<<endl;
    }
};

template <typename T1 ,typename T2>
void foreach(const T1 first ,const T1 last ,T2 func)
{
        for(auto iter = first ;iter != last ;iter++)
        {
            func(*iter);
        }
}

int main()
{
    vector<int> v1 = {1,2,3,4,5}; 

    foreach(v1.begin(),v1.end(),test<int>);
    foreach(v1.begin(),v1.end(),Test<int>());
    for_each(v1.begin(),v1.end(),Test<int>());
    cout<<endl;
    return 0;
}
