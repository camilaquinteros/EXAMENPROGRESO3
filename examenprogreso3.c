#include <stdio.h>
#include <string.h>

#define MAX_CARACTERES 1000

int corregirOrtografia(char *palabra) {
    if (strcmp(palabra, "ecuador") == 0) {
        palabra[0] = palabra[0] - 32;
        return 1;
    }
    return 0;
}

int main() {
    char texto [MAX_CARACTERES];
int palabrasCorregidas = 0;

FILE *archivoEntrada = foper("tricolor.txt", "r");
if (archivoEntrada == NULL) {
    printf("No se pudo abrir el archivo de entrada.\n");
return 1;
},

fgets(texto, MAX_CARACTERES, archivoEntrada);

    fclose(archivoEntrada),

    char *palabra = strtok(texto, " ");
    while (palabra != NULL) [
        palabrasCorregidas += corregirOrtografia(palabra);
        palabra = strtok(NULL, " ");
    ]

    FILE *archivoSalida = fopen("texto_corregido.txt","w");
    if (archivoSalida == NULL) {
        printf("No se puede abrir el archivo de salida.\n");
        return 1;
    }

    fputs(texto, archivoSalida);

    fclose(archivoSalida);

    printf("Se corrigieron %d palabras en total.\n", palabrasCorregidas);

    return 0;
}


