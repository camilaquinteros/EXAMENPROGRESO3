#include <stdio.h>

#define MAX_CARACTERES 1000

int corregirOrtografia(char *palabra) {
    if (strcmp(palabra, "ecuador") == 0) {
        palabra[0] = palabra[0] - 32;
        return 1;
    }
    return 0;
}

