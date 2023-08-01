#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
#include<unistd.h>
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
    
/* 1）get_id()
thread::id get_id() noexcept;
该函数用于获取线程ID，thread类也有同名的成员函数。 */

/* 2）sleep_for()  VS  Sleep(1000)   Linux sleep(1)
template <class Rep, class Period>
  void sleep_for (const chrono::duration<Rep,Period>& rel_time);
该函数让线程休眠一段时间。 */

/* 5）thread类其它的成员函数
void swap(std::thread& other);    // 交换两个线程对象。 */

    thread t1(func, 3, "hello");
	thread t2(func, 8, "hello");
	
    cout<<"主线程id:"<<this_thread::get_id()<<endl;
    cout<<"t1线程id:"<<t1.get_id()<<endl;
    cout<<"t2线程id:"<<t2.get_id()<<endl;
	
    swap(t1,t2);
     
    cout<<"t1线程id:"<<t1.get_id()<<endl;
    cout<<"t2线程id:"<<t2.get_id()<<endl;

	t1.join();         // 回收线程t1的资源。
	t2.join();         // 回收线程t2的资源。
	
    cout<<endl;
    return 0;
}
