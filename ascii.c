#include <stdio.h>
#include "ascii.h"

void imprimeArte(FILE *f){
    while(!feof(f)){
        printf("%c", fgetc(f));
    }
}

void imprimeArteInicial(){
    FILE *f = fopen("artes/arteInicial.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteBanner(){
    FILE *f = fopen("artes/banner.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteDragao(){
    FILE *f = fopen("artes/dragao.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteGuerreiro(){
    FILE *f = fopen("artes/guerreiro.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteAtaqueDasMilLaminas(){
    FILE *f = fopen("artes/ataqueDasMilLaminas.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteEspadaDemoniaca(){
    FILE *f = fopen("artes/espadaDemoniaca.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteBencaoDosDeuses(){
    FILE *f = fopen("artes/bencaoDosDeuses.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteBolaDeFogo(){
    FILE *f = fopen("artes/bolaDeFogo.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteataqueComACauda(){
    FILE *f = fopen("artes/ataqueComACauda.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteGuerreiroDerrotado(){
    FILE *f = fopen("artes/guerreiroDerrotado.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteDragaoDerrotado(){
    FILE *f = fopen("artes/dragaoDerrotado.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteGuerreiroAtaque(){
    FILE *f = fopen("artes/guerreiroAtaque.txt", "r");
    imprimeArte(f);
    fclose(f);
}

void imprimeArteDragaoAtaque(){
    FILE *f = fopen("artes/dragaoAtaque.txt", "r");
    imprimeArte(f);
    fclose(f);
}