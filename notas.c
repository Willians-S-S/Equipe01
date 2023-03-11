#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notas.h"

struct notas{
    float nota;
    Notas *prox;
    Notas *ante;
};

Notas *iniciarNotas(){
    return NULL;
}

Notas *inserirNotas(Notas *listaNotas){
    Notas *new = (Notas*) malloc(sizeof(Notas)); 
    scanf("%f", &new->nota);
    new->prox = NULL;
    new->ante = NULL;

    new->prox = listaNotas;
    return new;
}

void mostrarNotas(Notas *listaNotas){
    if(listaNotas){
        printf("%.1f ", listaNotas->nota);
        mostrarNotas(listaNotas->prox);
    }
}

void selection_sort_Notas(Notas *cabeca) {
    Notas *aux, *aux2, *min;
    
    int aux3;
    for (aux = cabeca; aux !=NULL; aux = aux->prox) {
        min = aux;
        for (aux2 = aux->prox; aux2 != NULL; aux2 = aux2->prox){
            if (aux2->nota < min->nota) {
                min = aux2;
            }
        }
        if (aux != min) {
            aux3 = aux->nota;
            aux->nota = min->nota;
            min->nota = aux3;
        }
    }
}