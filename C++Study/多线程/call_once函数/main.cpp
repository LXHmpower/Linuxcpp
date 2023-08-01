#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
#include<unistd.h>
#include<thread>
#include<mutex>
using namespace std;

once_flag onceflag;

void once_func()
{
    cout<<"ready!!!"<<endl;
}
void func(int bh, const string& str) {
	for (int ii = 1; ii <= 10; ii++)
	{
        call_once(onceflag, once_func);
		cout << "第" << ii << "次打招呼：" << bh << "号，" << str << endl;
		this_thread::sleep_for(chrono::seconds(1));  // 休眠1秒。
	}
}

int main()
{

    thread t1(func, 3, "hello");
	thread t2(func, 8, "hello");
	

	t1.join();         // 回收线程t1的资源。
	t2.join();         // 回收线程t2的资源。
	
    cout<<endl;
    return 0;
}
