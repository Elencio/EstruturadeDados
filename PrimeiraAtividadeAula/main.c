#include <stdio.h>

#define N 10

void imprime(int *v, int size);
int espacos_ocupados(int *v, int size);
void insere_fim(int *v, int size, int x);
void insere_inicio(int *v, int size, int x);
void insere_inicio_2(int *v, int size, int x);
int buscar(int *v, int size, int x);

int main(void) {
  int v[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  imprime(v, N);
  insere_inicio(v, N, 3);
  insere_inicio_2(v, N, 21);
  insere_fim(v, N, 50);
  imprime(v, N);
  buscar(v, N, 50);
  return 0;
}

void imprime(int *v, int size) {
  for (int i = 0; i < size; i++)
    printf("%d\t", v[i]);
  printf("\n");
}

void insere_inicio(int *v, int size, int x) {
  int t = espacos_ocupados(v, size);

  if (t == size) // a lista já está cheia
    return;

  // Deslocando
  int i = t - 1;
  while (i >= 0) {
    v[i + 1] = v[i];
    i--;
  }

  // Inserindo
  v[0] = x;
}

/**
Conta quantos espaços ocupados existem no vetor.
Considerando que 0 == espaço livre
*/
int espacos_ocupados(int *v, int size) {
  int c = 0;

  for (int i = 0; i < size; i++)
    if (v[i] != 0)
      c++;

  return c;
}

void insere_fim(int *v, int size, int x) {
  int t = espacos_ocupados(v, size);
  if (t == size) // a lista já está cheia
    return;

  v[t] = x;
}

void insere_inicio_2(int *v, int size, int x) {
  int t = espacos_ocupados(v, size);

  if (t == size) // a lista já está cheia
    return;

  v[t] = v[0];
  v[0] = x;
}

int buscar(int *v, int size, int x) {
  int i;
  while (i <= size) {
    if (x == v[i]) {
      printf("\nEncontrei o numero! A posicao do numero %d e %d", x, i);

      v[i] = 42;

      printf("\nE Atualizei o numero para : %d \n\n", v[i]);

      imprime(v, N);

      return 0;
    }

    i++;
  }
  printf("Nao encontrei o numero ");
}