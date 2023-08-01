#include <iostream>
#include <functional>
using namespace std;

// 普通函数
void show(int bh, const string& message) {
	cout << "亲爱的" << bh << "，" << message << endl;
}

struct AA	// 类中有静态成员函数。
{
	static void show(int bh, const string& message) {
		cout << "亲爱的" << bh << "，" << message << endl;
	}
};

struct BB	// 仿函数。
{
	void operator()(int bh, const string& message) {
		cout << "亲爱的" << bh << "，" << message << endl;
	}
};

struct CC	// 类中有普通成员函数。
{
	void show(int bh, const string& message) {
		cout << "亲爱的" << bh << "，" << message << endl;
	}
};

struct DD		// 可以被转换为普通函数指针的类。
{
	using Fun = void (*)(int, const string&);    // 函数指针的别名。
	operator Fun() {
		return show;	// 返回普通函数show的地址。
	}
};

int main()
{
	// 普通函数。
	function<void(int, const string&)> fn1 = bind(show, placeholders::_1, placeholders::_2);    // 绑定普通全局函数show。
	fn1(1, "我是一只傻傻鸟。");										// 用function对象调用普通全局函数show。

	// 类的静态成员函数。
	function<void(int, const string&)> fn3 = bind(AA::show, placeholders::_1, placeholders::_2);		// 绑定类的静态成员函数。
	fn3(2, "我是一只傻傻鸟。");												// 用function对象调用类的静态成员函数。

	// 仿函数。
	function<void(int, const string&)> fn4 = bind(BB(), placeholders::_1, placeholders::_2);			// 绑定仿函数。
	fn4(3, "我是一只傻傻鸟。");										// 用function对象调用仿函数。

	// 创建lambda对象。
	auto lb = [](int bh, const string& message) {
		cout << "亲爱的" << bh << "，" << message << endl;
	};
	function<void(int, const string&)> fn5 = bind(lb, placeholders::_1, placeholders::_2);			// 绑定lamba函数。
	fn5(4, "我是一只傻傻鸟。");										// 用function对象调用lamba函数。

	// 类的非静态成员函数。
	CC cc;
	//function<void(CC&, int, const string&)> fn11 = bind(&CC::show, placeholders::_1, placeholders::_2, placeholders::_3);		// 绑定成员函数。
	//fn11(cc, 5, "我是一只傻傻鸟。");											// 用function对象调用成员函数。
	function<void(int, const string&)> fn11 = bind(&CC::show,&cc,placeholders::_1, placeholders::_2);		// 绑定成员函数。
	fn11(5, "我是一只傻傻鸟。");											// 用function对象调用成员函数。

	// 可以被转换为函数指针的类对象。
	DD dd;
	function<void(int, const string&)> fn12 = bind(dd, placeholders::_1, placeholders::_2);			// 绑定可以被转换为函数指针的类。
	fn12(6, "我是一只傻傻鸟。");										// 用function对象调用它。
}