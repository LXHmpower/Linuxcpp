#include <iostream>
using namespace std;

void func1(int& ii) {        // 如果参数是左值，调用此函数。
    cout << "参数是左值=" << ii << endl;
}

void func1(int&& ii) {     // 如果参数是右值，调用此函数。
    cout << "参数是右值=" << ii << endl;
}

// 1）如果模板中（包括类模板和函数模板）函数的参数书写成为T&& 参数名，
// 那么，函数既可以接受左值引用，又可以接受右值引用。
// 2）提供了模板函数std::forward<T>(参数) ，用于转发参数，
// 如果参数是一个右值，转发之后仍是右值引用；如果 参数是一个左值，转发之后仍是左值引用。
template<typename TT>
void func(TT&& ii)
{
    func1(forward<TT>(ii));
}

int main()
{
    int ii = 3;
    func(ii);       // 实参是左值。
    func(8);       // 实参是右值。
}