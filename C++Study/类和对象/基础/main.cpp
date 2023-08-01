#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

class Student
{
    public:
        string m_name;
        int m_score;
        Student()
        {
            cout<<"无参构造函数调用"<<endl;
        }
        Student(string name , int score)
        {
            m_name = name;
            m_score = score;
            cout<<"有参构造函数调用"<<endl;
        }
        void setName(string name)
        {
            m_name = name;
        }
        string getName()
        {
            return m_name;
        }
        void setScore(int score)
        {
            m_score = score;
        }
        int getScore()
        {
            return m_score;
        }
        Student(const Student& stu)
        {
            m_name = stu.m_name;
           m_score = stu.m_score;
            cout<<"拷贝构造函数调用"<<endl;
        }
        ~Student()
        {
            cout<<"析构函数调用"<<endl;
        }
        void show()
        {
            cout<<"姓名 :"<<m_name<<" "<<"分数:"<<m_score<<endl;
        }
        
};
int main()
{
    Student stu("张三",80);
      stu.show();
    
    Student stu_copy1(stu);
    stu_copy1.show();
   
    Student stu_copy2(stu);
    stu_copy1.show();
    
    Student stu_1 ;
    stu_1.setName("王五");
    stu_1.setScore(60);
    stu_1.show();    
    return 0;
}
