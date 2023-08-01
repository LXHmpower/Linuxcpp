#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
#include<list>
using namespace std;

void print(list<int> L)
{
    for(auto &val : L)
        cout<<val<<" ";
    cout<<endl;
}
int main()
{
    list<int> l1 = {2,5,4,1,3};
    print(l1);
    l1.reverse();
    print(l1);
    l1.sort();
    print(l1);
    
    list<int> l2 = {7,6,9,8,5};
    l2.sort();
    l1.merge(l2);
    print(l1);

    l1.push_front(0);
    print(l1);
    
    list<int>  la = { 8,2,6,4,5 };
	print(la);
	list<int>  lb = { 3,7,9,10,1 };
	print(lb);

	auto first = lb.begin();
	first++;
	auto last = lb.end();
	last--;

	la.splice(la.begin(), lb, first, last);

	print(la);

	cout << "lb.size()=" << lb.size() << endl;
	print(lb);
    cout<<endl;
    return 0;
}
