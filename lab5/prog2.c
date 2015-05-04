/*
 * =====================================================================================
 *
 *       Filename:  prog2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/04/15 23:12:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <pthread.h>
#include <stdio.h>

	int x=1;
/* This is the lock for thread synchronization */
	pthread_mutex_t my_sync;

void* compute_thread(void * argument) 
{
	printf("X value in thread before sleep = %d\n",x);
	printf("X value in thread is increment by 1 before sleep\n");
	pthread_mutex_lock(&my_sync);
	x++;
	sleep(2);
	printf("X value in thread after sleep = %d\n",x);
	pthread_mutex_unlock(&my_sync);
	return;
}

main( ) 
{
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
/* Initialize the mutex (default attributes) */
	pthread_mutex_init (&my_sync,NULL);
	pthread_create(&tid, &attr, compute_thread,(void *)NULL);
	sleep(1);
	pthread_mutex_lock(&my_sync);
	x++;
	printf("Main thread increments 1 to X, after that X value is %d\n",x);
	pthread_mutex_unlock(&my_sync);
	pthread_join(tid,NULL);
	exit(0);
}
