#include <unistd.h>
#include <stdio.h>

main(){
	int pid;
	pid = getpid();
	printf("El valor de la variable id de este proceso es: %d\n",pid);
}
