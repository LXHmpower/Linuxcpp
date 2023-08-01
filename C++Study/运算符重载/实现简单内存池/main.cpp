#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

class Example
{
    public:
     int m_a;
     int m_b;
     static char* m_pool ;
     Example(int a, int b):m_a(a),m_b(b){}
     static bool InitPool()
     {
         m_pool = (char *)malloc(18);
         if(m_pool == 0) return false;
         memset(m_pool,0,18);
         cout << "内存池的起始地址是：" << (void*)m_pool << endl;
         return true;
     }
     static void freepool()
     {
        if(m_pool == 0) return;
        free(m_pool);
        cout << "内存池已释放。\n";
     }
     
     void * operator new(size_t size)
     {
        if(m_pool[0]==0)
        {
            cout<<"分配第一块内存："<<(void *)(m_pool+1)<<endl;
            m_pool[0] = 1;
            return m_pool+1;
        }
        if(m_pool[9] == 0)
        {
            cout<<"分配第二块内存："<<(void *)(m_pool+9)<<endl;
            m_pool[9] = 1;
            return m_pool+9;
        }
        void* ptr = malloc(size);       
        cout << "内存池已满，从系统申请到的内存的地址是：" << ptr << endl;
        return ptr;
     }
     void operator delete(void* ptr)
     {
        if(ptr == 0) return;
        if(ptr == m_pool+1)
        {
            cout<<"释放第一块内存："<<endl;
            m_pool[0] = 0;
            return;
        }
        if(ptr == m_pool+9)
        {
            cout<<"释放第二块内存："<<endl;
            m_pool[9] = 0;
            return;
        }
        cout<<"释放系统申请内存："<<endl;
        free(ptr);
     }
};
char*Example ::m_pool = 0;
int main()
{
    if(Example::InitPool()==false)
    {
        cout<<"内存分配失败。\n";
        return -1;
    }
    Example *e1 = new Example(1,2);
    cout<<"e1的地址是："<<e1<<endl;
     Example *e2 = new Example(3,4);
    cout<<"e2的地址是："<<e2<<endl;
     Example *e3 = new Example(5,6);
    cout<<"e3的地址是："<<e3<<endl;
    delete e1;
     Example *e4 = new Example(7,8);
    cout<<"e4的地址是："<<e4<<endl;
    delete e2;
    delete e3;
    delete e4;
    Example::freepool();    
    cout<<endl;
    return 0;
}
