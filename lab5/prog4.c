/*
 * =====================================================================================
 *
 *       Filename:  prog4.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/04/15 23:26:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

/*Program to demonstrate the usage of semaphore variable in
controlling the access to specific resources.
* This program contains two functions which display their own
messages.
* The display is suitably controlled by the use of semaphore
variable.
* It is a program in which a semaphore variable is shared between
the main function and a thread function.
* This module can be compiled using 'cc program4.c –o program4 –
lpthread' and executed './program4'*/
/*inculsion part.*/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

/*function prototype for the thread function.*/
void * display_function();

/*global semaphore variable to be shared.*/
sem_t sem_var;

int main()
{
	pthread_t tid;
	pthread_attr_t attr;
	int i;
/*initialising the semaphore variable with an initial value 0
(third arguement.)*/
	sem_init(&sem_var,0,0);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_create(&tid,&attr,display_function,NULL);
	for(i=0;i<5;i++){
		printf("\n Displaying from the main function:\t%d\n",i+1);
		/*waiting for the resources.*/
		sem_wait(&sem_var);
	}
/*destroying the semaphore variable.*/
	sem_destroy(&sem_var);
}
void * display_function()
{
	int i;
	for(i=0;i<5;i++){
		printf("\n***** Displaying from the thread function.:\t%d\n",i+1);
	/*releasing resources.*/
	sem_post(&sem_var);
	sleep(1);
	}
}
