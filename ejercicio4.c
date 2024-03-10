#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>

int main(void) {
    pid_t pid, pid_dos;
    
    pid = fork();

    if(pid == 0) {
        printf("\n Soy el proceso: %d y tengo un PPID: %d \n", getpid(), getppid());
        pid_dos = fork();
        if(pid_dos == 0) {
            printf("\n Soy el proceso: %d y tengo un PPID: %d\n", getpid(), getppid());
        }
    }
    while(wait(NULL) > 0);
    return 0;
}