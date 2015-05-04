/*
 * =====================================================================================
 *
 *       Filename:  program5.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2015 03:57:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

main ( )

{

 alarm (5) ; /*  schedule an alarm signal in 5 seconds */

 printf ("Looping forever ...\n") ;

 while ( 1 );
 printf ("This line should never be executed.\n") ;
}
