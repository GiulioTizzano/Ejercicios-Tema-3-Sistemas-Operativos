#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void) {
   for(int i = 1; i <= 8; i++) {
    if(fork() == 0) {
        printf("\n Soy el proceso %d y mi padre es %d", getpid(), getppid());
        break;
    }
   }

   // El proceso MAIN inicia el bucle for() y crea ocho procesos hijos utilizando fork().
   // Específicamente en mi entorno al imprimir el mensaje por pantalla se imprimen
   // los PID en orden aunque esto pued ser coincidencia ya que el fork() crea hijos en 
   // el mismo bucle for() y éstos compiten por el tiempo de CPU y por tanto al compilarlo
   // de nuevo o en entorno distinto al mío podrían ejecutarse sin un orden específico.
    return 0;
}