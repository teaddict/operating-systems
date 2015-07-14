#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() 
{
float x,y;
pid_t pid;

printf("Enter first num: ");
scanf("%f",&x);
printf("Enter second num: ");
scanf("%f",&y);

if((pid=fork())== -1)
{
printf("can not fork..\n");
exit(1);
}
if(pid==0) //child
{

pid=getpid();
char command1[50], command2[50]; // Added
char *temp[] = {NULL, command1, command2, NULL}; // Modified
temp[0]="sum";
sprintf(temp[1],"%f",x); // remove *
sprintf(temp[2],"%f",y); // remove *
execv("sum",temp);
}
else
{
wait(NULL);
printf("parentPID: %d childPID: %d works now.\n",getpid(),pid);
}

return 0;
}
