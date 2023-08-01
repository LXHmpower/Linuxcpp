#include <iostream>
#include <mutex>        // 互斥锁类的头文件。
using namespace std;

class AA
{
	recursive_mutex m_mutex;
public:
	void func1() {
		m_mutex.lock();
		cout << "调用了func1()\n";
		m_mutex.unlock();
	}

	void func2() {
		m_mutex.lock();
		cout << "调用了func2()\n";
		func1();
		m_mutex.unlock();
	}
};

int main()
{
	AA aa;
	//aa.func1();
	aa.func2();
}
