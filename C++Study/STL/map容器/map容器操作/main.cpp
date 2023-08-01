#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
#include<map>
using namespace std;
class Person
{
public:
    string p_name;
    int p_age;
    Person(){cout<<"调用了无参构造函数。\n";}
    Person(int age,string name):p_age(age),p_name(name){cout<<"调用了两个参数构造函数。\n";}
    Person(const Person &p):p_age(p.p_age),p_name(p.p_name){cout<<"调用了拷贝构造函数。\n";}
    ~Person(){cout<<"调用了析构函数。\n";}
};
template<typename T1,typename T2>
void print(map<T1,T2> &m)
{
    for(auto &val : m)
    {
        cout<<val.first<<"   "<<val.second<<endl;
    }
}
int main()
{
    map<int,string> m1 = {{1,"张三"},{2,"李四"},{3,"王五"}};
   
    m1.erase(2);
    print<int,string>(m1);
    
    m1.insert({2,"李四"});
    //m1.insert(make_pair(2,"李四"));
    //m1.insert(pair<int,string>(2,"李四"));
     print<int,string>(m1);
   
    auto ret = m1.insert(pair<int,string>(4,"赵六"));
    if (ret.second == true) cout << "插入成功：" << ret.first->first << "," << ret.first->second << endl;
	else cout << "插入失败。\n";
     print<int,string>(m1);
   
    auto ret1 = m1.emplace(20, "sdf");
	if (ret1.second == true) cout << "插入成功：" << ret1.first->first << "," << ret1.first->second << endl;
	else cout << "插入失败。\n";
     print<int,string>(m1);
    // 5）iterator emplace_hint(const_iterator pos, ...); 
	// 功能与上个函数相同，第一个参数提示插入位置，该参数只有参考意义，如果提示的位置是正确的，
	// 对性能有提升，如果提示的位置不正确，性能反而略有下降，但是，插入是否成功与该参数元关。
	// 该参数常用end()和begin()。成功返回新插入元素的迭代器；如果元素已经存在，则插入失败，返回现
	// 有元素的迭代器。
    m1.emplace_hint(m1.begin(),piecewise_construct,forward_as_tuple(8),forward_as_tuple("wefw") );
     print<int,string>(m1);
    
    map<int,Person> m2;
    m2.insert(pair<int,Person>(1,Person(18,"张三")));
    m2.insert(pair<int,Person>(2,Person(20,"李四")));
    m2.insert(pair<int,Person>(3,Person(16,"王五")));
    cout<<"start\n";
    //m2.emplace(8,Person(22,"赵六"));
    m2.emplace_hint(m2.begin(),piecewise_construct,forward_as_tuple(8),forward_as_tuple(22,"wefw") );
    cout<<"end\n";
    for (const auto& val : m2)
		cout << val.first << "," << val.second.p_age << "," << val.second.p_name << "  ";
	cout << endl;
    cout<<endl;
    return 0;
}
