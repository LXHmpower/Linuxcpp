#include <iostream>
#include <cmath>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<cstring>
using namespace std;


struct person
{
    int age;
    char name[20];
};

int main(int argc,char**argv)
{
    if(argc < 3)
    {
        cout<<"too little!!!"<<endl;
        return -1;
    }
   int shmid = shmget(0x5005,sizeof(person),0640|IPC_CREAT);
   if(shmid == -1)
   {
        return -1;
   }
   cout<<"shmid:"<<shmid<<endl;
   
   person *p = (person*)shmat(shmid,0,0);
   cout<<p->age<<" "<<p->name<<endl;
   p->age = atoi(argv[1]); strcpy(p->name,argv[2]);
   cout<<p->age<<" "<<p->name<<endl;

   shmdt(p);
   return 0;
}
