#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

template <class T , int len>
class LinkList
{
public:
    T *head;
    int m_len = len;
    void insert(){cout<<"链表插入数据"<<endl;}
    void _delete(){cout<<"链表删除数据"<<endl;}
};

template <class T , int len>
class Array
{
public:
    T *data;
    int m_len = len;
    void insert(){cout<<"数组插入数据"<<endl;}
    void _delete(){cout<<"数组删除数据"<<endl;}
};

template < template<class,int>class tabletype ,class datatpye, int len>
class LinearList
{
public:
    tabletype<datatpye,len> m_table;
    void insert(){m_table.insert();}
    void _delete(){m_table._delete();}
    void ReturnSize(){cout<<"len = "<<m_table.m_len<<endl;}
};
int main()
{
    LinearList< LinkList, int, 10 > l1;
    l1.insert();
    l1._delete();
    l1.ReturnSize();
    LinearList< Array, int, 10 > l2;
    l2.insert();
    l2._delete();
    l2.ReturnSize();

    cout<<endl;
    return 0;
}
