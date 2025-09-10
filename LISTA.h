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

// ================== CRIAR ==================
Filme* criarFilme(char *titulo, int ano);
Ator* criarAtor(char *nome);

// ================== INSERIR ==================
int inserirFilme(Filme **lista, Filme *novo);
int inserirAtor(Filme *filme, Ator *novo);

// ================== EXIBIR ==================
int exibirAtores(Ator *lista);
int exibirFilmes(Filme *lista);

// ================== BUSCAR ==================
Filme* buscarFilme(Filme *lista, char *titulo);

// ================== ARQUIVO ==================
int lerArquivoFilmes(const char *nomeArquivo, Filme **lista);

#endif



