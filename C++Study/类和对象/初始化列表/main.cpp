#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
class Score{
    public:
    int m_score;
    Score()
    {
        cout<<"score的无参构造函数调用"<<endl;
    }
    Score(int score)
    {
        m_score = score;
        cout<<"score的构造函数调用"<<endl;
    }
    Score(const Score &score)
    {
        cout<<"score的拷贝构造函数调用"<<endl;
    }
    
};
class Student
{
public:
    int m_age;
    string m_name;
    Score &m_Score;
     Student(int age,string name ,Score &score):m_age(age),m_name(name),m_Score(score)//初始化列表对于类成员变量性能会更好
    {
        cout<<"构造函数"<<endl;
    } 
    /* Student(int age,string name ,Score &sc)
    {
        m_age=age;
        m_name=name;
        m_Score.m_score=sc.m_score;
        cout<<"构造函数"<<endl;
    } */
    void show()
    {
        cout<<"姓名:"<<m_name<<"年龄:"<<m_age<<"成绩:"<<m_Score.m_score<<endl;
    }
};
int main()
{
    Score s(60);
    Student stu(18,"张三",s);
    stu.show();
    return 0;
}
