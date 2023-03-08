#include <stdio.h>
#include <string.h>
#include "alunos.h"
#include "notas.h"

struct alunos{
    char nome[20];
    Notas *listaNotas;
    Alunos *prox;
    Alunos *ante;
};

Alunos *iniciar(){
    return NULL;
}

Alunos *inserirAlunos(Alunos *listaAlun){
    Alunos *new = (Alunos*) malloc(sizeof(Alunos)); 
    scanf(" %s", new->nome);
    new->prox = NULL;
    new->ante = NULL;
    
    new->listaNotas = iniciarNotas();

    if(!listaAlun) return new;

    return new->prox = listaAlun;
}

void insertion_sort(char **lista, int n){
    int i, j;
    char *key;
    for (i = 1; i < n; i++) {
        key = lista[i];
        j = i - 1;
        while (j >= 0 && strcmp(lista[j], key) > 0) {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = key;
    }
}

