#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;

int main()
{
    char STR[] = "hello";
    
    //C风格字符串复制需要用函数，不能使用=
   /*  char *strcpy(char* dest, const char* src);

功 能: 将参数src字符串拷贝至参数dest所指的地址。

返回值: 返回参数dest的字符串起始地址。

复制完字符串后，会在dest后追加0。

如果参数dest所指的内存空间不够大，会导致数组的越界。 */
    char str1[10];
    strcpy(str1,STR);
    cout<<str1<<endl;
    for(int i=0;i<sizeof(str1)/sizeof(char);i++)
    {
        cout<<"str1["<<i<<"]"<<" = "<<str1[i]<<endl;
    }
    /* char * strncpy(char* dest,const char* src, const size_t n);

功能：把src前n个字符的内容复制到dest中。

返回值：dest字符串起始地址。

如果src字符串长度小于n，则拷贝完字符串后，在dest后追加0，直到n个。

如果src的长度大于等于n，就截取src的前n个字符，不会在dest后追加0。

如果参数dest所指的内存空间不够大，会导致数组的越界。 */
    char str2[10];
    strncpy(str2,STR,3);
    cout<<str2<<endl;
    for(int i=0;i<sizeof(str1)/sizeof(char);i++)
    {
        cout<<"str2["<<i<<"]"<<" = "<<str2[i]<<endl;
    }/* 
    获取字符串的长度strlen()

 size_t  strlen( const char*  str);

功能：计算字符串的有效长度，不包含0。

返回值：返回字符串的字符数。

strlen()函数计算的是字符串的实际长度，遇到0结束。 */
    cout<<"strlen(STR) = "<<strlen(STR)<<endl;
    /* 字符串拼接strcat(）

char *strcat(char* dest,const char* src);

功能：将src字符串拼接到dest所指的字符串尾部。

返回值：返回dest字符串起始地址。

dest最后原有的结尾字符0会被覆盖掉，并在连接后的字符串的尾部再增加一个0。

如果参数dest所指的内存空间不够大，会导致数组的越界。 */
char str3[10]="hel";
char str4[] = "lo";
strcat(str3,str4);
cout<<str3<<endl;

/* 字符串拼接strncat()

char *strncat (char* dest,const char* src, const size_t n);

功能：将src字符串的前n个字符拼接到dest所指的字符串尾部。

返回值：返回dest字符串的起始地址。

如果n大于等于字符串src的长度，那么将src全部追加到dest的尾部，如果n小于字符串src的长度，只追加src的前n个字符。

strncat会将dest字符串最后的0覆盖掉，字符追加完成后，再追加0。

如果参数dest所指的内存空间不够大，会导致数组的越界。
 */
/* 字符串比较strcmp()和strncmp()

int strcmp(const char *str1, const char *str2 );

功能：比较str1和str2的大小。

返回值：相等返回0，str1大于str2返回1，str1小于str2返回-1；

int strncmp(const char *str1,const char *str2 ,const size_t n);

功能：比较str1和str2前n个字符的大小。

返回值：相等返回0，str1大于str2返回1，str1小于str2返回-1；

两个字符串比较的方法是比较字符的ASCII码的大小，从两个字符串的第一个字符开始，如果分不出大小，就比较第二个字符，如果全部的字符都分不出大小，就返回0，表示两个字符串相等。

在实际开发中，程序员一般只关心字符串是否相等，不关心哪个字符串更大或更小。
 */
/* 查找字符strchr()和strrchr()

const char *strchr(const char *s, int c);

返回在字符串s中第一次出现c的位置，如果找不到，返回0。

const char *strrchr(const char *s, int c);

返回在字符串s中最后一次出现c的位置，如果找不到，返回0。

 */
/* 查找字符串strstr()

char *strstr(const char* str,const char* substr);

功能：检索子串在字符串中首次出现的位置。

返回值：返回字符串str中第一次出现子串substr的地址；如果没有检索到子串，则返回0。
 */

    cout<<endl;
    return 0;
}
