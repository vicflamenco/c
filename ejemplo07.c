#include <unistd.h>
#include <stdio.h>
main(){
	int pid = fork();
	if (pid>0)
		printf("EL pid del proceso Padre es: %d\n", getpid());
}
