#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
template<class T,int len>
class Array
{
private:
    T items[len];
public:
    Array(){}
    ~Array(){};
    T& operator[](int i)
    {
        return items[i]; 
    }
    const T & operator[](int i)const
    {
        return items[i];
    }

};
template<class T>
class Vector
{
private:
    int len;
    T *items;
public:
    Vector(int size=10):len(size){
        items = new T[len];
    }
    ~Vector(){
        delete[] items;
        items = nullptr;
    };
    void resize(int size)
    {
        if(size<=len) return;
        T *tmp = new T[size];
        for(int i=0;i<len;i++)
        {
            tmp[i] = items[i];
        }
        delete[] items;
        items = tmp;
        len=size;
    }
    int size() const
    {
        return len;
    }
    T& operator[](int i)
    {   
        if(i>=len) resize(i+1);
        return items[i]; 
    }
    const T & operator[](int i)const
    {
        return items[i];
    }

};
template<class T,int len>
class Array
{
private:
    T items[len];
public:
    Array(){}
    ~Array(){};
    T& operator[](int i)
    {
        return items[i]; 
    }
    const T & operator[](int i)const
    {
        return items[i];
    }

};
template<class T>
class Vector
{
private:
    int len;
    T *items;
public:
    Vector(int size=10):len(size){
        items = new T[len];
    }
    ~Vector(){
        delete[] items;
        items = nullptr;
    };
    void resize(int size)
    {
        if(size<=len) return;
        T *tmp = new T[size];
        for(int i=0;i<len;i++)
        {
            tmp[i] = items[i];
        }
        delete[] items;
        items = tmp;
        len=size;
    }
    int size() const
    {
        return len;
    }
    T& operator[](int i)
    {   
        if(i>=len) resize(i+1);
        return items[i]; 
    }
    const T & operator[](int i)const
    {
        return items[i];
    }

};
int main()
{
    Array<int,10> a;
    a[0] = 10;  a[1] = 20;  a[2] = 30;  a[3] = 40;  a[4] = 50;  a[5] = 60;
    for (int i = 0; i < 6; i++)
        cout<<a[i]<<" ";
        cout<<endl;
   
    Array<string,10> s;
    s[0] = "a";  s[1] = "b";  s[2] = "c";  s[3] = "d";  s[4] = "e";
    for (int i = 0; i < 5; i++)
        cout<<s[i]<<" ";
        cout<<endl;

    Vector<int> v;
    v[0] = 10;  v[1] = 20;  v[2] = 30;  v[3] = 40;  v[4] = 50;
    for (int i = 0; i < 5; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    Vector<string> vs;
    vs[0] = "a";  vs[1] = "b";  vs[2] = "c";  vs[3] = "d";  vs[4] = "e";
    for (int i = 0; i < 5; i++)
    {
        cout<<vs[i]<<" ";
    }
    cout<<endl;
    return 0;
}
