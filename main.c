#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"
#include "notas.h"


int main(){
    Alunos *alun = iniciar();

    alun = inserirAlunos(alun);
    alun = inserirAlunos(alun);
    alun = inserirAlunos(alun);

    mostrarAlunos(alun);

    ordenar(alun);
    printf("\n\nOrdenado\n");
    mostrarAlunos(alun);
}