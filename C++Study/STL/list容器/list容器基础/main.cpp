#include <iostream>
#include <vector>
#include <list>
using  namespace std;

int main()
{
	// 1）list();  // 创建一个空的list容器。
	list<int> l1;
	// cout << "li.capacity()=" << l1.capacity() << endl;  // 链表没有容量说法。
	cout << "li.size()=" << l1.size() << endl;

	// 2）list(initializer_list<T> il); // 使用统一初始化列表。
	list<int> l2({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
	// list<int> l2={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// list<int> l2  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int value : l2)       // 用基于范围的for循环遍历容器。
		cout << value << " ";
	cout << endl;

	// 3）list(const list<T>& l);  // 拷贝构造函数。
	list<int> l3(l2);
	// list<int> l3=l2;
	for (int value : l3)    
		cout << value << " ";
	cout << endl;

	// 4）list(Iterator first, Iterator last);  // 用迭代器创建list容器。
	list<int> l4(l3.begin(), l3.end());      // 用list容器的迭代器。
	for (int value : l4)  
		cout << value << " ";
	cout << endl;

	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // 创建vector容器。
	list<int> l5(v1.begin() + 2, v1.end() - 3);          // 用vector容器的迭代器创建list容器。
	for (int value : l5)   
		cout << value << " ";
	cout << endl;

	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };   // 创建数组。
	list<int> l6(a1 + 2, a1 + 10 - 3);           // 用数组的指针作为迭代器创建list容器。
	for (int value : l6)     
		cout << value << " ";
	cout << endl;

	char str[] = "hello world";         // 定义C风格字符串。
	string s1(str + 1, str + 7);          // 用C风格字符串创建string容器。
	for (auto value : s1)                   // 遍历string容器。
		cout << value << " ";
	cout << endl;
	cout << s1 << endl;                 // 以字符串的方式显示string容器。

	vector<int> v2(l3.begin(), l3.end());   // 用list迭代器创建vector容器。
	for (auto value : v2)                               // 遍历vector容器。
		cout << value << " ";
	cout << endl;
}