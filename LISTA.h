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




#endif

