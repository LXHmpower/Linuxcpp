#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
#include<thread>
#include<mutex>
using namespace std;

mutex mtx;
void func(int i)
{
    for(int j=1;j<=10;j++)
    {
        mtx.lock();
        cout<<"hello:"<<i<<endl;
        mtx.unlock();
        this_thread::sleep_for(chrono::seconds(1));
    }
}
int main()
{
    thread t1(func,1);
    thread t2(func,2);
    thread t3(func,3);
    thread t4(func,4);
    thread t5(func,5);


    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    cout<<endl;
    return 0;
}
