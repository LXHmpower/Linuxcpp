#pragma once
#include<iostream>
using namespace std;
void test(int a,int b);
template<typename T>
void test(T a,T b)
{
    cout<<"函数模版"<<endl;
}
template<> void test<int>(int a,int b);