 // C Program for vowels counting using vfork 
#include<stdio.h> 
#include<sys/types.h> 
int main() 
{ 
intj,n,a,i,e,o,u; 
char str[50]; 
a=e=i=o=u=0; 
pid_tpid; 
if((pid=vfork())<0) 
{ 
perror("FORK ERROR"); 
exit(1); 
} 
if(pid==0) 
{ 
printf(" 
Counting Number of Vowels using VFORK"); 
printf(" 
-------- ------ -- ------ ----- -----"); 
printf(" 
Enter the String:"); 
gets(str); 
_exit(1); 
}
else 
{ 
n=strlen(str); 
for(j=0;j<n;j++) 
{ 
if(str[j]=='a' || str[j]=='A') 
a++; 
else if(str[j]=='e' || str[j]=='E') 
e++; 
else if(str[j]=='i' || str[j]=='I') 
i++; 
else if(str[j]=='o' || str[j]=='O') 
o++; 
else if(str[j]=='u' || str[j]=='U') 
u++; 
} 
printf(" 
Vowels Counting"); 
printf(" 
------ --------"); 
printf(" 
Number of A : %d",a); 
printf(" 
Number of E : %d",e); 
printf(" 
Number of I : %d",i); 
printf(" 
Number of O : %d",o); 
printf(" 
Number of U : %d",u); 
printf(" 
Total vowels : %d 
",a+e+i+o+u); 
exit(1); 
} 
}

