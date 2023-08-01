#include <iostream>         
using namespace std;        

class Example     
{
public:    
    int m; 
    Example() {   m = 5; }
    void show() const { cout << m<< endl; }
    Example & operator++()         // ++前置的重载函数。
    {
       m++; return *this;
    }
    Example operator++(int)     // ++后置的重载函数。
    {
        Example tmp = *this;
        m++; 
        return tmp;
    }
};
int main()

{
    Example e1,e2;       
    int ii=5 , jj=5;
    int xx = ++(++(++ii));        cout << "xx=" << xx << ",ii=" << ii << endl;
    int yy = jj++;                       cout << "yy=" << yy << ",jj=" << jj << endl;
    Example e3 = ++(++(++e1));   cout << "e3.m = " << e3.m<< ",e1.m=" << e1.m << endl;
    Example e4 = e2++;                   cout << "e4.m=" << e4.m << ",e2.m=" << e2.m << endl;
    // e2.show();
    return 0;
}

