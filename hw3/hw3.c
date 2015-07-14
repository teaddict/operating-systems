#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int tek=1;
int cift=0;

void *ThreadTek(void *parameter)
{

int *p=(int *)parameter;
while(1)
{
if(tek>1000)
{
tek=1;
}
tek=tek+2;
}

}//end func

void *ThreadCift(void *parameter)
{
int *p=(int *)parameter;
while(1)
{
if(cift>1000)
{
cift=0;
}
cift=cift+2;
}

}//end func

void *ThreadMenu(void *parameter)
{

char c;

while(1)
{

printf("tek (t), çift (c),çıkış(e) için giriniz: ");
c=getchar();

if(c=='t')
{
printf("tek değeri: %d\n",tek);
}
else if(c=='c')
{
printf("cift değeri: %d\n",cift);
}
else if(c=='e')
{
pthread_exit(NULL);
return 0;
}
/*  else
{
printf("hatalı komut\n");
}*/
}//while
}//end func

main()
{
pthread_t thread1,thread2,thread3;

pthread_create(&thread1,NULL,ThreadTek,NULL);
pthread_create(&thread2,NULL,ThreadCift,NULL);
pthread_create(&thread3,NULL,ThreadMenu,NULL);


pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
pthread_join(thread3,NULL);
printf("All threads are terminated..\n");

return 0;
}


