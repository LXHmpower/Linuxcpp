#include "test.h"
void test(int a,int b){
    std::cout<<"普通函数"<<endl;
}
template<> void test<int>(int a,int b){
    cout<<"函数模版具体化"<<endl;
}