#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

class Student
{
    public:
    string student[10] = {"张三","李四","王五"};
    string &operator[](int i)//[]运算符重载只能在类中声明
    {
        return student[i];
    }
    const string &operator[](int i)const
    {
        return student[i];
    }

};
int main()
{
    Student s;
    cout<<s[1]<<endl;
    s[2] = "赵六";
    cout<<s[2]<<endl;
    cout<<endl;
    return 0;
}
