/*
 * =====================================================================================
 *
 *       Filename:  p6.c
 *
 *    Description:  aldığı arguman kadar recursive olarak programı çağırıyor.hiç arguman almazsa sadece 1 kez çünkü kendisi de bir arguman. her recursive çağırdığında adresler azalıyor çünkü stack grows downward to allocate its arguments and local variables. 
 *
 *        Version:  1.0
 *        Created:  04/05/15 22:27:31
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

main(int argc, char **argv)
{
	int i;
	printf("argc = %d. &argc = 0x%x, &argv = 0x%x, &i = 0x%x\n",argc, &argc, &argv, &i);
	
	if (argc > 0) main(argc-1, argv);
}
