#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

    void  *operator new(size_t size)
    {
        cout<<"调用全局重载new:"<<size<<"字节"<<endl;
        void *ptr  = malloc(size);
        cout<<"申请到空间:"<<ptr<<endl;
        return ptr;
    }
    void  operator delete(void *ptr)
    {
        cout << "调用了全局重载的delete。\n";
         if (ptr == 0) return;       
            free(ptr);      
    }
    class Example
    {
        public:
         int a;
          void  *operator new(size_t size)
    {
        cout<<"调用类重载new:"<<size<<"字节"<<endl;
        void *ptr  = malloc(size);
        cout<<"申请到空间:"<<ptr<<endl;
        return ptr;
    }
    void  operator delete(void *ptr)
    {
        cout << "调用了类重载的delete。\n";
         if (ptr == 0) return;       
            free(ptr);      
    }
    };
int main()
{
    int *p1 = new int(3);
    cout<<"*p1:"<<(void*)p1<<" "<<"p1:"<<p1<<endl;
    delete p1;
    Example *ex = new Example();   
    delete ex;
    cout<<endl;
    return 0;
}
