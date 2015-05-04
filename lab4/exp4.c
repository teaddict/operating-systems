/* Pipes are uni-directional message boxes
   used to exchange messages between 2 related
   processes, i.e., parent-child, siblings of
   a parent process etc.
 */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int alarmFlag = 0 ;
void alarmHandler ( ) ;

int main(int argc, char *argv[]){
	int filedes[2];
	int pid;
	
	signal(SIGALRM, alarmHandler) ; /*Install signal Handler*/

	pipe(filedes);
	
	pid=fork();
	if (pid== 0)
	{
		// Child.
		if(getpid()%2==0)
		{
		char message[100]= "save me";

		printf("Child -> PID is %d and message to be sent is %s\n",getpid(),message);
		close(filedes[0]);
		write(filedes[1], message, strlen(message));
		}
		else
		{
		char message[100]= "kill me";

		printf("Child -> PID is %d and message to be sent is %s\n",getpid(),message);
		
		close(filedes[0]);
		write(filedes[1], message, strlen(message));
		}	
		alarm (5) ;
		printf("Alarm clock signal was scheduled\n");
		while (!alarmFlag){
			pause ( ) ; /* wait for a signal */
		}

		printf("Child -> I am done\n");
	}
	else {
		/* Parent. Echo server */
		char message[100];
		int len;

		//close write end of the pipe
		
		close(filedes[1]);
		memset(message, 0, 100);
		len = strlen(message);
		read(filedes[0], &message[len], 100);
		if(!strcmp(message,"kill me"))
		{
		printf("Parent -> Incoming Message from Child is : kill me \n");
		kill(pid, SIGQUIT);  
		printf("Parent -> Child is killed\n");
		}
		else
		{
		wait(NULL);
		printf("Parent -> Childprocess is done\n");
		}
	} /* end-else */
	
	return 0;
} /* end-main */

void alarmHandler ( )
{
printf ("Handler -> An ALARM clock signal was received\n") ;
alarmFlag = 1 ;
}
