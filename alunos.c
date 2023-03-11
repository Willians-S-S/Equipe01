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
    int qtd;
    printf("Digite o nome do aluno: ");
    scanf(" %s", new->nome);
    new->prox = NULL;
    new->ante = NULL;
    
    new->listaNotas = iniciarNotas();

    printf("Digite a quantidade de motas que irá inserir: ");
    scanf(" %d", &qtd);

    for(int i = 0; i < qtd; i++){
        printf("Digite a %dº nota: ", i);
        new->listaNotas = inserirNotas(new->listaNotas);
    }

    new->prox = listaAlun;
    if(listaAlun) listaAlun->ante = new;
    printf("\n");
    return new;
}

void mostrarAlunos(Alunos * listaAlun){
    if(listaAlun){
        printf("%s\n", listaAlun->nome);
        printf("Notas: ");
        mostrarNotas(listaAlun->listaNotas);
        printf("\n\n");
        mostrarAlunos(listaAlun->prox);
    }
}

void selecionSort(Alunos * listaAlun){
    Alunos *aux, *aux2, *min;
    char aux3[20];
    


    for(aux = listaAlun; aux != NULL; aux = aux->prox){
        min = aux;
        for(aux2 = aux->prox; aux2 != NULL; aux2 = aux2->prox){
            if(strcmp(aux2->nome, min->nome) < 0){
                min = aux2;
            }
        }
        if(aux != min){
            strcpy(aux3, aux->nome);
            Notas *aux4 = aux->listaNotas;
    
            strcpy(aux->nome, min->nome);
            aux->listaNotas = min->listaNotas;

            strcpy(min->nome, aux3);
            min->listaNotas = aux4;
        }
    }
}

void ordenar(Alunos *listaAlun){
    Alunos *aux = listaAlun;
    selecionSort(listaAlun);

    while(aux){
        selection_sort_Notas(aux->listaNotas);
    }
}