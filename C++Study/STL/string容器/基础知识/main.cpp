#include<iostream>
//#include<vector>
#include<string>
//#include<algorithm>

using namespace std;

int main()
{
// 1）string(); // 创建一个长度为0的string对象（默认构造函数）。
    string s1;
    cout<<"s1 = "<<s1<<endl;
    cout<<"s1.capacity() = "<<s1.capacity()<<endl;
    cout<<"s1.size() = "<<s1.size()<<endl;
    cout << "容器动态数组的首地址=" << (void *)s1.c_str() << endl;
    s1 = "xxxxxxxxxxxxxxxxxxxx";
    cout << "s1.capacity()=" << s1.capacity() << endl;    
    cout << "s1.size()=" << s1.size() << endl;                   
    cout << "容器动态数组的首地址=" << (void *)s1.c_str() << endl;
//2）string(const char *s); // 将string对象初始化为s指向的NBTS（转换函数）。
    string s2("hello world");
     cout << "s2=" << s2 << endl;       // 将输出s2=hello world
    string s3 = "hello world";
    cout << "s3=" << s3 << endl;       // 将输出s3=hello world
//3）string(const string &str); // 将string对象初始化为str（拷贝构造函数）。
    string s4(s3);
    cout << "s4=" << s4 << endl;       // 将输出s4=hello world
    string s5 = s3;
    cout << "s5=" << s5 << endl;       // 将输出s5=hello world

//4）string(const char *s,size_t n); // 将string对象初始化为s指向的地址后n字节的内容。

    string s6("hello world", 5);
    cout << "s6=" << s6 << endl;       // 将输出s6=hello
    cout << "s6.capacity()=" << s6.capacity() << endl;    // 返回当前容量，可以存放字符的总数。
    cout << "s6.size()=" << s6.size() << endl;                   // 返回容器中数据的大小。
    string s7("hello world", 50); 
    cout << "s7=" << s7 << endl;       // 将输出s7=hello未知内容
    cout << "s7.capacity()=" << s7.capacity() << endl;    // 返回当前容量，可以存放字符的总数。
    cout << "s7.size()=" << s7.size() << endl;                   // 返回容器中数据的大小。
//5）string(const string &str,size_t pos=0,size_t n=npos); // 将sring对象初始化为str从位置pos开始到结尾的字符（或从位置pos开始的n个字符）。
 string s8(s3, 3, 5);                               // s3 = "hello world";
    cout << "s8=" << s8 << endl;         // 将输出s8=lo wo
    string s9(s3, 3);          
    cout << "s9=" << s9 << endl;         // 将输出s9=lo world
    cout << "s9.capacity()=" << s9.capacity() << endl;    // 返回当前容量，可以存放字符的总数。
    cout << "s9.size()=" << s9.size() << endl;                   // 返回容器中数据的大小。
    string s10("hello world", 3, 5);
    cout << "s10=" << s10 << endl;       // 将输出s10=lo wo
    string s11("hello world", 3);                // 注意：不会用构造函数5），而是用构造函数4）
    cout << "s11=" << s11 << endl;       // 将输出s11=hel
//6）template<class T> string(T begin,T end); // 将string对象初始化为区间[begin,end]内的字符，其中begin和end的行为就像指针，用于指定位置，范围包括begin在内，但不包括end。
//7）string(size_t n,char c); // 创建一个由n个字符c组成的string对象。
    string s12(8, 'x');
    cout << "s12=" << s12 << endl;       // 将输出s12=xxxxxxxx
    cout << "s12.capacity()=" << s12.capacity() << endl;    // s12.capacity()=15
    cout << "s12.size()=" << s12.size() << endl;                   // s12.size()=8
    string s13(30, 0);
    cout << "s13=" << s13 << endl;       // 将输出s13=
    cout << "s13.capacity()=" << s13.capacity() << endl;    // s13.capacity()=31
    cout << "s13.size()=" << s13.size() << endl;                   // s12.size()=30 
    cout<<endl;
    return 0;
}
