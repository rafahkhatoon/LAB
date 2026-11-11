#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main(){
void *shared_memory;
char buffer[100];
int shmid;
shmid=shmget((key_t) 2922,1024,0666);
printf("Key of shared memory: %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("Process attached at: %p\n",shared_memory);
printf("Received data:%s\n",(char *)shared_memory);
}
