#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void) {

int fd;
pid_t pid;
char *mensaje_padre;
mensaje_padre = "1";
char *mensaje_hijo;
mensaje_hijo = "2";

fd = open("ejercicio2.txt", O_CREAT | O_RDWR);
pid = fork();

if(pid == -1) {
	printf("Error con el fork");
	exit(EXIT_FAILURE);
} else if(pid == 0) {
	for(int i = 0; i < 20; i += 2) {
		write(fd, mensaje_padre, 1);
		} 
	} else {
		for(int i = 1; i <= 20; i += 2) {
			write(fd, mensaje_hijo, 1);
		}
	}
	while(wait(NULL) > 0);
	close(fd);
	return 0;
}
