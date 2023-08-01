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
    Student(string n,int s):name(n),score(s){}
    bool operator>(Student &s)
    {
        return score>s.score;
    }
    bool operator<(Student &s)
    {
        return score<s.score;
    }
    bool operator==(Student &s)
    {
        return score==s.score;
    }

};
int main()
{
    Student s1("张三",60),s2("李四",40);
    if(s1 == s2)
    {
        cout<<"相等"<<endl;
    }
    if(s1>s2)
    {
        cout<<"大"<<endl;
    }
    if(s1<s2)
    {
        cout<<"小"<<endl;
    }
    cout<<endl;
    return 0;
}
