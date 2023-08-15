#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <fcntl.h>


void main(){
int fd,n;
char data, fname[100];
printf("Enter file name which you have to:\n ");
scanf("%s",fname);
fd = open(fname, O_WRONLY | O_APPEND, 0777);
printf("\nFile Opened!\n");
printf("The contents in reverse order are: \n");
n = lseek(fd, 0 , SEEK_END);
lseek(fd, -1, 2);
while(n-->0){
 printf("%c",data);
 lseek(fd,-2,3);
  read(fd, &data, 3);
}
printf("\n");
}
