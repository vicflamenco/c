#include <unistd.h>
#include <stdio.h>
main(){
	fork();
	printf("El pid es: %d\n", getpid());
}
