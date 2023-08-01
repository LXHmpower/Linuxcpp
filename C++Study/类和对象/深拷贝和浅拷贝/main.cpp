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
        int *m_ptr;
        Student()
        {
             m_name = "张三";
            m_score = 60;
            m_ptr = nullptr;
            cout<<"无参构造函数调用"<<endl;
        }
       
        Student(const Student& stu)
        {
             m_name = stu.m_name;
            m_score = stu.m_score;
           //*m_ptr = *stu.m_ptr; //浅拷贝
            m_ptr = new int(3);
            *m_ptr = *stu.m_ptr; //深拷贝
            cout<<"拷贝构造函数调用"<<endl;
            
        }
        ~Student()
        {
            delete m_ptr; m_ptr = nullptr; 
            cout<<"析构函数调用"<<endl;
        }
        void show()
        {
            cout<<"姓名 :"<<m_name<<" "<<"分数:"<<m_score<<" "<<"*m_ptr:"<<*m_ptr<<endl;
        }
        
};
int main()
{
   Student stu1;
   stu1.m_name = "张三" ; stu1.m_score = 60;stu1.m_ptr = new int(3);
   stu1.show();
   Student stu2(stu1);
   
    stu2.show();
      
    return 0;
}
