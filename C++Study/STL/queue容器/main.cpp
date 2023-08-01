#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
#include<list>
#include<queue>
using namespace std;
class Person
{
public:
    string p_name;
    int p_age;
    Person(int age,string name):p_age(age),p_name(name){}
};
int main()
{
    queue<int>q1;
    q1.push(1); q1.push(2); q1.push(3); q1.push(4); q1.push(5);
    while(q1.empty() == false)
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;

    queue<Person,list<Person> >q2;
    q2.push(Person(1,"张三"));
    q2.push(Person(2,"李四"));
    q2.push(Person(3,"王五"));  
    while(q2.empty() == false)
    {
        cout<<q2.front().p_name<<" "<<q2.front().p_age<<endl;
        q2.pop();
        }

    return 0;
}
