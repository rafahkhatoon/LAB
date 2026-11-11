#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>
int main(){
void *shared_memory;
char buffer[100];
int shmid;
shmid=shmget((key_t) 2706,1024,0666|IPC_CREAT);
printf("Key of shared memory: %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("Process attached at:%p\n",shared_memory);
printf("Enter data to write shared memory:\n");
read(0,buffer,100);
strcpy(shared_memory,buffer);
printf("Data written is %s\n",(char *)shared_memory);
}
