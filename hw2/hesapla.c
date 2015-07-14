#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() 
{
float x,y;
pid_t pid;

printf("Enter first num:  ");
scanf("%f",&x);
printf("Enter second num:  ");
scanf("%f",&y);

if((pid=fork())== -1)
{
printf("can not fork..\n");
exit(1);
}
if(pid==0) //child
{

pid=getpid();
char command1[50], command2[50];
char *temp[] = {NULL,NULL,NULL,NULL};
temp[0]="toplama";
sprintf(temp[1],"%f",x); //here I want to convert float number to char but it doesn't work
sprintf(temp[2],"%f",y);
execv("toplama",temp);
}
else
{
wait(NULL);
printf("parentPID: %d childPID: %d works now\n",getpid(),pid);
}

return 0;
}

