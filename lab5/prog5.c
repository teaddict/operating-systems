/*
 * =====================================================================================
 *
 *       Filename:  prog5.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/04/15 23:31:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

/*inculsion part.*/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

/*function prototype for the thread function.*/
void * thread_function1();
void * thread_function2();

/*global variables.*/
int data=0,end=0;

/*global semaphore variables.*/
sem_t sem_var;

int main()
{
	pthread_t t1,t2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	sem_init(&sem_var,0,1);
	pthread_create(&t1,&attr,thread_function1,NULL);
	pthread_create(&t2,&attr,thread_function2,NULL);
	while(end!=2){}
	printf("\n\t****** The value of DATA is:\t%d ******\n",data);
}

/*definition of first thread function.*/
void * thread_function1()
{
	int a;
	printf("\nEntered into thread function:1\n");
	printf("\nThread function:1 waiting to gain access\n");
	sleep(1);
	sem_wait(&sem_var);
	printf("\nAccess gained by thread function:1\n");
	printf("\nThread function:1 using the value of 'DATA' \n");
	a=data;
	a=a+1;
	data=a;
	sem_post(&sem_var);
	printf("\nResources released by thread function:1\n");
	end++;
}

/*definition of second thread function.*/
void * thread_function2()
{
	int b;
	
	printf("\nEntered into thread function:2\n");
	printf("\nThread function:2 waiting to gain access\n");
	sleep(1);
	sem_wait(&sem_var);
	printf("\nAccess gained by thread function:2\n");
	printf("\nThread function:2 using the value of 'DATA' \n");
	b=data;
	b=b+1;
	data=b;
	sem_post(&sem_var);
	printf("\nResources released by thread function:2\n");
	end++;
}
