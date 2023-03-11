#include <stdio.h>
#include <stdlib.h>
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

    new->prox = listaAlun;
    if(listaAlun) listaAlun->ante = new;

    return new;
}

void mostrarAlunos(Alunos * listaAlun){
    Alunos *aux = listaAlun;

    while(aux != NULL){
        printf("Aluno: %s \n\n", aux->nome);
        aux = aux->prox;
    }
}

void selecionSort(Alunos * listaAlun){
    Alunos *aux, *aux2, *min, *aux3;

    for(aux = listaAlun; aux != NULL; aux = aux->prox){
        min = aux;
        for(aux2 = aux->prox; aux2 != NULL; aux2 = aux2->prox){
            if(strcmp(aux2->nome, min->nome) < 0){
                min = aux2;
            }
        }
        if(aux != min){
            strcpy(aux3->nome, aux->nome);
            aux3->listaNotas = aux->listaNotas;
            strcpy(aux->nome, min->nome);
            aux->listaNotas = min->listaNotas;
            strcpy(min->nome, aux3);
        }
    }
}

