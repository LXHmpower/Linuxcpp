#include<iostream>
#include<fstream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

typedef struct st_person
{
    string name;
    int age;
}person;
int main()
{
    person p  = {"张三",18};
    string filename = R"(main.txt)";
    ofstream file(filename,ios::out | ios::binary);
    file.write((const char*)&p,sizeof(person));
    file.close();
    cout<<"文件写入成功!!!"<<endl;
    cout<<endl;
    return 0;
}
