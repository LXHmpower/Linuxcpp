#include <iostream>
// #include<vector>
// #include<string>
// #include<algorithm>

using namespace std;

int main() {
    int *num = new int[10]; // 用new分配内存
    for (int i = 0; i < 10; i++) {
        *(num + i) = i;
    }
    for (int i = 0; i < 10; i++) {
        cout << *(num + i) << " ";
    }
    delete[] num;  // 用delete销毁
    num = nullptr; // 销毁后置空，以免出现野指针
    cout << endl;
    return 0;
}
