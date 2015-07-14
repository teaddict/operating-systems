
// Simple example to show how fork works
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	int p1_pid,p2_pid,p3_pid,p4_pid;

	//Create a new process
	if ((p1_pid = fork())== 0)
	printf("I am P1 and I am proud of it.\n");
	else {
	if ((p2_pid = fork()) == 0) 
	{
	p3_pid == fork();
	printf("I am P3. I like it.\n");
	p4_pid == fork();
	printf("I am P4. Get used to it.\n");
	} 
	else
	printf("I am the parent process, obey or die!\n");
	}

	return 0;
} // end-main
