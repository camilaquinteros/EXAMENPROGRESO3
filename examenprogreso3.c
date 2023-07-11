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
    char texto[MAX_CARACTERES];
    int palabrasCorregidas = 0;

    FILE *archivoEntrada = fopen("tricolor.txt", "r");
    if (archivoEntrada == NULL) {
        printf("No se pudo abrir el archivo de entrada.\n");
        return 1;
    }

    FILE *archivoSalida = fopen("texto_corregido.txt", "w");
    if (archivoSalida == NULL) {
        printf("No se pudo abrir el archivo de salida.\n");
        fclose(archivoEntrada);
        return 1;
    }

    while (fgets(texto, MAX_CARACTERES, archivoEntrada) != NULL) {
        char *palabra = strtok(texto, " ");
        while (palabra != NULL) {
            palabrasCorregidas += corregirOrtografia(palabra);
            fputs(palabra, archivoSalida);
            fputs(" ", archivoSalida);
            palabra = strtok(NULL, " ");
        }
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);

    printf("Se corrigieron %d palabras en total.\n", palabrasCorregidas);

    return 0;
}



