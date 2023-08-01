#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
 class Example
 {
    public:
     int *m_ptr;
     Example()
     {
         m_ptr = nullptr;    
    }
    ~Example()
    {
        delete m_ptr;
    }
    void show()
    {
        cout<<*m_ptr<<endl;
    }
    Example &operator=(const Example &ex)
    {
        if (ex.m_ptr == nullptr)    
        {
            if (m_ptr != nullptr) { delete m_ptr; m_ptr = nullptr; }

        }
       else  
        {
            if (m_ptr == nullptr) m_ptr = new int;
           memcpy(m_ptr, ex.m_ptr, sizeof(int));
        }
        cout << "调用了重载赋值函数" << endl; 
       return *this;
    }
 };
int main()
{
    Example e1;
    e1.m_ptr = new int(3);
    e1.show();
    Example e2;
    e2 = e1;
    e2.show();
    cout<<endl;
    return 0;
}
