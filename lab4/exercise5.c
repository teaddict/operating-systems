/*
 * =====================================================================================
 *
 *       Filename:  exercise5.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2015 05:30:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <signal.h>
main(){
int pid1, pid2 ;
pid1 = fork ( ) ;
if (pid1 == 0) {
while (1) {
/*first child */
/* infinite loop */
printf ("pid1 is alive\n") ;
sleep (1) ;
}
}
pid2 = fork ( ) ;
if (pid2 == 0) {
while (1) {
/*second child */
/* infinite loop */
printf ("pid2 is alive\n") ;
sleep (1) ;
}
}
sleep (3) ;
kill (pid1,SIGSTOP) ;
sleep (3) ;
kill (pid1,SIGCONT) ;
sleep (3) ;
kill (pid1,SIGINT) ;
kill (pid2,SIGINT) ;
}


