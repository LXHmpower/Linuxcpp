#include<iostream>
#include<memory>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

class A
{
public:
    int m_a;
    A(int a):m_a(a){cout<<"调用构造函数 "<<endl;}
    ~A(){cout<<"调用析构函数 "<<endl;}
};
void func1(const A *a)
{
    cout<<a->m_a<<endl;
}
void func2(A *a)
{
    cout<<a->m_a<<endl;
    delete a;
}
void func3(const unique_ptr<A> &a)
{
    cout<<a->m_a<<endl;
}
void func4(unique_ptr<A> a)
{
    cout<<a->m_a<<endl;
}
int main()
{
    	unique_ptr<A> pu(new A(1));

	cout << "开始调用函数。\n";
	//func1(pu.get());        // 函数func1()需要一个指针，但不对这个指针负责。
	func2(pu.release());  // 函数func2()需要一个指针，并且会对这个指针负责。
	//func3(pu);                // 函数func3()需要一个unique_ptr，不会对这个unique_ptr负责。
	//func4(move(pu));     // 函数func4()需要一个unique_ptr，并且会对这个unique_ptr负责。
	cout << "调用函数完成。\n";
	if (pu == nullptr) cout << "pu是空指针。\n";
    cout<<endl;
    return 0;
}
