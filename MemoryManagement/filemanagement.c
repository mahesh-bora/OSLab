/*
Write a C program to implement I/O System Calls of 
Linux. 
a) Create a file  
b) Read contents of a file  
c) Write to a file  
d) Read contents of a file in a reverse order  
e) Search the file to find the given pattern ( Grep command)  
f) Delete a file  
g) To print file status using stat  
h)To print file status using fstat  
Using these system calls also write a program to,  
1) Write a program that creates a file with a 4K bytes free space. Such files are  called files with holes.  
2) Write a program that copies the contents of an existing file into another file.  The names of the two file should be read as an input from the command line.  
*/




#include <stdio.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <string.h> 
#include <stdbool.h> 
#include <stdlib.h> 
void search_string(char *filename, char *pattern)
{ 
 int fd = open(filename, O_RDONLY); 
 if (fd < 0) 
 { 
 printf("Error opening file\n"); 
 return; 
 } 
 char buffer[1024]; 
 int bytes_read; 
 bool found = false; 
 while (bytes_read = read(fd, buffer, sizeof(buffer)) > 0)  { 
 char *found_str = strstr(buffer, pattern);  if (found_str != NULL) 
 { 
 found = true; 
 break; 
 } 
 } 
 if (bytes_read < 0) 
 { 
 printf("Error reading file\n"); 
 close(fd); 
 return; 
 } 
 if (found) 
 { 
 printf("String %s is present in file\n", pattern);  } 
 else 
 { 
 printf("String %s is not present in file\n", pattern);  }
 close(fd); 
} 
void call_stat(char *filename) 
{ 
 struct stat file_stat; 
 if (stat(filename, &file_stat) == 0) 
 { 
 printf("File size: %ld bytes\n", file_stat.st_size); 
 printf("File permissions: %o\n", file_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));  printf("File inode: %lu\n", file_stat.st_ino); 
 printf("File device: %lu\n", file_stat.st_dev); 
 printf("File number of hard links: %lu\n", file_stat.st_nlink); 
 printf("File UID of owner: %u\n", file_stat.st_uid); 
 printf("File GID of owner: %u\n", file_stat.st_gid); 
 printf("File last access time: %ld\n", file_stat.st_atime); 
 printf("File last modification time: %ld\n", file_stat.st_mtime); 
 printf("File last status change time: %ld\n", file_stat.st_ctime); 
 } 
 else 
 { 
 printf("stat() failed"); 
 } 
} 
void call_fstat(char *filename) 
{ 
 int fd = open(filename, O_RDONLY); 
 if (fd < 0) 
 { 
 perror("Error opening file"); 
 return; 
 }
 struct stat fd_stat; 
 if (fstat(fd, &fd_stat) == 0) 
 { 
 printf("File size: %ld bytes\n", fd_stat.st_size); 
 printf("File permissions: %o\n", fd_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));  printf("File inode: %lu\n", fd_stat.st_ino); 
 printf("File device: %lu\n", fd_stat.st_dev); 
 printf("File number of hard links: %lu\n", fd_stat.st_nlink); 
 printf("File UID of owner: %u\n", fd_stat.st_uid); 
 printf("File GID of owner: %u\n", fd_stat.st_gid); 
 printf("File last access time: %ld\n", fd_stat.st_atime); 
 printf("File last modification time: %ld\n", fd_stat.st_mtime); 
 printf("File last status change time: %ld\n", fd_stat.st_ctime); 
 } 
 else 
 { 
 perror("fstat() failed"); 
 } 
 close(fd); 
} 
int main() 
{ 
 char data; 
 char buf[100], pat[10], temp[1024]; 
 int ch1, ch = 0, fd, nfd, n, m, charcount = 0, user; 
 int ret, resp, i = 0, n1; 
 char fname[10], dname[10]; 
 char *newline; 
 FILE *fp; 
 struct stat *sb; 
 do 
 { 
 printf("Perform different Operations on Files\n");
 printf("1. Create\n2. Read\n3. Write\n4. Read in Reverse Order\n5. Search\n6. Delete\n7.To  add contents of two files\n8. Call f_stat\n9. Call stat\n10. files with holes"); 
 printf("\nEnter your choice: "); 
 scanf("%d", &ch1); 
 switch (ch1) 
 { 
case 1: 
 printf("Enter file name which you have to create: "); 
 scanf("%s", fname); 
 fd = creat(fname, 0777); 
 printf("\nFile Created\n"); 
 printf("Enter the contents to write "); 
 scanf("%s", buf); 
 charcount = strlen(buf); 
 write(fd, buf, charcount); 
 close(fd); 
 break; 
 case 2: 
 printf("Enter file name which you have to open: "); 
 scanf("%s", fname); 
 fd = open(fname, O_RDONLY, 0777); 
 printf("\nFile Opened\n"); 
 printf("The contents are \t"); 
 while (read(fd, &data, 1) > 0) 
 { 
 printf("%c", data); 
 } 
 close(fd); 
 break; 
 case 3: 
 printf("Enter file name which you have to open: "); 
 scanf("%s", fname); 
 fd = open(fname, O_WRONLY | O_APPEND, 0777);
 printf("File Opened\n"); 
 printf("Enter the contents to write: ");  scanf("%s", buf); 
 charcount = strlen(buf); 
 write(fd, buf, charcount); 
 close(fd); 
 break; 
 case 4: 
 printf("Enter file name which you have to open: ");  scanf("%s", fname); 
 fd = open(fname, O_RDONLY, 0777);  printf("\nFile Opened"); 
 printf("\nThe contents in reverse order are: ");  n = lseek(fd, 0, 2); 
 lseek(fd, -1, 2); 
 while (n-- > 0) 
 { 
 read(fd, &data, 1); 
 printf("%c", data); 
 lseek(fd, -2, 1); 
 } 
 printf("\n"); 
 close(fd); 
 break; 
 case 5: 
 printf("\nEnter file name: "); 
 scanf("%s", fname); 
 printf("Enter the pattern to be searched: ");  scanf("%s", pat); 
 fd = open(fname, O_RDONLY); 
 printf("File Opened\n"); 
 search_string(fname, pat); 
 break;
 case 6: 
 printf("Enter file name which you have to delete: ");  scanf("%s\n", fname); 
 unlink(fname); 
 break; 
 case 7: 
 printf("Enter the name of first file: "); 
 scanf("%s", fname); 
 printf("Enter the name of second file: "); 
 scanf("%s", dname); 
 fd = open(fname, O_WRONLY | O_APPEND, 0777);  printf("File opened for writing...\n"); 
 nfd = open(dname, O_RDONLY, 0777); 
 printf("File opened to read...\n"); 
 n = lseek(nfd, 0, 2); 
 lseek(nfd, i, 0); 
 write(fd, " ", 1); 
 while (n1 = (read(nfd, buf, sizeof(buf))) > 0)  { 
 if (write(fd, buf, n) != n) 
 { 
 printf("Error : cannot write in file\n");  close(fd); 
 close(nfd); 
 } 
 } 
 printf("Contents of file2 is copied to contents of file 1\n");  close(fd); 
 close(nfd); 
 break; 
 case 8: 
 printf("Enter file name: "); 
 scanf("%s", fname);
 call_fstat(fname); 
 break; 
 case 9: 
 printf("Enter file name: "); 
 scanf("%s", &fname); 
 call_stat(fname); 
 break; 
 case 10: 
 printf("ENTER FILE NAME TO BE CREATED : ");  scanf("%s", fname); 
scanf("%s", fname); 
 fd = creat(fname, 0777); 
 if (fd == -1) 
 printf("UNABLE TO CREATE FILE\n");  else 
 { 
 printf("FILE CREATED\n"); 
 ftruncate(fd, 4096); 
 printf("File created with 4k bytes free space\n");  close(fd); 
 } 
 break; 
 } 
 printf("\nDo you want to continue [1/0]: ");  scanf("%d", &resp); 
 if (resp == 1) 
 { 
 user = 1; 
 } 
 else 
 { 
 user = 0; 
 } 
 } while (user);
 }


