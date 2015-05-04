/*
 * =====================================================================================
 *
 *       Filename:  exercise2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2015 05:13:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<signal.h>
#include<stdio.h>

void my_routine();

main()
{
printf ("Process ID is: %d\n", getpid( ) ) ;
signal (SIGINT, SIGQUIT) ;
for ( ; ; ) ;
}

void my_routine()
{
printf("have a good day!!!!\n");
}
