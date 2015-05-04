#include <pthread.h>
#include <stdio.h>
void ChildThread (int *argument)
{
int i;
for (i=0; i<*argument; i++)
{
printf(" Child Count - %d\n", i);
}
pthread_exit(0);
}
int main(void)
{
pthread_t hThread;
int k=15;
pthread_create (&hThread,NULL,(void *)ChildThread,&k);
pthread_join (hThread, NULL);
printf ("Parent is continuing....\n");
return 0;
}

