#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char **argv) {
if(argc!=3)
{
printf("eksik ya da fazla parametre girildi...\n");
return -1;
}
double a=atof(argv[1]);
double b=atof(argv[2]);
printf("%lf + %lf = %lf \n",a,b,a+b);
return 0;
}

