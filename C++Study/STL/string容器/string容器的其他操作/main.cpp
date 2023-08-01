#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int main()
{
    
    cout<<endl;
    return 0; 
}

/* 二、特性操作
size_t max_size() const;    // 返回string对象的最大长度string::npos，此函数意义不大。
size_t capacity() const;     // 返回当前容量，可以存放字符的总数。
size_t length() const;      // 返回容器中数据的大小（字符串语义）。
size_t size() const;         // 返回容器中数据的大小（容器语义）。
bool empty() const;     // 判断容器是否为空。
void clear();             // 清空容器。
void shrink_to_fit();	      // 将容器的容量降到实际大小（需要重新分配内存）。
void reserve( size_t size=0);  // 将容器的容量设置为至少size。
void resize(size_t len,char c=0);  // 把容器的实际大小置为len，如果len<实际大小，会截断多出的部分；如果len>实际大小，就用字符c填充。


三、字符操作
char &operator[](size_t n); 
const char &operator[](size_t n) const;  // 只读。
char &at(size_t n); 
const char &at(size_t n) const;          // 只读。
operator[]和at()返回容器中的第n个元素，但at函数提供范围检查，当越界时会抛出out_of_range异常，operator[]不提供范围检查。
const char *c_str() const; // 返回容器中动态数组的首地址，语义：寻找以null结尾的字符串。
const char *data() const; // 返回容器中动态数组的首地址，语义：只关心容器中的数据。
int copy(char *s, int n, int pos = 0) const; // 把当前容器中的内容，从pos开始的n个字节拷贝到s中，返回实际拷贝的数目。


四、赋值操作
给已存在的容器赋值，将覆盖容器中原有的内容。
1）string &operator=(const string &str); // 把容器str赋值给当前容器。
2）string &assign(const char *s); // 将string对象赋值为s指向的NBTS。
3）string &assign(const string &str); // 将string对象赋值为str。
4）string &assign(const char *s,size_t n); // 将string对象赋值为s指向的地址后n字节的内容。
5）string &assign(const string &str,size_t pos=0,size_t n=npos); // 将sring对象赋值为str从位置pos开始到结尾的字符（或从位置pos开始的n个字符）。
6）template<class T> string &assign(T begin,T end); // 将string对象赋值为区间[begin,end]内的字符。
7）string &assign(size_t n,char c); // 将string对象赋值为由n个字符c。


五、连接操作
把内容追加到已存在容器的后面。
1）string &operator+=(const string &str); //把容器str连接到当前容器。
2）string &append(const char *s); // 把指向s的NBTS连接到当前容器。
3）string &append(const string &str); // 把容器str连接到当前容器。
4）string &append(const char *s,size_t n); // 将s指向的地址后n字节的内容连接到当前容器。
5）string &append(const string &str,size_t pos=0,size_t n=npos); // 将str从位置pos开始到结尾的字符（或从位置pos开始的n个字符）连接到当前容器。
6）template<class T> string &append (T begin,T end); // 将区间[begin,end]内的字符连接到容器。
7）string &append(size_t n,char c); // 将n个字符c连接到当前容器。


六、交换操作
void swap(string &str);    // 把当前容器与str交换。
如果数据量很小，交换的是动态数组中的内容，如果数据量比较大，交换的是动态数组的地址。


七、截取操作
string substr(size_t pos = 0,size_t n = npos) const; // 返回pos开始的n个字节组成的子容器。


八、比较操作
bool operator==(const string &str1,const string &str2) const; // 比较两个字符串是否相等。
int compare(const string &str) const; // 比较当前字符串和str1的大小。
int compare(size_t pos, size_t n,const string &str) const; // 比较当前字符串从pos开始的n个字符组成的字符串与str的大小。
int compare(size_t pos, size_t n,const string &str,size_t pos2,size_t n2)const; // 比较当前字符串从pos开始的n个字符组成的字符串与str中pos2开始的n2个字符组成的字符串的大小。
以下几个函数用于和C风格字符串比较。
int compare(const char *s) const; 
int compare(size_t pos, size_t n,const char *s) const;
int compare(size_t pos, size_t n,const char *s, size_t pos2) const;


九、查找操作
size_t find(const string& str, size_t pos = 0) const;
size_t find(const char* s, size_t pos = 0) const;
size_t find(const char* s, size_t pos, size_t n) const;
size_t find(char c, size_t pos = 0) const;

size_t rfind(const string& str, size_t pos = npos) const;
size_t rfind(const char* s, size_t pos = npos) const;
size_t rfind(const char* s, size_t pos, size_t n) const;
size_t rfind(char c, size_t pos = npos) const;

size_t find_first_of(const string& str, size_t pos = 0) const;
size_t find_first_of(const char* s, size_t pos = 0) const;
size_t find_first_of(const char* s, size_t pos, size_t n) const;
size_t find_first_of(char c, size_t pos = 0) const;

size_t find_last_of(const string& str, size_t pos = npos) const;
size_t find_last_of(const char* s, size_t pos = npos) const;
size_t find_last_of(const char* s, size_t pos, size_t n) const;
size_t find_last_of(char c, size_t pos = npos) const;

size_t find_first_not_of(const string& str, size_t pos = 0) const;
size_t find_first_not_of(const char* s, size_t pos = 0) const;
size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
size_t find_first_not_of(char c, size_t pos = 0) const;

size_t find_last_not_of(const string& str, size_t pos = npos) const;
size_t find_last_not_of(const char* s, size_t pos = npos) const;
size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
size_t find_last_not_of(char c, size_t pos = npos) const;


十、替换操作
string& replace(size_t pos, size_t len, const string& str);
string& replace(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen = npos);
string& replace(size_t pos, size_t len, const char* s);
string& replace(size_t pos, size_t len, const char* s, size_t n);
string& replace(size_t pos, size_t len, size_t n, char c);
以下函数意义不大。
string& replace(iterator i1, iterator i2, const string& str);
string& replace(iterator i1, iterator i2, const char* s);
string& replace(iterator i1, iterator i2, const char* s, size_t n);
string& replace(iterator i1, iterator i2, size_t n, char c);
template <class InputIterator>
string& replace(iterator i1, iterator i2, InputIterator first, InputIterator last);


十一、插入操作
string& insert(size_t pos, const string& str);
string& insert(size_t pos, const string& str, size_t subpos, size_t sublen = npos);
string& insert(size_t pos, const char* s);
string& insert(size_t pos, const char* s, size_t n);
string& insert(size_t pos, size_t n, char c);
以下函数意义不大。
iterator insert(iterator p, size_t n, char c);
iterator insert(iterator p, char c);
template <class InputIterator>
iterator insert(iterator p, InputIterator first, InputIterator last);


十二、删除操作
string &erase(size_t pos = 0, size_t n = npos); // 删除pos开始的n个字符。
以下函数意义不大。
iterator erase(iterator it); // 删除it指向的字符，返回删除后迭代器的位置。
iterator erase(iterator first, iterator last); / /删除[first，last）之间的所有字符，返回删除后迭代器的位置。 */