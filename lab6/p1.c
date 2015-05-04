/*
 * =====================================================================================
 *
 *       Filename:  p1.c
 *
 *    Description:  segmentation violation
 *
 *        Version:  1.0
 *        Created:  04/05/15 21:42:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

main( )
{
	char *s;
	char c;
	s=(char *)0;
	c=*s;
}
