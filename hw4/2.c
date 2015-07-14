/** =====================================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/25/2015 03:57:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


int index=0;
int size=14;
char msg[15]={'o', 'd' , 'e', 'v',' ','3',':',' ','m','e','r','h','a','b','a'};
pthread_mutex_t mutex;


void *Thread1Proc(void *parameter){

    int ind=0;
    long int i=0;
    while(ind<15){
    pthread_mutex_lock(&mutex);
        ind=index;
        index++;
        while(i<10000000){
            if((i%2000000)==0)
                printf("_");
            i++;
        }
        i=0;
        printf("%c",msg[ind]);
	pthread_mutex_unlock(&mutex);
    }
	index=0;
	return 0;    // Exit

}//end-Thread1Proc

void *Thread2Proc(void *parameter){

    int ind=0;
    long int i=0;
    while(ind<15){
    pthread_mutex_lock(&mutex);
        ind=index;
        index++;
        while(i<10000000){	
            if((i%1000000)==0)
                printf(".");
            i++;
        }
        i=0;
        printf("%c",msg[ind]);
	pthread_mutex_unlock(&mutex);
    }
	index=0;
	return 0;    // Exit

}//end-Thread2Proc


int main(int argc, char* argv[]){

	//thread pointers
	pthread_t threadId1, threadId2;
	//
	//		// Create a thread executing Thread1Proc
	
	pthread_create(&threadId1, NULL, Thread1Proc,NULL);
	pthread_mutex_init(&mutex,NULL);
	//
	//				// Create a second thread executing Thread2Proc
	pthread_create(&threadId2, NULL, Thread2Proc,NULL);
	
	pthread_join(threadId1,NULL);
	pthread_join(threadId2,NULL);
	
	pthread_mutex_destroy(&mutex);	
	
return 0;
}
