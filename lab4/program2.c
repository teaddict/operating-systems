/*
 * =====================================================================================
 *
 *       Filename:  program2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2015 02:49:02 PM
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

char* phrase="This is the lab time" ;

main(){
int fd [2], bytesread ;
char message [100] ;
pipe ( fd ) ;
if(fork ( ) == 0){
/*  child, writer */
close ( fd [READ] ); /*  close unused end */
write ( fd [WRITE], phrase, strlen (phrase) + 1) ;
close ( fd [WRITE] ); /*  close used end */
}
else{
/*  parent, reader */
close ( fd [WRITE] ); /*  close unused end */
bytesread = read (fd [READ], message, 100);
printf ("Read %d bytes : %s\n", bytesread, message);
close ( fd [READ] ); /*  close used end */
}
}

