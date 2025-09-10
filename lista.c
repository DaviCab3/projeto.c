#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LISTA.h"

//  CRIAR 
Filme* criarFilme(char *titulo, int ano) {
    Filme *novo = (Filme*) malloc(sizeof(Filme));
    if (!novo) return NULL;

    strcpy(novo->titulo, titulo);
    novo->ano = ano;
    novo->ant = novo->prox = NULL;
    novo->atores = NULL;

    return novo;
}

Ator* criarAtor(char *nome) {
    Ator *novo = (Ator*) malloc(sizeof(Ator));
    if (!novo) return NULL;

    strcpy(novo->nome, nome);
    novo->ant = novo->prox = NULL;

    return novo;
}

//  INSERIR 
int inserirFilme(Filme **lista, Filme *novo) {
    if (!novo) return 0;

    if (*lista == NULL) {
        *lista = novo;
        return 1;
    }

    Filme *aux = *lista;
    while (aux->prox != NULL) aux = aux->prox;

    aux->prox = novo;
    novo->ant = aux;
    return 1;
}

int inserirAtor(Filme *filme, Ator *novo) {
    if (!filme || !novo) return 0;

    if (filme->atores == NULL) {
        filme->atores = novo;
        return 1;
    }

    Ator *aux = filme->atores;
    while (aux->prox != NULL) aux = aux->prox;

    aux->prox = novo;
    novo->ant = aux;
    return 1;
}

//  EXIBIR 
int exibirAtores(Ator *lista) {
    if (!lista) return 0;

    Ator *aux = lista;
    while (aux != NULL) {
        printf("%s", aux->nome);
        if (aux->prox != NULL) printf(", ");
        aux = aux->prox;
    }
    printf("\n");
    return 1;
}

int exibirFilmes(Filme *lista) {
    if (!lista) return 0;

    Filme *auxFilme = lista;
    while (auxFilme != NULL) {
        printf("Filme: %s (%d)\n", auxFilme->titulo, auxFilme->ano);
        printf("Atores: ");
        if (!exibirAtores(auxFilme->atores))
            printf("Nenhum ator cadastrado");
        printf("\n\n");
        auxFilme = auxFilme->prox;
    }
    return 1;
}

// LEITURA DE ARQUIVO 
void lerArquivoFilmes(char *nomeArquivo, Filme **listaFilmes) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (!fp) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    char linha[256];
    Filme *filmeAtual = NULL;

    while (fgets(linha, sizeof(linha), fp)) {
        linha[strcspn(linha, "\n")] = 0; // remove \n
        if (strlen(linha) == 0) continue;

        if (strncmp(linha, "Filme:", 6) == 0) {
            char titulo[50];
            int ano;
            sscanf(linha, "Filme:%49[^;];%d", titulo, &ano);

            filmeAtual = criarFilme(titulo, ano);
            inserirFilme(listaFilmes, filmeAtual);
        } else if (strncmp(linha, "Ator:", 5) == 0 && filmeAtual != NULL) {
            char nome[50];
            sscanf(linha, "Ator:%49[^\n]", nome);

            Ator *novoAtor = criarAtor(nome);
            inserirAtor(filmeAtual, novoAtor);
        }
    }

    fclose(fp);
}

