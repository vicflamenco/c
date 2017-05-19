#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main ()
{
	int bandera, fd;
	char *nfifo = "fifo";
	char mensaje[100];
	bandera = mkfifo(nfifo, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);

	if (!bandera)
	{
		while (strcmp(mensaje,"q"))
		{
			fd = open(nfifo, O_RDONLY);
			if (fd == -1)
				perror("\nError al abrir tubería\n");
			else
			{
				read(fd, mensaje, 100);
				float operador1, operador2, resultado;
				
				if (strchr(mensaje,'+') > 0)
				{
					operador1 = (float)atof(strtok(mensaje,"+"));
					operador2 = (float)atof(strtok(NULL,"+"));
					resultado = operador1 + operador2;
					sprintf(mensaje, "%f", resultado);
				}
				else if (strchr(mensaje,'-')>0)
				{
					operador1 = (float)atof(strtok(mensaje,"-"));
					operador2 = (float)atof(strtok(NULL,"-"));
					resultado = operador1 - operador2;
					sprintf(mensaje, "%f", resultado);
				}
				else if (strchr(mensaje,'*')>0)
				{
					operador1 = (float)atof(strtok(mensaje,"*"));
					operador2 = (float)atof(strtok(NULL,"*"));
					resultado = operador1 * operador2;
					sprintf(mensaje, "%f", resultado);
				}
				else if (strchr(mensaje,'/')>0)
				{
					operador1 = (float)atof(strtok(mensaje,"/"));
					operador2 = (float)atof(strtok(NULL,"/"));
					resultado = operador1 / operador2;
					sprintf(mensaje, "%f", resultado);
				}
				close(fd);

				fd = open(nfifo, O_WRONLY);
				if (fd == -1)
				{
					perror("Error al abrir la tuberia en modo escritura");
					exit(1);
				}
				else
				{
					write(fd,mensaje,100);
					close(fd);
				}
			}
		}
	}
	else
		perror("\nError al crear la tubería\n");

	return 0;
}
