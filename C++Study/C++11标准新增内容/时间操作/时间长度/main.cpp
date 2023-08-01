#include <iostream>
#include <chrono>      // chrono库的头文件。
using namespace std;

int main()
{
    chrono::hours  t1(1);                                  // 1小时
    chrono::minutes  t2(60);                            //  60分钟
    chrono::seconds  t3(60 * 60);                    //  60*60秒
    chrono::milliseconds  t4(60 * 60 * 1000);  // 60*60*1000毫秒
    chrono::microseconds t5(60 * 60 * 1000 * 1000);          // 警告：整数溢出。
    chrono::nanoseconds t6(60 * 60 * 1000 * 1000*1000);  // 警告：整数溢出。

    if (t1 == t2)    cout << "t1==t2\n";
    if (t1 == t3)    cout << "t1==t3\n";
    if (t1 == t4)    cout << "t1==t4\n";

    // 获取时钟周期的值，返回的是int整数。
    cout << "t1=" << t1.count() << endl;
    cout << "t2=" << t2.count() << endl;
    cout << "t3=" << t3.count() << endl;
    cout << "t4=" << t4.count() << endl;

    chrono::seconds t7(1);                                         // 1秒
    chrono::milliseconds  t8(1000);                           // 1000毫秒
    chrono::microseconds t9(1000 * 1000);              // 1000*1000微秒
    chrono::nanoseconds t10(1000 * 1000 * 1000);  //  1000*1000*1000纳秒

    if (t7 == t8)    cout << "t7==t8\n";
    if (t7 == t9)    cout << "t7==t9\n";
    if (t7 == t10)  cout << "t7==t10\n";

    // 获取时钟周期的值。
    cout << "t7=" << t7.count() << endl;
    cout << "t8=" << t8.count() << endl;
    cout << "t9=" << t9.count() << endl;
    cout << "t10=" << t10.count() << endl;
}