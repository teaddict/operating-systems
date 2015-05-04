#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>

sem_t sem1,sem2,sem3,sem4;

void *T_A()
{

sem_wait(&sem1);
printf("A\n");
sem_post(&sem2);
sem_post(&sem3);

}

void *T_B()
{
sem_wait(&sem2);
printf("B\n");
sem_post(&sem1);
}

void *T_C()
{
sem_post(&sem1);
sem_wait(&sem3);
printf("C\n");
sem_post(&sem2);
}

int main(){

pthread_t thread_A,thread_B,thread_C,thread_D;

sem_init(&sem1,0,1);
sem_init(&sem2,0,0);
sem_init(&sem3,0,0);

pthread_create(&thread_A, NULL ,T_A ,(void *)NULL);
pthread_create(&thread_B, NULL ,T_B ,(void *)NULL);
pthread_create(&thread_C, NULL ,T_C ,(void *)NULL);

pthread_join(thread_A,NULL);
pthread_join(thread_B,NULL);
pthread_join(thread_C,NULL);

return 0;
}
