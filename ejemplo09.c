#include <unistd.h>
#include <stdio.h>
main(){
	int pid=fork();
	if (pid==0){
		printf("Soy el proceso hijo, mi id es: %d\n",getpid());
		printf("Soy el proceso hijo, el id de mi proceso padre es: %d\n",getppid());
	} else {
		printf("Soy el proceso padre, mi id es: %d\n",getpid());
		printf("Soy el proceso padre, el id de mi proceso padre es: %d\n",getppid());
	}
}
