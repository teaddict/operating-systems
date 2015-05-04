/*
 * =====================================================================================
 *
 *       Filename:  prog3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/04/15 23:21:25
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

/* This is the initial thread routine */
void* compute_thread (void*);

/* This is the lock for thread synchronization */
pthread_mutex_t my_sync;

/* This is the condition variable */
pthread_cond_t rx;

#define TRUE 1
#define FALSE 0
/* this is the Boolean predicate */

int thread_done = FALSE;
int x=1;

main( ) 
{
/* This is data describing the thread created */
	pthread_t tid;
	pthread_attr_t attr;
/* Initialize the thread attributes */
	pthread_attr_init (&attr);
/* Initialize the mutex (default attributes) */
	pthread_mutex_init (&my_sync, NULL);
/* Initialize the condition variable (default attr) */
	pthread_cond_init (&rx, NULL);
/* Create another thread. ID is returned in &tid */
/* The last parameter is passed to the thread function */
	pthread_create(&tid, &attr, compute_thread, "hello");
/* wait until the thread does its work */
	pthread_mutex_lock(&my_sync);
	while (!thread_done)
	pthread_cond_wait(&rx, &my_sync);
/* When we get here, the thread has been executed */
	x++;
	printf("Main thread increments 1 to X,after that X value is %d\n",x);
	pthread_mutex_unlock(&my_sync);
	exit(0);
}
/* The thread to be run by create_thread */
void* compute_thread(void* dummy) 
{
	printf("X value in thread before sleep = %d\n",x);
	printf("X value in thread is increment by 1 before sleep\n");
/* Lock the mutex - the cond_wait has unlocked it */
	pthread_mutex_lock (&my_sync);
	x++;
	sleep(2);
	printf("X value in thread after sleep = %d\n",x);
/* set the predicate and signal the other thread */
	thread_done = TRUE;
	pthread_cond_signal (&rx);
	pthread_mutex_unlock (&my_sync);
	return;
}
