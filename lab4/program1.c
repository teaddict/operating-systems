/*
 * =====================================================================================
 *
 *       Filename:  program1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2015 02:34:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#define SIZE 1024
main(){
int pfd[2];
int nread;
int pid;
char buf[SIZE];
if (pipe(pfd) == -1){
perror("pipe failed");
exit(1);
}
if ((pid = fork()) < 0){
perror("fork failed");
exit(2);
}
if (pid == 0){
/*  child */
close(pfd[1]);
while ((nread = read(pfd[0], buf, SIZE)) != 0)
printf("child read %s\n", buf);
close(pfd[0]);
}
else {
/*  parent */
close(pfd[0]);
strcpy(buf, "hello...");
/*  include null terminator in write */
write(pfd[1], buf, strlen(buf)+1);
close(pfd[1]);
}
}

