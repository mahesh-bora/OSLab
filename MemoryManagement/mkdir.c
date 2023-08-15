#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
void main(){
	int fd;
	char fname[1024];
	printf("Name: ");
	scanf("%s", fname);
	fd = mkdir(fname, 0777);
	if(fd==-1){
	 printf("error");
	}
	else{
	 printf("Created");
	}
}
