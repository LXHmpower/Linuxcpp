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
    person p; 
    string filename = R"(../写入二进制文件/main.txt)";
    ifstream file(filename,ios::out | ios::binary);
     while (file.read((char*)&p, sizeof(p)))
	{
        cout<<p.name<<" "<<p.age<<endl;
    }

	file.close();	   

	cout << "操作文件完成。\n";
    cout<<endl;
    return 0;
}
