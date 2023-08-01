#include<iostream>
#include<fstream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int main()
{
    string filename = R"(main.txt)";
    ofstream file(filename,ios::out);
   // ofstream file(filename,ios::app);
    if(file.is_open() == false)
    {
        cout<<"file:"<<filename<<" failed!!!"<<endl;
        return -1;
    }

    file<<"hello world"<<endl;
    file<<"hello world !"<<endl;
 
    cout<<"文件写入成功!!!"<<endl;
    file.close();
    cout<<endl;
    return 0;
}
