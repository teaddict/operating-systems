#include <stdio.h>
#include <unistd.h>
main ( ){
execl ("/bin/ls","ls","-l","-a",NULL) ;
/* program to run - give full path */
/* name of program sent to argv[0] */
/* first parameter (argv[1])*/
/* second parameter (argv[2]) */
/* terminate arg list */
printf ("EXEC Failed\n") ;
/*This above line will be printed only on error and not otherwise*/
}

