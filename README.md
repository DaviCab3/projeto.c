# projeto.c
🎬 Sistema de Filmes e Atores

Autor: Davi Gonçalves Cabeceira

📌 Modelagem do Problema

O problema apresentado foi escrever um código em linguagem C que utilize listas duplamente encadeadas para gerenciar uma lista de filmes, sendo que cada filme contém uma lista de atores associados.

A ideia é permitir, via terminal, operações como:

Listagem dos filmes.

Exibição dos atores de cada filme.

Inserção de novos filmes.

Inserção de novos atores em um filme existente.

Para isso, foi criado um módulo chamado lista.c para implementar as funções relativas à estrutura de dados, juntamente com um arquivo de interface lista.h para compartilhamento das funções, estruturas e tipos com o arquivo main.c.

📚 Bibliotecas Utilizadas

stdio.h → Entrada e saída padrão.

stdlib.h → Funções de alocação dinâmica de memória e controle do sistema operacional.

string.h → Funções de manipulação de strings.

🗂 Estruturas de Dados Utilizadas

A estrutura de dados escolhida foi a lista duplamente encadeada, aplicada tanto para a lista de filmes quanto para a lista de atores.

Filme

Título

Ano

Ponteiro para a lista de atores

Ponteiros para o filme anterior e próximo

Ator

Nome

Ponteiros para o ator anterior e próximo

📑 Documentação do Código
Funções
```Filme* criarFilme(char *titulo, int ano)```

Cria um novo filme.

Parâmetros: título (string), ano (inteiro).

Retorno: ponteiro para o filme criado.

```Ator* criarAtor(char *nome)```

Cria um novo ator.

Parâmetros: nome do ator (string).

Retorno: ponteiro para o ator criado.

```int inserirFilme(Filme **lista, Filme *novo)```

Insere um filme em uma lista de filmes.

Parâmetros: ponteiro para a lista de filmes, ponteiro para o novo filme.

Retorno: 1 se inserido com sucesso, 0 caso contrário.

```int inserirAtor(Filme *filme, Ator *novo)```

Insere um ator em um filme específico.

Parâmetros: ponteiro para o filme, ponteiro para o ator.

Retorno: 1 se inserido com sucesso, 0 caso contrário.

```int exibirFilmes(Filme *lista)```

Exibe todos os filmes presentes na lista.

Parâmetros: ponteiro para a lista de filmes.

Retorno: número de filmes exibidos.

```int exibirAtores(Ator *lista)```

Exibe todos os atores de um filme.

Parâmetros: ponteiro para a lista de atores.

Retorno: número de atores exibidos.

```int lerArquivoFilmes(char *nomeArquivo, Filme  ** lista) ```
Lê filmes e atores de um arquivo de texto e cria a lista de filmes.

Parâmetros:

nomeArquivo → nome do arquivo contendo os filmes (ex.: "filmes.txt").

Retorno: ponteiro para a lista de filmes ou NULL se houver erro ao abrir o arquivo.

```Filme* buscarFilme(Filme *lista, char *titulo)```
Procura um filme na lista de filmes pelo seu título.
 
  lista: ponteiro para a lista de filmes (Filme*).
  titulo: string com o título do filme que se deseja buscar.
 
  Retorno:
    Ponteiro para o nó do filme encontrado, caso exista.
    NULL caso o filme não seja encontrado na lista.
 
 Observações:
    - A busca é sensível a maiúsculas e minúsculas.
  - Retorna o primeiro filme que corresponde exatamente ao título informado.


Exemplo de uso do codigo : 


=== Lista de Filmes ===
Filme: Pulp Fiction (1994)
Atores: John Travolta, Uma Thurman, Samuel L. Jackson, Bruce Willis

Filme: Matrix (1999)
Atores: Keanu Reeves, Laurence Fishburne, Carrie-Anne Moss

Filme: Inception (2010)
Atores: Leonardo DiCaprio, Joseph Gordon-Levitt, Ellen Page, Tom Hardy


Digite o título do filme que deseja buscar: Matrix

Filme encontrado:
Título: Matrix (1999)
Atores: Keanu Reeves, Laurence Fishburne, Carrie-Anne Moss




