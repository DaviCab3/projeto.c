#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LISTA.h"

//  CRIAR FILME 
Filme* criarFilme(char *titulo, int ano) {
    Filme *novo = (Filme*) malloc(sizeof(Filme));
    if (!novo) return NULL;

    strcpy(novo->titulo, titulo);
    novo->ano = ano;
    novo->ant = NULL;
    novo->prox = NULL;
    novo->atores = NULL;

    return novo;
}

//  CRIAR ATOR 
Ator* criarAtor(char *nome) {
    Ator *novo = (Ator*) malloc(sizeof(Ator));
    if (!novo) return NULL;

    strcpy(novo->nome, nome);
    novo->ant = NULL;
    novo->prox = NULL;

    return novo;
}


int inserirFilme(Filme **lista, Filme *novo) {
    if (!novo) return 0;

    if (*lista == NULL) {
        *lista = novo;
        return 1;
    }

    Filme *aux = *lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
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
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ant = aux;

    return 1;
}

//  EXIBIR ATORES 
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

    Filme *aux = lista;
    while (aux != NULL) {
        printf("Filme: %s (%d)\n", aux->titulo, aux->ano);
        printf("Atores: ");
        if (!exibirAtores(aux->atores))
            printf("Nenhum ator cadastrado\n");
        printf("\n");
        aux = aux->prox;
    }

    return 1;
}

//  BUSCAR FILME 
Filme* buscarFilme(Filme *lista, char *titulo) {
    if (!lista) return NULL;

    Filme *aux = lista;
    while (aux != NULL) {
        if (strcmp(aux->titulo, titulo) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

// LER ARQUIVO 
int lerArquivoFilmes(const char *nomeArquivo, Filme **lista) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (!fp) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), fp)) {
        linha[strcspn(linha, "\n")] = '\0'; // remove \n
        if (strlen(linha) == 0) continue;

        // Título
        char titulo[50];
        strcpy(titulo, linha);

        // Ano
        if (!fgets(linha, sizeof(linha), fp)) break;
        int ano = atoi(linha);

        Filme *novoFilme = criarFilme(titulo, ano);
        inserirFilme(lista, novoFilme);

        // Atores (até linha em branco)
        while (fgets(linha, sizeof(linha), fp)) {
            linha[strcspn(linha, "\n")] = '\0';
            if (strlen(linha) == 0) break;

            Ator *novoAtor = criarAtor(linha);
            inserirAtor(novoFilme, novoAtor);
        }
    }

    fclose(fp);
    return 1
