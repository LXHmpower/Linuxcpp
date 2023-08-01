#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
class Student
{
    public:
    string name;
    
    friend class test;
    friend void func();
    Student(string name)
    {
        this->name = name;
    }
    void show_name()
    {
        cout<<name<<endl;
    }
    private:
    int score = 90;
    void show_score()
    {
        cout<<score<<endl;
    }
};
class test
{
    public:
    void show()
    {
        Student s("张三");
        s.show_name();
        s.show_score(); // 由于show_score是私有的,所以不能访问，需要在Student类中声明友元类
    }


};
void func()
{
    Student s("张三");
        s.show_name();
        s.show_score(); // 由于show_score是私有的,所以不能访问，需要在Student类中声明友元函数
}
int main()
{
    test t;
    t.show();
    func();
    cout<<endl;
    return 0;
}
