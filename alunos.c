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

    // if(!listaAlun) return new;

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


// void Insert_Sort(Alunos *listaAlun){
//     Alunos *atual = listaAlun->prox; 
//     char nome[20];

//     while(atual != NULL){
//         Alunos *chave = atual;
//         strcpy(nome, chave->nome);
//         Alunos *anterior = chave->ante;

//         while(anterior != NULL && strcmp(anterior->nome, nome) > 0){
//             strcpy(anterior->prox->nome, anterior->nome);
//             anterior->prox->listaNotas = anterior->listaNotas;
//             anterior = anterior->ante;
//         }
//         if(anterior == NULL){
//             strcpy(listaAlun->nome, chave->nome);
//             listaAlun->listaNotas = chave->listaNotas;
//         }else{
//             strcpy(anterior->prox->nome, chave->nome);
//             anterior->prox->listaNotas = chave->listaNotas;
//         }     
//         atual = atual->prox;
//     }
// }



// void insertion_sort(char *lista, int n){
//     int i, j;
//     char *key;
//     for (i = 1; i < n; i++) {
//         key = lista[i];
//         j = i - 1;
//         while (j >= 0 && strcmp(lista[j], key) > 0) {
//             lista[j + 1] = lista[j];
//             j--;
//         }
//         lista[j + 1] = key;
//     }
// }

