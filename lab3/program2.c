#include <stdio.h>
#include <pthread.h>

int glob_data = 5 ;

void *kidfunc(void *p)
{
printf ("Kid here. Global data was %d.\n", glob_data) ; // 5
//cünkü thread create edildiğinde glob_data=5 di , sonra glob_data=10 oluyor!
glob_data = 15 ;
printf("Kid Again. Global data was now %d.\n", glob_data); //15
}
main ( )
{
pthread_t kid ;
pthread_create (&kid, NULL, kidfunc, NULL) ;
//burada create edildiğinde glob_data değerini alıyor, yani 5 olarak
printf ("Parent here. Global data = %d\n", glob_data) ; //5
glob_data = 10 ;
pthread_join (kid, NULL) ;
printf ("End of program. Global data = %d\n", glob_data) ; //15
}

