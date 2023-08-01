#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

template<class DataType>
class Stack{
private:
    DataType *items;
    int top;
    int stacksize;
public:
    Stack(int size = 3):top(0),stacksize(size){
        items = new DataType[stacksize];
    }
    
    ~Stack(){
        delete [] items;
        items = nullptr;
    }
    Stack &operator =(Stack &s)//Vector内增加容量时出现了赋值，会导致浅拷贝的问题，所以要重载赋值函数改成深拷贝
    {
        delete []items;
        stacksize = s.stacksize;
        items = new DataType[stacksize];
        for(int i=0;i<stacksize;i++)
        {
            items[i] = s.items[i];
        }
        top = s.top;
        return *this;
    }
    bool isEmpty() const{return top == 0;}
    bool isFull() const{return top == stacksize;}
    bool push(const DataType &item)
    {
        if(isFull())return false;
        items[top++] = item;
        return true;
    }
    bool pop(DataType &item)
    {
    if(top>0){item = items[--top]; return true; }
        return false;
    }
};

template<class T>
class Vector
{
private:
    int len;
    T *items;
public:
    Vector(int size =2 ):len(size){
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
    Vector<Stack<string>> v;
    v[0].push("ab");v[0].push("cd");v[0].push("ef");
    v[1].push("gh");v[1].push("ij");//v[1].push("kl");
    for (int i = 0; i < v.size(); i++)
    {
        while(v[i].isEmpty() == false)
        {
            string items;
            v[i].pop(items);
            cout<<"item ="<<items<<endl;
        }
    }

    Stack<Vector<string>> s;
    Vector<string> tmp;
    tmp[0] = "ab";tmp[1] = "cd";s.push(tmp);
    //tmp[0] = "ef";tmp[1] = "gh";s.push(tmp);
    tmp[0] = "ij";tmp[1] = "lm";s.push(tmp);
    while(s.isEmpty() == false)
    {
        s.pop(tmp);
        for(int i=0;i<tmp.size();i++)
        {
            cout<<"tmp["<<i<<"]="<<tmp[i]<<endl;
        }
    }
    cout<<endl;
    return 0;
}
