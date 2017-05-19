#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *funcion01(void *arg)
{
	int i;
	for (i=0; i<100; i++)
	{
		printf("*");
		fflush(stdout);
		sleep(1);
	}
	return NULL;
}

void *funcion02(void *arg)
{
	int i;
	for (i=0; i<100; i++)
	{
		printf("o");
		fflush(stdout);
		sleep(1);
	}
}

int main(void)
{
	int i;
	pthread_t h1, h2;

	if (pthread_create(&h1,NULL,funcion01,NULL))
	{
		printf("Error creando hilo");
		abort();
	}

	if (pthread_create(&h2, NULL, funcion02, NULL))
	{
		printf("Error creando hilo");
		abort();
	}

	pthread_join(h1,NULL);
	pthread_join(h2,NULL);

	printf("\n");
	exit(0);
}
