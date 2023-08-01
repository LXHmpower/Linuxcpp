#include <iostream>
#include <vector>
using  namespace std;

class AA
{
public:
	int m_bh;               // 编号。
	string m_name;     // 姓名。

	AA()      // 默认构造函数。
	{ 
		cout << "默认构造函数AA()。\n"; 
	}

	AA(const int &bh,const string& name) : m_bh(bh),m_name(name)   // 有两个参数的构造函数。
	{
		cout << "构造函数，name=" << m_name << "。\n"; 
	}

	AA(const AA& g) :m_bh(g.m_bh), m_name(g.m_name)                       // 拷贝构造函数。
	{ 
		cout << "拷贝构造函数，name=" << m_name << "。\n"; 
	}

	~AA() { cout << "析构函数。\n"; }
};

int main()
{
	vector<AA> v;
	
	cout << v.size() << v.data() << endl;
	
	//AA a(18,"张三"); 
	//v.push_back(a);
	//v.emplace_back(a);
	v.emplace_back(18,"张三");

	cout << "bh=" << v[0].m_bh << ",name=" << v[0].m_name << endl;
}