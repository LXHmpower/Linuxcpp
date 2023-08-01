#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>

using namespace std;
class Number
{
    public:
    int number;
    Number(int number)
    {
        this->number = number;
    }
   const Number &compare(Number num) const
    {
        if(this->number > num.number)
        {
            return *this;
        }
        else
        {
            return num;
        }
    }
};
int main()
{
    Number n1(2);Number n2(3);Number n3(4); Number n4(5);Number n5(6);
    const Number &n = n1.compare(n2).compare(n3).compare(n4).compare(n5);
    cout<<n.number<<endl;
    cout<<endl;
    return 0;
}
