#include <unistd.h>
#include <stdio.h>
main(){
	int pid = fork();
	if (pid==0)
		printf("El pid del proceso hijo es: %d\n",getpid());
}
