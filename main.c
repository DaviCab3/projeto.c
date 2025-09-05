#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define TAM_MAX 100

// Função para ler filmes e atores do arquivo
Filme* lerFilmesDoArquivo(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo!\n");
        return NULL;
    }

    Filme *lista = NULL;
    char linha[TAM_MAX];

    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';
        char titulo[50];
        strcpy(titulo, linha);

        if (!fgets(linha, sizeof(linha), arquivo)) break;
        int ano = atoi(linha);

        Filme *filme = criarFilme(titulo, ano);
        inserirFilme(&lista, filme);

        if (!fgets(linha, sizeof(linha), arquivo)) break;
        int numAtores = atoi(linha);

        for (int i = 0; i < numAtores; i++) {
            if (!fgets(linha, sizeof(linha), arquivo)) break;
            linha[strcspn(linha, "\n")] = '\0';
            Ator *ator = criarAtor(linha);
            inserirAtor(filme, ator);
        }
    }

    fclose(arquivo);
    return lista;
}

// Função para liberar memória
void liberarFilmes(Filme *lista) {
    while (lista) {
        Filme *tmpFilme = lista;
        Ator *auxAtor = tmpFilme->atores;
        while (auxAtor) {
            Ator *tmpAtor = auxAtor;
            auxAtor = auxAtor->prox;
            free(tmpAtor);
        }
        lista = lista->prox;
        free(tmpFilme);
    }
}

int main() {
    Filme *lista = lerFilmesDoArquivo("filmes.txt");
    if (!lista) return 1;

    exibirFilmes(lista);

    liberarFilmes(lista);
    return 0;
}
