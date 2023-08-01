#include <iostream>
#include <thread>                // 线程类头文件。
#include <unistd.h>         // Sleep()函数需要这个头文件。
using namespace std;

// 普通函数。
void func(int bh, const string& str) {
	for (int ii = 1; ii <= 10; ii++)
	{
		cout << "第" << ii << "次打招呼：" << bh << "号，" << str << endl;
		sleep(1);   // 休眠1秒。
	}
}

int main()
{
	// 用普通函数创建线程。
	thread t1(func, 3, "hello");
	thread t2(func, 8, "hello");
	
	t1.detach(); t2.detach();  // 分离子线程。

	//cout << "任务开始。\n";
	//for (int ii = 0; ii < 12; ii++) {
	//	cout << "执行任务中......\n";
	//	Sleep(1000);   // 假设执行任务需要时间。
	//}
	//cout << "任务完成。\n";
	
	//t1.join();         // 回收线程t1的资源。
	//t2.join();         // 回收线程t2的资源。
	sleep(12);
}