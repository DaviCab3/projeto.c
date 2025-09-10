#include <stdio.h>
#include "LISTA.h"
#include <string.h>


int main() {
    Filme *listaDeFilmes = NULL;

    // Lê os filmes e atores de um arquivo
    lerArquivoFilmes("filmes.txt", &listaDeFilmes);

    // Exibe os filmes e atores
    printf("=== Lista de Filmes ===\n");
    exibirFilmes(listaDeFilmes);

    // Buscar um filme específico
    char tituloBusca[50];
    printf("\nDigite o título do filme que deseja buscar: ");
    fgets(tituloBusca, sizeof(tituloBusca), stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0'; // remover \n

    Filme *f = buscarFilme(listaDeFilmes, tituloBusca);
    if (f) {
        printf("\nFilme encontrado:\n");
        printf("Título: %s (%d)\n", f->titulo, f->ano);
        printf("Atores: ");
        if (!exibirAtores(f->atores))
            printf("Nenhum ator cadastrado\n");
    } else {
        printf("\nFilme não encontrado!\n");
    }

    return 0;
