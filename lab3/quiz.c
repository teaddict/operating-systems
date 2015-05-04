/*
 * =====================================================================================
 *
 *       Filename:  quiz.c
 *
 *    Description:  Write, compile and run a C program (give the name exp3.c). The program involves two threads: a reader and write
 *    threads. The reader thread will read integers from the user and writer thread will display strings related to the integers
 *    entered through the reader thread. The writer thread will print “Hello!!!” and “How are you?” for the integers 1 and 2,
 *    respectively. It will not print anything and the threads will just exit if the integers are different than 1 and 2.
 *
 *
 *        Version:  1.0
 *        Created:  03/17/2015 05:04:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict, 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<pthread.h>
#include<stdio.h>

void ReadThread(void *argument)
{
	int *p= (int *)argument;
	if(*p==1 || *p==2)
	{
		printf("reader thread function -> number = %d\n",*p);
	}
	else
	{
		pthread_exit(NULL);
	}	

}//end ReadThread

void WriteThread(void *argument)
{

	int *p=(int *)argument;

	switch(*p)
	{
	case 1:
		printf("Hello!!!\n");
		break;
	case 2:
		printf("How are you?\n");
		break;
	default:
		pthread_exit(NULL);
	}

}//end WriteThread

main()
{

	pthread_t threadRead,threadWrite;
	int k;

	do
	{
	printf("enter a number: ");
	scanf("%d",&k);

	pthread_create(&threadRead,NULL,(void*)ReadThread,&k);
	pthread_create(&threadWrite,NULL,(void*)WriteThread,&k);

	pthread_join(threadRead,NULL);
	pthread_join(threadWrite,NULL); 
	
	}while(k!=1 || k!=2);

	return 0;
}//end main




