/*
 * =====================================================================================
 *
 *       Filename:  program3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2015 02:54:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <sys/file.h>
main (argc, argv)
int argc ;
char *argv[ ] ;
{
int
fd ;
/*  file descriptor or pointer */
fd = open (argv[1], O_CREAT | O_TRUNC | O_RDWR, 0777) ;
/*  open file named in argv[1] */
dup2 (fd, 1);
/*  and assign it to fd file pointer */
close (fd);
/*  duplicate fd with 1 which is */
/* standard output (the monitor) */
execvp (argv[2], &argv[2]) ;
/*  the output is not printed on screen*/
/* but is redirected to “output” file */
printf ("End\n") ;
/*  should never execute */
}
 

