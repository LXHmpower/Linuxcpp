#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

class AA {
public:
    AA()         { cout << "调用了AA的构造函数AA()。\n"; }
    AA(int a) { cout << "调用了AA的构造函数AA(int a)。\n"; }
};

class BB {
public:
    BB()         { cout << "调用了BB的构造函数BB()。\n"; }
    BB(int a) { cout << "调用了BB的构造函数BB(int a)。\n"; }
};

class CC {
public:
    CC()         { cout << "调用了CC的构造函数CC()。\n"; }
    CC(int a) { cout << "调用了CC的构造函数CC(int a)。\n"; }
};

template<class T>
class DD {
public:
    DD()         { cout << "调用了DD的构造函数DD()。\n"; }
    DD(int a) { cout << "调用了DD的构造函数DD(int a)。\n"; }
};

template<class T>
class EE : public T {          // 模板类继承模板参数给出的基类。
public:
    EE() :T()           { cout << "调用了EE的构造函数EE()。\n"; }
    EE(int a) :T(a) { cout << "调用了EE的构造函数EE(int a)。\n"; }
};

int main()
{
    EE<AA> ea1;                 // AA作为基类。
    EE<BB> eb1;                 // BB作为基类。
    EE<CC> ec1;                 // CC作为基类。
    EE<DD<int>> ed1;      // EE<int>作为基类。
    // EE<DD> ed1;                // DD作为基类，错误。
}