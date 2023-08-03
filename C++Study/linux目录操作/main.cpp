#include <iostream>
#include <cmath>
#include<dirent.h>
using namespace std;

int main(int argc,char**argv)
{
   if(argc < 2)
   {
        cout<<"fail!!!"<<endl;
        return -1;
   }

   DIR *dir;
   if((dir = opendir(argv[1])) == nullptr) return -1;

   struct dirent *stdinfo  = nullptr;
   while(1)
   {
        if((stdinfo = readdir(dir)) == nullptr) break;
        cout<<"文件名："<<stdinfo->d_name<<" "<<"文件类型："<<(int)stdinfo->d_type<<endl;
   }
   closedir(dir);
   return 0;
}
