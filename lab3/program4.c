#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int this_is_global;

void thread_func( void *ptr );

int main( ) 
{
int local_main;
int pid, status;
pthread_t thread1, thread2;
printf("First, we create two threads to ");
printf("see better what context they share...\n");
this_is_global=1000;
printf("Set this_is_global=%d\n",this_is_global);
pthread_create(&thread1,NULL, (void*)&thread_func, (void*) NULL);
pthread_create(&thread2,NULL, (void*)&thread_func, (void*) NULL);
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
printf("After threads, this_is_global=%d\n",this_is_global);
printf("\n");
printf("Now that the threads are done, let's call fork..\n");
local_main=17;
this_is_global=17;
printf("Before fork(), local_main=%d, ",local_main);
printf("this_is_global=%d\n",this_is_global);
pid=fork();
if (pid == 0) { /* this is the child */
printf("In child, pid %d: &global: ", getpid());
printf("%X, &local: %X\n", &this_is_global, &local_main);
local_main=13; this_is_global=23;
printf("Child set local main=%d, ",local_main);
printf("this_is_global=%d\n",this_is_global);
exit(0);
}
else { /* this is parent */
printf("In parent, pid %d: &global: ", getpid());
printf("%X, &local: %X\n", &this_is_global, &local_main);
wait(&status);
printf("In parent, local main=%d, ",local_main);
printf("this_is_global=%d\n",this_is_global);
}
exit(0);
}
void thread_func(void *dummy)
{
int local_thread;
printf("Thread %u, ",(unsigned int)pthread_self());
printf("pid %d,addresses:&global:%X, ",getpid(),&this_is_global);
printf("&local: %X\n", &local_thread);
this_is_global++;
printf("In Thread %u, ", (unsigned int)pthread_self());
printf("incremented this_is_global=%d\n", this_is_global);
pthread_exit(0);
}

