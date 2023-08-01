#include <iostream>

#include <string>

using namespace std; 

class AA {   // 定义一个类。

public: 

    AA() {} 

};

int main()

{

    // typeid用于自定义的数据类型。

    AA aa;

    AA* paa = &aa;
    AA& raa = aa;
    cout << "typeid(AA)=" << typeid(AA).name() << endl;
    cout << "typeid(aa)=" << typeid(aa).name() << endl;
    cout << "typeid(AA *)=" << typeid(AA*).name() << endl;
    cout << "typeid(paa)=" << typeid(paa).name() << endl;
    cout << "typeid(AA &)=" << typeid(AA&).name() << endl;
    cout << "typeid(raa)=" << typeid(raa).name() << endl;
    // type_info重载了==和!=运算符，用于对类型进行比较。
    if (typeid(AA) == typeid(aa))     cout << "ok1\n";
    if (typeid(AA) == typeid(*paa)) cout << "ok2\n";
    if (typeid(AA) == typeid(raa))    cout << "ok3\n";
    if (typeid(AA*) == typeid(paa))   cout << "ok4\n";
    return 0;
}

