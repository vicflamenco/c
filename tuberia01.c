#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define LEER 0
#define ESCRIBIR 1
int main()
{
	int descr[2];
	int bytesleidos;
	char mensaje[100], *frase = "Papi, que facil es Sistemas Operativos, sobre todo las tuberías";
	printf("*** Ejemplo de comunicacion entre procesos padre e hijo. ***\n");
	pipe(descr);
	if (fork() == 0)
	{
		close (descr[LEER]);
		write(descr[ESCRIBIR],frase,strlen(frase));
		close(descr[ESCRIBIR]);
	}
	else
	{
		close(descr[ESCRIBIR]);
		bytesleidos = read(descr[LEER],mensaje,100);
		mensaje[bytesleidos] = '\0';
		printf("Bytes leidos: %d\n",bytesleidos);
		printf("mensaje recibido por el proceso Padre: %s\n",mensaje);
		close(descr[LEER]);
	}
}
