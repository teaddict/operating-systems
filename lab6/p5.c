/*
 * =====================================================================================
 *
 *       Filename:  p5.c
 *
 *    Description:  malloc() effects
 *
 *        Version:  1.0
 *        Created:  04/05/15 22:17:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

extern end;
extern etext;

main( )
{

char *s;
char c;
char *buf;

printf("&etext = 0x%lx\n", &etext);
printf("&end = 0x%lx\n", &end);

printf("before malloc, sbrk(0)= 0x%lx\n", sbrk(0));
buf = (char *) malloc(1000);
printf("after, malloc, sbrk(0)= 0x%lx\n", sbrk(0));

printf("&c = 0x%lx\n", &c);
printf("\n");

printf("Enter memory location in hex (start with 0x): ");
fflush(stdout);
scanf("0x%x", &s);

printf("Reading 0x%x: ", s);
fflush(stdout);
c = *s;
printf("%d\n", c);
printf("Writing %d back to 0x%x: ", c, s);
fflush(stdout);
*s = c;
printf("ok\n");
}
