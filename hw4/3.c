/*
 * =====================================================================================
 *
 *       Filename:  3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2015 12:49:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t S1,S2,S3;

void *ThreadProc1(void *arg)
{
sem_wait(&S1);
printf("section a1\n");
printf("section a2\n");
sem_post(&S1);
sem_post(&S2);
}

void *ThreadProc2(void *arg)
{

printf("section b1\n");
sem_wait(&S2);
printf("section b2\n");
sem_post(&S2);
sem_post(&S3);
}

void *ThreadProc3(void *arg)
{
printf("section c1\n");
sem_wait(&S3);
printf("section c2\n");
sem_post(&S3);
}


int main(int argc,char *argv[])
{
pthread_t threadId1,threadId2,threadId3;

sem_init(&S1,0,1);
sem_init(&S2,0,0);
sem_init(&S3,0,0);
pthread_create(&threadId1,NULL,ThreadProc1,NULL);
pthread_create(&threadId2,NULL,ThreadProc2,NULL);
pthread_create(&threadId3,NULL,ThreadProc3,NULL);

  
pthread_join(threadId1,NULL);
pthread_join(threadId2,NULL);
pthread_join(threadId3,NULL);

sem_destroy(&S1);
sem_destroy(&S2);
sem_destroy(&S3);
return 0;
}
