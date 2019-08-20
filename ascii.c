#include <stdio.h>
#include "ascii.h"

void imprimeArteInicial(){
    FILE *f = fopen("artes/arte-inicial.txt", "r");
    while(!feof(f)){
        printf("%c", fgetc(f));
    }
    fclose(f);
}