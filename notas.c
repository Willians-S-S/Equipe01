#include <stdio.h>
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
    scanf("%f", new->nota);
    new->prox = NULL;
    new->ante = NULL;
    

    if(!listaNotas) return new;

    return new->prox = listaNotas;
}