#include <iostream>
#include <cmath>
#include<time.h>
using namespace std;

int main(int argc,char**argv)
{   
    time_t now = time(&now);
    tm tm_now;
    localtime_r(&now,&tm_now);

    string time = to_string(tm_now.tm_year+1900)+"-"
                   +to_string(tm_now.tm_mon+1)+"-"
                   +to_string(tm_now.tm_mday)+" "
                   +to_string(tm_now.tm_hour)+":"
                   +to_string(tm_now.tm_mon)+":"
                   +to_string(tm_now.tm_sec);
    cout<<time<<endl;

   return 0;
}
