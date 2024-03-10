#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>

// La finalidad de la función execl() es de ejecutar un nuevo programa dentro de un proceso hijo
// y esto se hace a menudo después de una llamada al sistema fork().

// Los parámetro que se esperan insertar en la función execl() son los siguientes:
// execl(const char *path, const char *arg, ..., (char*)0);
// 1. const char *path: es el ruta absoluta donde se encuentra el programa que queremos ejecutar.
// 2. const char *arg: es el primer argumento que le pasas al programa que estás ejecutando, de este parámetro
// puede haber n dentro de una función.
// 3. (char*)0: es un marcador nulo que indica el final de la lista de argumentos




int main(int argc, char* argv[]) {
    int rt;
    rt = fork();

    if(rt == 0) {

        execl("/bin/ls", "ls", "-l", (char*)0);
    }
    while(wait(NULL) > 0);
}

// Dado todo lo explicado arriba, lo que haría el programa sería ejecutar el comando ls en el proceso hijo 
// y le pasaría como único argumento -l para el listado detallado.