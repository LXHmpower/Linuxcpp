#include<iostream>
#include<fstream>
#include<unistd.h>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int main()
{
    string filename = R"(main.txt)";
    ifstream file(filename,ios::out);
    if(file.is_open() == false)
    {
       cout<<"file:"<<filename<<"读取失败"<<endl; 
       return -1;      
    }
    cout<<"文件内容："<<endl;
   //// 第一种方法。
	string buffer;  // 用于存放从文件中读取的内容。
	//// 文本文件一般以行的方式组织数据。
	while (getline(file, buffer))
	{
		cout << buffer << endl;
	}

	//// 第二种方法。
	//char buffer[16];   // 存放从文件中读取的内容。
	//// 注意：如果采用ifstream.getline()，一定要保证缓冲区足够大。
	//while (file.getline(buffer, 15))
	//{
	//	cout << buffer << endl;
	//}

	// 第三种方法。
	/* string buffer;
	while (file >> buffer)
	{
		cout << buffer << " ";
	} */
    cout<<"文件操作完成!!!"<<endl;
    file.close();
    cout<<endl;
    return 0;
}