#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

int main()
{
	// int bh[2][3] = { {11,12,13},{21,22,23} };                              // 声明一个两行三列的二维数组
	// int bh[2][3] = { 11,12,13,21,22,23 };
	int bh[][3] = { 11,12,13,21,22,23 };
	/*bh[0][0] = 11;		bh[0][1] = 12;    bh[0][2] = 13;
	bh[1][0] = 21; 	bh[1][1] = 22;    bh[1][2] = 23;*/	
	/*cout << "bh[0][0] = " << bh[0][0] << "  bh[0][1] = " << bh[0][1] << "  bh[0][2] = " << bh[0][2] << endl;
	cout << "bh[1][0] = " << bh[1][0] << "  bh[1][1] = " << bh[1][1] << "  bh[1][2] = " << bh[1][2] << endl;*/
	for (int ii = 0; ii < 2; ii++)                 // 第一层循环表示行数，循环继续的条件是计数器小于行数。
	{
		for (int jj = 0; jj < 3; jj++)              // 第二层循环表示列数，循环继续的条件是计数器小于列数。
		{
			cout << "&bh["<<ii<<"]["<<jj<<"] = " << (long long) & bh[ii][jj] << "  ";          // 处理二维数组的每个元素。
		}
		cout << endl;          // 每处理一行数据后，输出一个换行。
	}
	int* p = (int *)bh;
	for (int ii = 0; ii < 6; ii++)
	{
		cout << "p[" << ii << "]=" << p[ii] << endl;     // 一维数组的数组表示法。
	}
}