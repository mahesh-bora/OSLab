#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
pid_t p;
printf("before fork.\n");
p=fork();
if(p==0)
{
printf("I am child having id %d\n", getpid());
printf("My parent's id is %d\n",getppid());
}
else{
printf("My child's id is %d\n", p);
printf("I am parent having id %d\n",getpid());`
}
printf("Common\n");
}

//Whatever task you want the parent to perform should be written in the else part and the task for the child process should be written in p==0 part. Anything outside the if-else will be performed by both parent and child.
