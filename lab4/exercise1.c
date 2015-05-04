#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) 
{
    int pid, status;    
    int pid1, pid2;
    int filedes[2];
    char message[1000],buffer[1000];

    pipe(filedes);
 
    
            pid1 = fork();      
         
            if(pid1==0)
            {
             
             close(filedes[0]);	
             FILE *f = popen("ls", "r");
    	     while (fgets(message, 100, f) != NULL) { }
    	     pclose(f);
	     write(filedes[1],message,sizeof(message));
                exit(-1);
            }
            else
            {
                wait(&status);
                close(filedes[1]);
		int k=read(filedes[0],buffer,sizeof(buffer));
                FILE *f = fopen("/home/schwappkopf/os_temp/hw4/test.txt", "w");
    		fputs(message, f);
   		
    		fclose(f);
                exit(-1);
            }
    return 0;
}
