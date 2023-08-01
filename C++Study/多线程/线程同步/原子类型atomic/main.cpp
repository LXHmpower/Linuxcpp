#include <iostream>
#include <atomic>     // 原子类型的头文件。
using namespace std;

int main()
{
	atomic<int> a = 3;       // atomic(T val) noexcept;  // 转换函数。
	cout << "a=" << a.load() << endl;   // 读取原子变量a的值。输出：a=3
	a.store(8);      // 把8存储到原子变量中。
	cout << "a=" << a.load() << endl;   // 读取原子变量a的值。 输出：a=8
	
	int old;        // 用于存放原值。
	old = a.fetch_add(5);         // 把原子变量a的值与5相加，返回原值。
	cout << "old = " << old <<"，a = " << a.load() << endl;   // 输出：old=8，a=13
	old = a.fetch_sub(2);         // 把原子变量a的值减2，返回原值。
	cout << "old = " << old << "，a = " << a.load() << endl;   // 输出：old=13，a=11
	
	atomic<int> ii = 3;  // 原子变量
	int expect = 4;         // 期待值
	int val = 5;               // 打算存入原子变量的值
	// 比较原子变量的值和预期值expect，
	// 如果当两个值相等，把val存储到原子变量中；
	// 如果当两个值不相等，用原子变量的值更新预期值。
	// 执行存储操作时返回true，否则返回false。
	bool bret = ii.compare_exchange_strong(expect, val);
	cout << "bret=" << bret << endl;
	cout << "ii=" << ii << endl;
	cout << "expect=" << expect << endl;
}
