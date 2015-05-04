#include <stdio.h>
#include <unistd.h>
main (argc, argv )
int argc ;
char *argv[ ] ;
{
execvp ("echo",&argv[0] ) ;
/* program to load - PATH searched
printf ("EXEC Failed\n") ;
/*This above line will be printed only on error and not otherwise */
}

