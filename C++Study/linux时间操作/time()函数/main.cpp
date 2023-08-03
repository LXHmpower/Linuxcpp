#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int main(int argc,char**argv)
{
   time_t now = time(0);
   time_t now_ = time(&now);
   cout<<now<<" "<<now_<<endl; 
   return 0;
}
