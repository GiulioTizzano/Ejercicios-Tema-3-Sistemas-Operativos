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
        execl("/bin/ls", "ls", "-l", (char*)0);
        pid_dos = fork();

        if(pid_dos == 0) {
            execl("/bin/ps", "ps", (char*)0);
        }
    } 
    while(wait(NULL) > 0);
    return 0;
}