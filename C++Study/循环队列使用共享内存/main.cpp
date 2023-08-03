#include"squeue.h"

using namespace std;

int main(int argc,char**argv)
{

    squeue<int ,5> s;
    s.push(1); s.push(2);s.push(3);s.push(4);s.push(5);  
    s.printqueue();
  return 0;
}
