/*
 * =====================================================================================
 *
 *       Filename:  p7.c
 *
 *    Description:  break stack -> It performs infinite recursion, and
at each recursive step it allocates 10000 bytes of stack memory in the variable iptr. this program allocates too much stack memory and get segmentation fault
 *
 *        Version:  1.0
 *        Created:  04/05/15 22:33:22
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
	char c;
	char iptr[10000];

	printf("&c = 0x%lx, iptr = 0x%x ... ", &c, iptr);
	fflush(stdout);

	c = iptr[0];
	printf("ok\n");
	main( );
}

