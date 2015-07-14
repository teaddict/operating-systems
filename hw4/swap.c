/*
 * =====================================================================================
 *
 *       Filename:  swap.c
 *
 *    Description:  kritik bölge için mutual exclusion oluşturabilmek için swap
 *    		    fonksiyonunu kullanarak gereken kodlamayı yazınız. 
 *
 *
 *        Version:  1.0
 *        Created:  03/25/2015 02:48:33 PM
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
#include<stdbool.h> //c doesnt support bool, include this

pthread_mutex_t mutex;

void swap(bool *a, bool *b)
{
	bool temp=*a;
	pthread_mutex_lock(&mutex); 
	*a=*b;
	*b=temp;
	pthread_mutex_unlock(&mutex); 
}

int main()
{
	bool a=false;
	bool b=true;
	
	if(b)
	{
		printf("before swap a is false and b is true\n");
	}
	swap(&a,&b);
	if(a)
	{
		printf("after swap a is true and b is false\n");
	}

return 0;
}




