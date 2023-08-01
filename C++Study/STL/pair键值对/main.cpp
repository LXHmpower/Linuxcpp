#include <iostream>
using  namespace std;

template <class T1, class T2>
struct Pair
{
	T1 first;        // 第一个成员，一般表示key。
	T2 second;  // 第二个成员，一般表示value。
	Pair()  {
		cout << "调用了有默认的构造函数。\n";
	}
	Pair(const T1& val1, const T2& val2) :first(val1), second(val2)  {
		cout << "调用了有两个参数的构造函数。\n";
	}
	Pair(const Pair<T1, T2>& p) : first(p.first),second(p.second)  {
		cout << "调用了拷贝构造函数。\n";
	}
};

template <class T1, class T2>
Pair<T1, T2> make_Pair(const T1& first, const T2& second)
{
	// Pair<T1, T2> p(first, second);
	// return p;        // 返回局部对象。
	return Pair<T1, T2>(first, second);  // 返回临时对象。
}

int main()
{
	//pair<int, string> p0;
	//cout << "p0 first=" << p0.first << ",second=" << p0.second << endl;

	//pair<int, string> p1(1, "西施1");    // 两个参数的构造函数。
	//cout << "p1 first=" << p1.first << ",second=" << p1.second << endl;

	//pair<int, string> p2 = p1;             // 拷贝构造。
	//cout << "p2 first=" << p2.first << ",second=" << p2.second << endl;

	//pair<int, string> p3 = { 3, "西施3" };   // 两个参数的构造函数。
	//// pair<int, string> p3 { 3, "西施3" };   // 两个参数的构造函数，省略了等于号。
	//cout << "p3 first=" << p3.first << ",second=" << p3.second << endl;

	auto p4 = Pair<int, string>(4, "西施4");   // 匿名对象（显式调用构造函数）。
	cout << "p4 first=" << p4.first << ",second=" << p4.second << endl;

	auto p5 = make_Pair<int, string>(5, "西施5");   // make_pair()返回的临时对象。
	cout << "p5 first=" << p5.first << ",second=" << p5.second << endl;

	//pair<int, string> p6 = make_pair(6, "西施6");  // 慎用，让make_pair()函数自动推导，再调用拷贝构造，再隐式转换。
	//cout << "p6 first=" << p6.first << ",second=" << p6.second << endl;

	//auto p7 = make_pair(7, "西施7");    // 慎用，让make_pair()函数自动推导，再调用拷贝构造。
	//cout << "p7 first=" << p7.first << ",second=" << p7.second << endl;

	//p5.swap(p4);   // 交换两个pair。

	//cout << "p4 first=" << p4.first << ",second=" << p4.second << endl;
	//cout << "p5 first=" << p5.first << ",second=" << p5.second << endl;

	//struct st_girl
	//{
	//	string name;
	//	int   age;
	//	double height;
	//};
	//// 用pair存放结构体数据。
	//pair<int, st_girl> p = { 3,{"西施",23,48.6} };
	//cout << "p first=" << p.first << endl;
	//cout << "p second.name=" << p.second.name << endl;
	//cout << "p second.age=" << p.second.age << endl;
	//cout << "p second.height=" << p.second.height << endl;
}