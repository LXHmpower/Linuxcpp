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
    Stack(int size):top(0),stacksize(size){
        items = new DataType[stacksize];
    }
    
    ~Stack(){
        delete [] items;
        items = nullptr;
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
int main()
{
    Stack<int> s(4);
    s.push(1);s.push(2);s.push(3);s.push(4);
    int item;
       while(s.isEmpty()==false)
    {
        s.pop(item);
        cout<<item<<endl;
    }     
    cout<<endl;
    return 0;
}
