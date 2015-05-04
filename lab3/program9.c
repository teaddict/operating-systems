/*
 * =====================================================================================
 *
 *       Filename:  program9.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/18/2015 10:33:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <pthread.h>
#include <stdio.h>
void ChildThread (int argument)
{
int i;
printf("I am thread\n");
//pthread_exit(NULL);
}
int main(void)
{
pthread_t hThread;
pthread_create(&hThread,NULL,ChildThread,NULL);
pthread_join (hThread, NULL);
printf ("Parent is continuing....\n");
return 0;
}

