#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no {
  int info;
  No *esq;
  No *dir;
};

No *getnode() {
  No *p;
  p = (No *)malloc(sizeof(No));
  return p;
}

No *criar_arvore(int x) {
  No *p;

  p = getnode();
  p->info = x;
  p->esq = NULL;
  p->dir = NULL;
  return (p);
}

void inserir(No *raiz, int x) {
  No *novo_no = getnode();
  novo_no->info = x;
  novo_no->dir = novo_no->esq = NULL;

  No *atual, *pai;
  atual = pai = raiz;

  // A função insere um novo nó com valor "x" na árvore binária. Para isso, a
  // árvore é percorrida em busca do local adequado para inserção, seguindo a
  // regra de árvore binária de pesquisa em que valores menores são armazenados
  // na subárvore esquerda e valores maiores na subárvore direita
  while (atual != NULL) {
    pai = atual;
    if (novo_no->info < atual->info) {
      atual = pai->esq;
    } else {
      atual = pai->dir;
    }
  }

  // O while e utiliza as variáveis "atual" e "pai" para armazenar os nós
  // visitados na busca. A cada iteração, o ponteiro "atual" é atualizado para a
  // subárvore esquerda ou direita, dependendo se "x" é menor ou maior que o
  // valor do nó "atual"

  if (x < pai->info) {
    pai->esq = novo_no;
  } else {
    pai->dir = novo_no;
  }
}

No *buscar(No *raiz, int x) {

  if (raiz == NULL || raiz->info == x) {
    return raiz;
  }

  if (x < raiz->info) {
    return buscar(raiz->esq, x);
  } else {
    return buscar(raiz->dir, x);
  }

  // A função busca um nó com valor "x" na árvore binária que tem a raiz raiz. A
  // busca é feita seguindo a regra de árvore binária de pesquisa, onde valores
  // menores são armazenados na subárvore esquerda e valores maiores são
  // armazenados na subárvore direita de um determinado nó
}

void imprimir(No *raiz, int nivel) {
  // A função recebe como parâmetros um ponteiro para um nó que representa a
  // raiz de uma árvore binária e um integer "nivel" que representa o nível do
  // nó
  if (raiz == NULL) {
    for (int i = 0; i < nivel; i++)
      putchar('\t');
    puts("~");
    return;
  } else {
    imprimir(raiz->dir, nivel + 1);
    for (int i = 0; i < nivel; i++)
      putchar('\t');
    printf("%d\n", raiz->info);
    imprimir(raiz->esq, nivel + 1);
  }

  // A função percorre toda a árvore binária em ordem invertida (da direita para
  // a esquerda), e imprime os valores dos nós na tela, identando-os para que a
  // impressão reflita a hierarquia e a estrutura da árvore. Se um nó que
  // precisa ser impresso está faltando, ele imprime o caractere ~ para indicar
  // a ausência
}

void imprimir_pre_ordem(No *raiz) {
  if (raiz != NULL) {
    printf("%d", raiz->info);
    printf("(");
    imprimir_pre_ordem(raiz->esq);
    imprimir_pre_ordem(raiz->dir);
    printf(")");
  }
  // a função imprime um parêntese aberto ("("), e chama recursivamente a função
  // para imprimir a subárvore esquerda da raiz e em seguida, chama
  // recursivamente a função para imprimir a subárvore direita da raiz
}

void imprimir_em_ordem(No *raiz) {
  if (raiz != NULL) {
    imprimir_em_ordem(raiz->esq);
    printf("%d ", raiz->info);
    imprimir_em_ordem(raiz->dir);
  }
  // a função percorre toda a subárvore esquerda da raiz, em seguida imprime o
  // valor armazenado na raiz e por fim percorre toda a subárvore direita da
  // raiz.
}

void imprimir_pos_ordem(No *raiz) {
  if (raiz != NULL) {
    imprimir_pos_ordem(raiz->esq);
    imprimir_pos_ordem(raiz->dir);
    printf("%d ", raiz->info);
  }
  // a função verifica se o nó da raiz tem algum valor nulo. Se não tiver, a
  // função é chamada recursivamente para imprimir a subárvore esquerda e depois
  // a subárvore direita da raiz.
}

void buscar_e_mostrar_resultado(No *raiz, int x) {
  printf("Buscando nó %d ", x);
  No *retorno_busca = buscar(raiz, x);
  if (retorno_busca) {
    printf(" -> Encontrado.\n");
  } else {
    printf(" -> NÃO encontrado.\n");
  }
}

/*
RESPOSTA AO ITEM b DA QUESTÃO 5:


p -> "pai": Representa o nó pai do nó a ser removido.
q -> "filho": Representa o nó filho que será movido para o lugar do nó removido



*/
No *remover(No *raiz, int x) {
  No *pai, *no, *p, *q;
  no = pai = raiz;

  // a função começa definindo três ponteiros "pai", "no" e "q", onde "no" e
  // "pai" são inicialmente iguais a "raiz", e "q" é utilizado na inserção do nó
  // que preencherá o espaço deixado pelo nó removido

  while (no->info != x) {
    pai = no;
    if (x < no->info)
      no = pai->esq;
    else
      no = pai->dir;
  }

  // Ela utiliza um loop "while" para percorrer a árvore enquanto o nó atual
  // "no" não contiver o valor a ser removido. A cada iteração, a variável "pai"
  // é atualizada para a "no" atual e a função determina se deve seguir para a
  // subárvore esquerda ou direita da "no" atual, dependendo se "x" é menor ou
  // maior que o valor do nó "no" atual.

  if (no == NULL)
    return raiz;

  if (!no->esq || !no->dir) {
    if (!no->esq)
      q = no->dir;
    else
      q = no->esq;
  } else {
    p = no;
    q = no->esq;
    while (q->dir) {
      p = q;
      q = q->dir;
    }

    // Após encontrar o nó a ser removido "no", a função determina se o nó tem
    // apenas um filho ou nenhum. Se o nó não tiver nenhum filho, a função
    // simplesmente remove o nó da árvore. Caso contrário, a função encontra o
    // menor nó na subárvore esquerda do nó a ser removido "p" e o conecta aos
    // seus pais, em seguida, conecta o nó a ser removido com seus filhos

    if (p != no) {
      p->dir = q->esq;
      q->esq = no->esq;
    }
    q->dir = no->dir;
  }

  if (!pai) {
    free(no);
    return (q);
  }

  if (x < pai->info)
    pai->esq = q;
  else
    pai->dir = q;
  free(no);
  return (raiz);

  // a variável "pai" para determinar se o nó a ser removido "no" é a raiz da
  // árvore ou não. Se for a raiz, a função remove o nó e devolve o novo nó que
  // preencherá seu espaço. Caso contrário, a função conecta o novo nó que
  // preencherá o espaço deixado pelo nó removido "q" com o pai "pai" do nó "no"
  // e remove o nó "no" da árvore
}

int main() {

  No *arvore;
  arvore = criar_arvore(18);

  inserir(arvore, 8);
  inserir(arvore, 2);
  inserir(arvore, 14);
  inserir(arvore, 10);
  inserir(arvore, 16);
  inserir(arvore, 9);
  inserir(arvore, 12);
  inserir(arvore, 11);

  printf("\nImpressão:\n");
  imprimir(arvore, 0);

  printf("\nBusca:\n");
  buscar_e_mostrar_resultado(arvore, 16);
  buscar_e_mostrar_resultado(arvore, 12);
  buscar_e_mostrar_resultado(arvore, 220);

  printf("\nImprimindo em pré-ordem:\n");
  imprimir_pre_ordem(arvore);

  printf("\nImprimindo em ordem:\n");
  imprimir_em_ordem(arvore);

  printf("\nImprimindo em pós-ordem:\n");
  imprimir_pos_ordem(arvore);

  int x = 14;
  printf("\nRemovendo nó %d...\n", x);
  arvore = remover(arvore, x);
  imprimir(arvore, 0);
}