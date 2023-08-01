
#include <iostream>
#include <vector>
using  namespace std;

int main()
{
	vector<int> v1;
	v1 = { 1,2,3,4,5 };     // 使用统一初始化列表赋值。
	for (int ii = 0; ii < v1.size(); ii++) cout << v1[ii] << "  ";
	cout << endl;

	vector<int> v2;
	v2 = v1;                    // 把容器v1赋值给当前容器。
	for (int ii = 0; ii < v2.size(); ii++) cout << v2[ii] << "  ";
	cout << endl;

	vector<int> v3;
	v3.assign({ 1,2,3,4,5 });   // 用assign()函数给当前容器赋值，参数是统一初始化列表。
	for (int ii = 0; ii < v3.size(); ii++) cout << v3[ii] << "  ";
	cout << endl;
    	
        
    vector<vector<int>> vv;   // 创建一个vector容器vv，元素的数据类型是vector<int>。

	vector<int> v;        // 创建一个容器v，它将作为容器vv的元素。

	v = { 1,2,3,4,5 };      // 用统一初始化列表给v赋值。
	vv.push_back(v);    // 把容器v作为元素追加到vv中。

	v = { 11,12,13,14,15,16,17 };   // 用统一初始化列表给v赋值。
	vv.push_back(v);                      // 把容器v作为元素追加到vv中。

	v = { 21,22,23 };     // 用统一初始化列表给v赋值。
	vv.push_back(v);    // 把容器v作为元素追加到vv中。

	// 用嵌套的循环，把vv容器中的数据显示出来。
	for (int ii = 0; ii < vv.size(); ii++)
	{
		for (int jj = 0; jj < vv[ii].size(); jj++)
			cout << vv[ii][jj] << " ";      // 像二维数组一样使用容器vv。

		cout << endl;
	}
    return 0;
}

