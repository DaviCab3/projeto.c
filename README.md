# projeto.c
Projeto da faculdade de listas duplamente encadeadas

#include <stdlib.h>
#include "LISTA.H"

int main() {
    Filme *listaDeFilmes = NULL; // lista principal de filmes

    // ---------------------- Criar filmes ----------------------
    Filme *f1 = criarFilme("Matrix", 1999);
    Filme *f2 = criarFilme("Titanic", 1997);

    // ---------------------- Inserir filmes na lista ----------------------
    inserirFilme(&listaDeFilmes, f1);
    inserirFilme(&listaDeFilmes, f2);

    // ---------------------- Criar atores ----------------------
    Ator *a1 = criarAtor("Keanu Reeves");
    Ator *a2 = criarAtor("Laurence Fishburne");
    Ator *a3 = criarAtor("Leonardo DiCaprio");
    Ator *a4 = criarAtor("Kate Winslet");

    // ---------------------- Inserir atores nos filmes ----------------------
    inserirAtor(f1, a1);
    inserirAtor(f1, a2);
    inserirAtor(f2, a3);
    inserirAtor(f2, a4);

    // ---------------------- Exibir filmes e atores ----------------------
    Filme *auxFilme = listaDeFilmes;
    while (auxFilme != NULL) {
        printf("Filme: %s (%d)\n", auxFilme->titulo, auxFilme->ano);

        Ator *auxAtor = auxFilme->atores;
        printf("Atores: ");
        while (auxAtor != NULL) {
            printf("%s", auxAtor->nome);
            if (auxAtor->prox != NULL) printf(", ");
            auxAtor = auxAtor->prox;
        }
        printf("\n\n");

        auxFilme = auxFilme->prox;
    }

    return 0;
}

#ifndef LISTA_H
#define LISTA_H


typedef struct Ator {
    char nome[50];
    struct Ator *ant;
    struct Ator *prox;
} Ator;


typedef struct Filme {
    char titulo[50];
    int ano;
    struct Filme *ant;
    struct Filme *prox;
    Ator *atores;   // ponteiro para a lista de atores do filme
} Filme;



Filme* criarFilme(char *titulo, int ano);
Ator* criarAtor(char *nome);



int inserirFilme(Filme **listapor, Filme *novo);
int inserirAtor(Filme *filme, Ator *novo);



int exibirFilmes(Filme *lista);
int exibirAtores(Ator *lista);



Filme* buscarFilme(Filme *lista, char *titulo);
Ator* buscarAtor(Ator *lista, char *nome);



void removerFilme(Filme **lista, char *titulo);
void removerAtor(Filme *filme, char *nome);



void salvarCinema(Filme *lista, char *nomeArquivo);
Filme* carregarCinema(char *nomeArquivo);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LISTA.H"


Filme* criarFilme(char *titulo, int ano){
    Filme* novo = (Filme*) malloc (sizeof(Filme));
         if (novo == NULL) {
            printf("Erro ao alocar memória para o filme.\n");
            return NULL;
         }
        strcpy (novo -> titulo ,titulo);
        novo -> ano   = ano;
        novo -> ant   = NULL;
        novo -> prox  = NULL;
        novo ->atores = NULL;

        return novo;

}


Ator* criarAtor(char *nome){
    Ator* novo = (Ator*) malloc (sizeof(Ator));
        if (novo == NULL) {
            printf("Erro ao alocar memória para o ator.\n");
        return NULL;
        }
    strcpy (novo-> nome , nome);
    novo -> ant = novo ->prox =NULL;

    return novo;
}


int inserirFilme(Filme **lista, Filme *novo){
  if (novo == NULL) return 0 ;

    // Lista vazia
    if (*lista == NULL) {
        *lista = novo;
        return 1;
    }
        Filme *aux = * lista;
        while (aux -> prox !=NULL) {
            aux = aux ->prox;
        }
        aux-> prox = novo;
        novo->ant = aux;
        return 1 ;
}

int inserirAtor(Filme *filme, Ator *novo){
    if (novo == NULL) return 0;

    if (filme -> atores == NULL) {
        filme -> atores = novo;
        return 1;
    }
        Ator * aux = filme ->atores;
        while (aux-> prox != NULL){
            aux= aux-> prox;
        }
        aux  -> prox = novo;
        novo -> ant  =  aux;
        return 1;
}



int exibirFilmes(Filme *lista) {
    if (lista == NULL) return 0; // lista vazia

    Filme *auxFilme = lista;
    while (auxFilme != NULL) {
        printf("Filme: %s (%d)\n", auxFilme->titulo, auxFilme->ano);

        printf("Atores: ");
        if (!exibirAtores(auxFilme->atores)) {
            printf("Nenhum ator cadastrado");
        }
        printf("\n\n");

        auxFilme = auxFilme->prox;
    }
    return 1; // sucesso
}


int exibirAtores(Ator *lista) {
    if (lista == NULL) return 0; // lista vazia

    Ator *aux = lista;
    while (aux != NULL) {
        printf("%s", aux->nome);
        if (aux->prox != NULL) printf(", ");
        aux = aux->prox;
    }
    printf("\n");
    return 1; // sucesso
}



