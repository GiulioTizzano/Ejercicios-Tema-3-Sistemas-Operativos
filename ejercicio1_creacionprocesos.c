#include <stdio.h>
#include <string.h>
#include <sys/types.h>

void main(void) {
pid_t pid;
pid = fork();

if(pid < 0) {
	printf("No sé ha creado el proceso correctamente");
} else if(pid == 0) {
	printf("\n Soy el proceso hijo con PID %d y PPID %d \n", getpid(), getppid());
} else {
	printf("\n Soy el proceso padre con PID %d y PPID %d \n", getpid(), getppid());
}



}
