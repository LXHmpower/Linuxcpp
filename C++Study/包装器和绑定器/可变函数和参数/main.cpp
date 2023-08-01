#include <iostream>
#include <thread>
#include <functional>        
using namespace std;

void show0() {  // 普通函数。
	cout << "hello。\n";
}

void show1(const string& message) {  // 普通函数。
	cout << "nihao，" << message << endl;
}

struct CC	// 类中有普通成员函数。
{
	void show2(int bh, const string& message) {
		cout << "hello:" << bh << "号，" << message << endl;
	}
};

template<typename Fn, typename...Args>
auto show(Fn&& fn, Args&&...args) -> decltype(bind(forward<Fn>(fn), forward<Args>(args)...))
{

	auto f = bind(forward<Fn>(fn), forward<Args>(args)...);
	f();

	return f;
}

int main()
{
	show(show0);
	show(show1,"你好");
	CC cc;
	auto f = show(&CC::show2,&cc, 3,"你好");
	f();
	
	
}