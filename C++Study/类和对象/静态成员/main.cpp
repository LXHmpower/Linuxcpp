#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

 
class Student
{
    public:
    string name;
    static int score ;//类内的静态成员变量只能在类外赋值
    Student(string name,int score)
    {
        this->name = name;
        this->score = score;
    }
    void show_name()
    {
        cout<<name<<endl;
    }
    static void show_score()
    {
        cout<<score<<endl;
    }
};
    int Student::score = 60;
int main()
{
    Student::show_score();//类中的静态成员方法可直接通过 类名:: 来进行调用
    Student s("张三",90);
    s.show_name();
    s.show_score();//通过创建类对象同样可以调用静态成员方法

    cout<<endl;
    return 0;
}
