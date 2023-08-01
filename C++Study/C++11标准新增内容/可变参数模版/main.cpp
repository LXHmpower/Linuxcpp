#include <iostream>
#include <thread>
using namespace std;

template <typename T>
void show(T girl)      // 向超女表白的函数，参数可能是超女编号，也可能是姓名，所以用T。
{
	cout << "亲爱的" << girl << "，我是一只傻傻鸟。\n";
}

// 递归终止时调用的非模板函数，函数名要与展开参数包的递归函数模板相同。
void print()
{
	cout << "递归终止。\n";
}

// 展开参数包的递归函数模板。
template <typename T, typename ...Args>
void print(T arg, Args... args)
{
	//cout << "参数： " << arg << endl;         // 显示本次展开的参数。

	show(arg);        // 把参数用于表白。

	//cout << "还有" << sizeof...(args) << "个参数未展开。" << endl;  // 显示未展开变参的个数。

	print(args...);     // 继续展开参数。
}

template <typename...Args>
void func(const string& str, Args...args)   // 除了可变参数，还可以有其它常规参数。
{
	cout << str << endl;    // 表白之前，喊句口号。

	print(args...);    // 展开可变参数包。

	cout << "程序终止。\n";
}

int main(void)
{
	//print("金莲", 4, "西施");   
	//print("冰冰", 8, "西施", 3);
	func("hello。", "张三", 8, "李四", 3);  // "我是绝世帅歌。"不是可变参数，其它的都是。
}