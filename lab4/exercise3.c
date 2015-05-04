/*
 * =====================================================================================
 *
 *       Filename:  exercise3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2015 05:23:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <signal.h>
void my_routine ( ) ;
int pid ;
main(){
pid = fork ( );
signal (SIGINT, my_routine) ;
for ( ; ; ) ;
}
void my_routine ( )
{
printf ("My pid = %d\n", pid) ;
}

