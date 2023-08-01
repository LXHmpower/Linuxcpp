#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
#include<pthread.h>
#include<thread>
using namespace std;


void func(int bh, const string& str) {
	for (int ii = 1; ii <= 10; ii++)
	{
		cout << "第" << ii << "次打招呼：" << bh << "号，" << str << endl;
		this_thread::sleep_for(chrono::seconds(1));  // 休眠1秒。
	}
}

int main()
{

    thread t(func, 3, "hello");
	this_thread::sleep_for(chrono::seconds(5));
	
    pthread_t th_id= t.native_handle();
    pthread_cancel(th_id);
	t.join();         // 回收线程t1的资源。
	       // 回收线程t2的资源。
	
    cout<<endl;
    return 0;
}
