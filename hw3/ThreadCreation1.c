//ThreadCreation.c
//Simple thread creation, termination example
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int test=0;
//---------------------------------------------------------
// some threads will executes the codes in this function
void *Thread1Proc(void *parameter){

	int *p = (int *)parameter;
	int i = 0;

	printf("I am Thread1Proc. My argument is: %d\n", *p);

	i = 0;
	while (i < 100000000){
		if (i % 10000000 == 0)
			printf("I am Thread1Proc. My argument is: %d. i: %d\n", *p, i);

		i++;
	} /* end-while */

	return 0;    // Exit

}//end-Thread1Proc


//---------------------------------------------------------
// some threads will executes the codes in this function
void *Thread2Proc(void *parameter){

	double *p = (double *)parameter;
	int ch;

	printf("I am Thread2Proc. My argument is: %5.2lf\n", *p);

	test=2;

	ch = getchar();
	printf("ThreadProc2: ch: %d\n", ch);

	return 0;    // Exit

} //end-Thread1Proc

//---------------------------------------------------------
int main(int argc, char* argv[]){

	//thread pointers
	pthread_t threadId1, threadId2, threadId3;
	int arg1 = 66;
	int arg2 = 77;
	double arg3 = 88.8;

	// Create a thread executing Thread1Proc
	pthread_create(&threadId1, NULL, Thread1Proc, (void *)&arg1);

	// Create a second thread executing Thread1Proc
	pthread_create(&threadId2, NULL, Thread1Proc, (void *)&arg2);

	// Create a third thread executing Thread2Proc
	pthread_create(&threadId3, NULL, Thread2Proc, (void *)&arg3);

	// Have main thread wait for all threads to finish
	pthread_join(threadId1, NULL);
	printf("Thread1 terminated\n");

	pthread_join(threadId2, NULL);
	printf("Thread2 terminated\n");

	pthread_join(threadId3, NULL);
	printf("-->All threads have terminated. Main thread is now exiting...gv: %d\n", test);

	return 0;
} //end-main
