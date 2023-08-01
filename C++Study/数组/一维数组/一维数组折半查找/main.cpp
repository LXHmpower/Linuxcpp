#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;


int search(int *arr,int size,int e)//折半查找
{
    int low=0,high=size-1,mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(*(arr+mid) == e) return mid;
        if(*(arr+mid)>e) high = mid -1;
        else low = mid+1;
    }
    return -1;
}
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    cout<<"请输入要查找的数字：";
    int num ;
    cin>>num;
    if(search(a,sizeof(a)/sizeof(*a),num) != -1)
    {
        cout<<"查找成功！";
    }
    else{
        cout<<"查找失败";
    }
    cout<<endl;
    return 0;
}
