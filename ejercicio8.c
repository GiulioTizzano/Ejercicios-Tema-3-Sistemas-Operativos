#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

#define VUELTAS 10000000000

void Salir(int sig) {
    switch(sig) {
        case(SIGINT):
            printf("Saliendo del programa al recibir la señal SIGINT\n");
            exit(EXIT_SUCCESS);
            break;
    }
}

int main(void) {
    int i;
    signal(SIGINT, Salir);
    for(int i = 0; i < VUELTAS; i++) {
        printf("Fin del programa sin recibir la señal SIGINT\n");
        exit(EXIT_SUCCESS); 
    }
}

// Cuando el proceso MAIN recibe la señal de SIGTERM entonces el comportamiento predeterminado es que 
// se termine de la ejecución sin ningún tipo de acción adicional.