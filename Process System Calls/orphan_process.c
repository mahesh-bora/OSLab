#include<stdio.h>

main(){
int id;
printf("Before fork()\n");
id = fork();

if(id == 0){
printf("Child has started:%d\n", getpid());
printf("Parent of this child:%d\n", getppid());
printf("child prints 1 item\n");
sleep(10);
printf("Child prints 2 item\n");
}
else{
printf("Parent has started: %d\n ", getpid());
printf("Parent of the Parent Process: %d\n ", getppid());
}
printf("\nAfter fork");
}
