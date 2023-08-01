#include <iostream>
#include <thread>                // 线程类头文件。
#include <unistd.h>>         // Sleep()函数需要这个头文件。
using namespace std;

// 普通函数。
void func(int bh, const string& str) {
	for (int ii = 1; ii <= 10; ii++)
	{
		cout << "第" << ii << "次打招呼：" << bh << "号，" << str << endl;
			sleep(1);   /// 休眠1秒。
	}
}

// 仿函数。
class mythread1
{
public:
	void operator()(int bh, const string& str) {
		for (int ii = 1; ii <= 10; ii++)
		{
			cout << "第" << ii << "次打招呼：" << bh << "号，" << str << endl;
			sleep(1);   // 休眠1秒。
		}
	}
};

// 类中有静态成员函数。
class mythread2
{
public:
	static void func(int bh, const string& str) {
		for (int ii = 1; ii <= 10; ii++)
		{
			cout << "第" << ii << "次打招呼：" << bh << "号，" << str << endl;
			sleep(1);   // 休眠1秒。
		}
	}
};

// 类中有普通成员函数。
class mythread3
{
public:
	void func(int bh, const string& str) {
		for (int ii = 1; ii <= 10; ii++)
		{
			cout << "第" << ii << "次打招呼：" << bh << "号，" << str << endl;
			sleep(1);   
		}
	}
};

int main()
{
	// 用普通函数创建线程。
	//thread t1(func, 3, "我是一只傻傻鸟。");
	//thread t2(func, 8, "我有一只小小鸟。");

	// 用lambda函数创建线程。
	auto f = [](int bh, const string& str) {
		for (int ii = 1; ii <= 10; ii++)
		{
			cout << "第" << ii << "次打招呼：" << bh << "号，" << str << endl;
			sleep(1);   // 休眠1秒。
		}
	};
	//thread t3(f, 3, "hello");

	// 用仿函数创建线程。
	//thread t4(mythread1(), 3, "hello");

	// 用类的静态成员函数创建线程。
	//thread t5(mythread2::func, 3, "hello");

	// 用类的普通成员函数创建线程。
	mythread3 myth;   // 必须先创建类的对象，必须保证对象的生命周期比子线程要长。
	thread t6(&mythread3::func, &myth, 3, "hello");  // 第二个参数必须填对象的this指针，否则会拷贝对象。

	cout << "任务开始。\n";
	for (int ii = 0; ii < 10; ii++) {
		cout << "执行任务中......\n";
		sleep(1);   // 假设执行任务需要时间。
	}
	cout << "任务完成。\n";

	//t1.join();         // 回收线程t1的资源。
	//t2.join();         // 回收线程t2的资源。
	//t3.join();         // 回收线程t3的资源。
	//t4.join();         // 回收线程t4的资源。
	//t5.join();         // 回收线程t5的资源。
	t6.join();         // 回收线程t6的资源。
}