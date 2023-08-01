#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

struct score{
    int ch_score;
    int ma_score;
    int en_score;
};
struct stu{
    char name[20];
    struct score SC;
};
int main()
{
    stu s = {"张三",{60,70,80}};
    cout<<s.name<<" "<<s.SC.ch_score<<" "<<s.SC.ma_score<<" "<<s.SC.en_score;
    cout<<endl;
    return 0;
}
