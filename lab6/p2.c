/*
 * =====================================================================================
 *
 *       Filename:  p2.c
 *
 *    Description:  etext, end
 *
 *        Version:  1.0
 *        Created:  04/05/15 21:49:32
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
extern int I;
extern int J;
int I;

main(int argc, char **argv)
{

	int i;
	int *ii;
	
	printf("&etext = 0x%lx\n", &etext);
	printf("&end = 0x%lx\n", &end);
	printf("\n");
	
	ii = (int *) malloc(sizeof(int));
	
	printf("main = 0x%lx\n", main);
	printf("&I = 0x%lx\n", &I);
	printf("&i = 0x%lx\n", &i);
	printf("&argc = 0x%lx\n", &argc);
	printf("&ii = 0x%lx\n", &ii);
	printf("ii = 0x%lx\n", ii);
}
