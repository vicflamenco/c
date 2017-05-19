#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t varmutex;

void *funcion01(void *arg)
{
	int i;
	pthread_mutex_lock(&varmutex);
	for (i=0; i<100; i++)
	{
		printf("*");
		fflush(stdout);
		sleep(1);
	}
	pthread_mutex_unlock(&varmutex);
	return NULL;
}

void *funcion02(void *arg)
{
	int i;
	pthread_mutex_lock(&varmutex);
	for (i=0; i<100; i++)
	{
		printf("o");
		fflush(stdout);
		sleep(1);
	}
	pthread_mutex_unlock(&varmutex);
	return NULL;
}

int main(void)
{
	int i;
	pthread_t h1, h2;
	pthread_mutex_init(&varmutex,NULL);

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

	pthread_mutex_destroy(&varmutex);

	printf("\n");
	exit(0);
}
