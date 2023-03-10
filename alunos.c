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
    Alunos *aux, *aux2;
    char str[20];

    for(aux = listaAlun; aux != NULL; aux = aux->prox){
        for(aux2 = aux->prox; aux2 != NULL; aux2 = aux2->prox){
            if(strcmp(aux->nome, aux2->nome) > 0){
                strcpy(str, aux2->nome);
                strcpy(aux2->nome, aux->nome);
                strcpy(aux->nome, str);
            }
        }
    }
}

// void selecionSort(Alunos * listaAlun){
//     Alunos *aux, *aux2, *min;
//     char str[20];

//     for(aux = listaAlun; aux != NULL; aux = aux->prox){
//         min = aux;
//         for(aux2 = aux->prox; aux2 != NULL; aux2 = aux2->prox){
//             if(strcmp(str, min->nome) < 0) min = aux2;
//         }
//         if(aux != min){
//             strcpy(str, aux->nome);
//             strcpy(aux->nome, min->nome);
//             strcpy(min->nome, str);
//         }
//     }
// }


// void Insert_Sort(Alunos *listaAlun){
//     Alunos *atual = listaAlun, *anterior;
//     char aux[20];

//     for(; atual != NULL; atual = atual->prox){
//         strcpy(aux, atual->nome);
//         anterior = atual->ante;

//         while(anterior != NULL && strcmp(aux, anterior->nome) < 0){

//             strcpy(anterior->prox->nome, anterior->nome);
//             anterior = anterior->ante;
//         }

//         if(anterior == NULL){
//             strcpy(listaAlun->nome, aux);
//         }else if( strcmp(aux, anterior->nome) < 0){
           
//             strcpy(anterior->nome, aux);

//         }
//         printf("4\n\n");
//     }
// }
