/*
 * =====================================================================================
 *
 *       Filename:  exercise4.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2015 05:27:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <signal.h>
#include <stdio.h>
char msg[100] ;
main (argc, argv)
int argc ;
char *argv[ ] ;
{
int time ;
void my_secretary ( ) ;
time = atoi (argv[2]) ;
strcpy (msg, argv[1]) ;
signal (SIGALRM, my_secretary) ;
alarm (time) ;
for ( ; ; ) ;
}
void my_secretary ( )
{
printf ("%s\n", msg) ;
exit (0) ;
}

