#include <unistd.h>
#include <stdio.h>

main(){
	int ppid;
	ppid = getppid();
	printf("El identificador del proceso padre es: %d\n",ppid);
}
