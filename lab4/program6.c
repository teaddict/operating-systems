/*
 * =====================================================================================
 *
 *       Filename:  program6.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2015 04:03:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <signal.h>
int alarmFlag = 0 ;
void alarmHandler ( ) ;
main(){
signal(SIGALRM, alarmHandler) ; /* Install signal Handler*/
alarm (5) ;
printf ("Looping ...\n") ;
while (!alarmFlag){
pause ( ) ; /*  wait for a signal */
}
printf ("Loop ends due to alarm signal\n") ;
}
void alarmHandler ( )
{
printf ("An ALARM clock signal was received\n") ;
alarmFlag = 1 ;
}

