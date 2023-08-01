#include <iostream>         
using namespace std;        

int main()
{
	int bh[] = {3, 6, 1,6,7,4,3,5,6,7,8,322,2,3,9};             
	string name[3];    
	
	for (int ii = 0; ii < sizeof(bh)/sizeof(int); ii++)
	{
		cout << "bh["<<ii<<"]=" << bh[ii] << endl;
	}

	int bh1[sizeof(bh) / sizeof(int)];   // 数组长度必须是整数，可以是常量，也可以是变量和表达式。

	memcpy(bh1, bh, sizeof(bh));      // 把数组bh中的内容复制到bh1。    

	for (int ii = 0; ii < sizeof(bh1) / sizeof(int); ii++)
	{
		cout << "bh1[" << ii << "]=" << bh1[ii] << endl;
	}
    
    return 0;
}