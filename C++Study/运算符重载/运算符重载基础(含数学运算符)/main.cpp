#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

class Student
{
public:
    string name;
    int score;
    
    Student()
    {}
    Student(string name)
    {
        this->name=name;
    }
    Student(string name,int score)
    {
        this->name=name;
        this->score=score;
    }
    void show()
    {
        cout<<name<<" "<<score<<endl;
    }
    Student& operator+(int n)
{
    this->score=this->score+n;
    return *this;
}
};
/* Student& operator+(Student &s1,int n)
{
    s1.score=s1.score+n;
    return s1;
}
*/
Student& operator+(int n,Student& s)
{
    s.score=s.score+n;
    return s;
} 


int main()
{
    Student s("张三",60);
    s = s + 10;
    s.show();
    s = 10 + s;
    s.show();
    cout<<endl;
    return 0;
}
