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
    Ator *atores;
} Filme;

Filme* criarFilme(char *titulo, int ano);
Ator* criarAtor(char *nome);

int inserirFilme(Filme **lista, Filme *novo);
int inserirAtor(Filme *filme, Ator *novo);


int exibirAtores(Ator *lista);
int exibirFilmes(Filme *lista);


Filme* buscarFilme(Filme *lista, char *titulo);


int lerArquivoFilmes(const char *nomeArquivo, Filme **lista);

#endif



