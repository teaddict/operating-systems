#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
printf("\n%d: Hello World!\n", threadid);
pthread_exit(NULL);
}//end

int main( )
{
pthread_t threads [NUM_THREADS];
int rc, t;
for(t=0; t < NUM_THREADS; t++)
{
printf ("Creating thread %d\n", t);
rc=pthread_create(&threads[t],NULL,PrintHello,(void *)t);
if (rc) 
{
printf("ERROR;return code from pthread_create() is %d\n",rc);
exit(-1);
}//end if
}//end for
pthread_exit(NULL);
}//end main

