#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

class Student
{
    public:
        string m_name;
        int m_age;
        Student(string name , int age):m_name(name),m_age(age){}
//   ostream &operator<<(/*此省略了第一个参数*/ /*const Student& stu*/ ostream &cout)//左移运算符不能在类内实现
//{
//    cout<<"姓名:"<<this->m_name<<"年龄:"<<this->m_age;
//   return cout;
//}   

};

ostream &operator<<(ostream &cout ,const Student &stu)//左移运算符只能在类外实现
{
    cout<<"姓名:"<<stu.m_name<<"年龄:"<<stu.m_age;
    return cout;
}
int main()
{
    Student s("张三",19);
    cout<<s<<endl;
    cout<<endl;
    return 0;
}
