
// Simple example to show how fork works
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	int p1_pid,p2_pid;

	//Create a new process
	if ((p1_pid = fork())== 0)
	{
	printf("PID: %d\n",getpid());
	printf("Child 1: Bye \n");
	}
	else {
	if ((p2_pid = fork()) == 0) 
	{
	printf("PID: %d\n",getpid());
	printf("Child 2: Bye \n");
	} 
	else
	{
	printf("PID: %d\n",getpid());
	printf("Parent\n");
	}
	
	}

	return 0;
} // end-main
