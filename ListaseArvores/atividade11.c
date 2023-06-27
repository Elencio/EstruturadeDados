#include <stdio.h>
#include <stdlib.h>

typedef struct no
    No; // Definição do tipo de dados "No", que é uma árvore binária

struct no { // Definição da estrutura do nó, que consiste na informação sobre
            // seu valor e seus respectivos filhos (subárvores)
  int info;
  No *esq; // Subárvore esquerda do nó
  No *dir; // Subárvore direita do nó
};

No *getnode() { // Função para alocar memória dinamicamente para um novo nó
  No *p;
  p = (No *)malloc(
      sizeof(No)); // Aloca um espaço de memória com o tamanho da estrutura "No"
  return p;
}

No *criar_arvore(
    int x) { // Função para criar uma árvore binária com um único nó
  No *p;

  p = getnode(); // Cria um novo nó e aloca memória para ele
  p->info = x;   // Armazena o valor recebido no nó criado
  p->esq = NULL; // Define as subárvores como vazias
  p->dir = NULL;
  return (p); // Retorna o nó criado
}

No *buscar(No *raiz, int x) {} // Função para buscar um valor específico na
                               // árvore (não implementada neste código)

void inserir(No *raiz, int x) { // Função para inserir um valor na árvore
  No *novo_no = getnode();      // Cria um novo nó e aloca memória para ele
  novo_no->info = x;            // Armazena o valor recebido no nó criado
  novo_no->dir = novo_no->esq = NULL; // Inicializa as subárvores como vazias

  No *atual, *pai;
  atual = pai = raiz; // Começa a busca a partir da raiz da árvore

  while (atual != NULL) { // Enquanto não for encontrada a posição correta para
                          // inserir o novo nó
    pai = atual; // O nó pai é atualizado para o nó atual
    if (x <
        atual->info) { // Se o valor a ser inserido for menor que o valor atual
      atual = pai->esq; // O nó atual passa a ser a subárvore esquerda do nó pai
    } else {            // Do contrário
      atual = pai->dir; // O nó atual passa a ser a subárvore direita do nó pai
    }
  }

  if (x <
      pai->info) { // Se o valor a ser inserido for menor que o valor do nó pai
    pai->esq = novo_no; // Insere o novo nó como subárvore esquerda do nó pai
  } else {              // Do contrário
    pai->dir = novo_no; // Insere o novo nó como subárvore direita do nó pai
  }
}

void imprimir(No *raiz, int nivel) { // Função para imprimir a árvore binária
  if (raiz == NULL) {                // Se a árvore estiver vazia
    for (int i = 0; i < nivel; i++)  // Imprime uma quantidade de tabulações
                                     // igual ao nível de profundidade do nó
      putchar('\t');
    puts("~"); // Imprime o til para indicar que não há conteúdo na árvore
    return;
  } else { // Se a árvore não estiver vazia
    imprimir(raiz->dir,
             nivel + 1); // Chama a função recursivamente para a subárvore da
                         // direita, incrementando o nível de profundidade
    for (int i = 0; i < nivel; i++)
      putchar('\t'); // Imprime uma quantidade de tabulações igual ao nível de
                     // profundidade do nó
    printf("%d\n", raiz->info); // Imprime o valor armazenado no nó
    imprimir(raiz->esq,
             nivel + 1); // Chama a função recursivamente para a subárvore da
                         // esquerda, incrementando o nível de profundidade } }
  }
}

int main() {
  No *arvore;
  arvore = criar_arvore(50); // Cria uma nova árvore com um único nó de valor 50
  inserir(arvore, 75);

  inserir(arvore, 10);
  inserir(arvore, 20);

  inserir(arvore, 40);

  inserir(arvore, 85);
  inserir(arvore, 90);
  inserir(arvore, 190);
  inserir(arvore, 80);
  inserir(arvore,
          25); // Insere os valores na árvore (à esquerda ou direita do nó pai,
               // conforme a comparação com o valor do nó atual) inserir(arvore,
               // 75); inserir(arvore, 10); inserir(arvore, 20); inserir(arvore,
               // 40); inserir(arvore, 85); inserir(arvore, 90);

  imprimir(arvore,
           0); // Imprime a árvore completa a partir da raiz (nível zero)
}