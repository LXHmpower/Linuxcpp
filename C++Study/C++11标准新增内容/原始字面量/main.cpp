#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int main()
{
    string str1 = R"(
    #include<iostream>
    int main()
    {
        std::cout<<"hello world"<<std::endl;
        return 0;
    }
     )";
    cout<<str1<<endl;
     string PATH = R"123123(/usr/local/include)123123";
    cout<<"PATH = "<<PATH<<endl;
      
    cout<<endl;
    return 0;
}
