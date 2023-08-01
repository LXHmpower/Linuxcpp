#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

struct stu{
    string name;
    int score; 
};
void func(stu *s)//结构体指针作为函数参数
{
     s->name = "李四";
    s->score = 80;
    cout<<s->name<< " "<< s->score<< endl;
}
int main()
{
    stu *s = new stu;//结构体指针动态分配
    memset(s,0,sizeof(stu));
      func(s);
    cout<<endl;
    delete(s);
    s = nullptr;

    //结构体数组和普通数组一样，可以用指针表示，也可以用数组本身
    stu S[3] = {{"张三",70},{"李四",80},{"小红",90}};
    stu *p = S;
    for(int i=0;i<3;i++)
    {
        cout<<S[i].name<<" "<<S[i].score<<endl;
    }
     for(int i=0;i<3;i++)
    {
        cout<<(p+i)->name<<" "<<(p+i)->score<<endl;
    }
    return 0;
}