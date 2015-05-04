/*
 * =====================================================================================
 *
 *       Filename:  program4.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2015 03:49:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>

#define READ 0
#define WRITE 1

main (argc, argv)

int argc ;

char* argv[] ;

{

 int pid, fd [2] ;

 

 if (pipe(fd) == -1) 

 { 

 perror("pipe failed"); 

 exit(1); 

 }

 if ((pid = fork( )) < 0) 

 { 

 perror("fork failed"); 

 exit(2); 

 } 

 if ( pid != 0 ) /*  parent, writer */

 {

 close ( fd [READ] ) ; /*  close unused end */

 dup2 ( fd [WRITE], 1) ; /*  duplicate used end to standard out */

 close ( fd [WRITE] ) ; /*  close used end */

 execlp ( argv[1], argv[1], NULL) ; /*  execute writer program */

 }

 else /*  child, reader */

 {

 close ( fd [WRITE] ) ; /*  close unused end */

 dup2 ( fd [READ], 0) ; /*  duplicate used end to standard input */

 close ( fd [READ] ) ; /*  close used end */

 execlp ( argv[2], argv[2], NULL) ; /*  execute reader program */

 }

} 
