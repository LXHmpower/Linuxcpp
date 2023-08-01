#include<iostream>
#include<vector>
//#include<string>
#include<algorithm>

using namespace std;

template<typename T>
bool test(const T& t)
{
    if(t != 9) return false;
    cout<<"hello :"<<t<<endl;
    return true;
}

template<class T>
class Test
{
    public:
        T m_x;
        Test(const T& x):m_x(x){}
    bool operator()(const T& t)
    {
        if(t != m_x) return false;
         cout<<"hello :"<<t<<endl;
         return true;
    }
};

template <typename T1 ,typename T2>
T1 foreach(const T1 first ,const T1 last ,T2 func)
{
        for(auto iter = first ;iter != last ;iter++)
        {
            if(func(*iter) == true) return iter;
            return last;
        }
}

int main()
{
    vector<int> v = {1,2,3,4,5}; 

    auto it1=find_if(v.begin(), v.end(), test<int>);  // 第三个参数是模板函数。
	if (it1 == v.end()) cout << "查找失败。\n";
	else cout << "查找成功：" << *it1 << endl;

	auto it2=find_if(v.begin(), v.end(), Test<int>(5));       // 第三个参数是仿函数。
	if (it2 == v.end()) cout << "查找失败。\n";
	else cout << "查找成功：" << *it2 << endl;

    find_if(v.begin(), v.end(), Test<int>(5));
    cout<<endl;
    return 0;
}
