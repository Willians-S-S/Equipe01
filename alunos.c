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


void Insert_Sort(Alunos *listaAlun){
    Alunos *atual = listaAlun, *anterior;
    char aux[20];

    for(; atual != NULL; atual = atual->prox){
        strcpy(aux, atual->nome);
        anterior = atual->ante;

        while(anterior != NULL && strcmp(aux, anterior->nome) < 0){

            strcpy(anterior->prox->nome, anterior->nome);
            anterior = anterior->ante;
        }

        if(anterior == NULL){
            strcpy(listaAlun->nome, aux);
        }else if( strcmp(aux, anterior->nome) < 0){
           
            strcpy(anterior->nome, aux);

        }
        printf("4\n\n");
    }
}
