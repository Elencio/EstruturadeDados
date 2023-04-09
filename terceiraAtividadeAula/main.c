#include <stdio.h> //chama-se a Biblioteca

float maximoNumero(int n, float *v) {
  float max_valor = v[0];
  for (int i = 1; i < n; i++) {
    if (v[i] > max_valor) {
      max_valor = v[i];
    }
  }
  return max_valor;
}

// Quando for chamada a funcao primeiro vai receber os parametros, depois
// declaracao uma variavel de nome max_valor serve para armazenar o maior valor
// encontrado até o momento no vetor. Inicialmente, ela aponta para o primeiro
// elemento do vetor, e depois é atualizada caso um valor maior seja encontrado
// durante a iteração pelo vetor. Por sim ela retorna o maximo valor.

int numerosImpares(int n, int *v) {
  int countImpares = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] % 2 != 0) {
      countImpares++;
    }
  }
  return countImpares;
}
// Quando for chamada a funcao primeiro vai receber os parametros, depois
// declaracao uma variavel de nome countImpares que vai contar e armazenar os
// numeros  impares. Inicialmente entra no ciclo e busca o nom primeiro que esta
// na primeira posicao verifica se nao divisivel por dois, se nao for armazena o
// valor

// Funcao Principal

int main(void) {
  int numero1, numero2; // declarou-se duas variaveis que serao usadas nas duas
                        // funcoes, a numeroMaximo e numerosImpares.
  int n1, n2; // Essas duas variaveis representam o tamanho dos vetores que
              // usuario ira preencher
  printf("\nSolicitacao dos numeros\n");
  printf("\nDigite o primeiro usado na Funcao Maior numero:\t");
  scanf("%d", &numero1);
  printf("\nDigite o primeiro usado na Funcao numeros Impares: \t");
  scanf("%d", &numero2);

  // Nesse codigo o usuario vai digitar os numeros necessarios para achar o
  // numero maximo e os numeros impares
  printf("\nPreencimento do primeiro vetor\n");
  printf("\nDigite o tamanho do primeiro vetor:\t");
  scanf("%d", &n1);
  float vetor1[n1];
  printf("\nDigite os valores do primeiro vetor:\t");
  for (int i = 0; i < n1; i++) {
    printf("\nNumero flutuante [%d]:", i + 1);
    scanf("%f", &vetor1[i]);
  }
  // As linhas acima de codigo premitem o usuario inserir o tamanho de vetor do
  // tipo flutuante que ira receber dados decimais e preenche-lo.
  printf("\nPreencimento do segundo vetor\n");
  printf("\nDigite o tamanho do segundo vetor:\t");
  scanf("%d", &n2);
  int vetor2[n2];
  printf("\nDigite os valores do segundo vetor:\t");
  for (int i = 0; i < n2; i++) {
    printf("\nNumero inteiro [%d]:", i + 1);
    scanf("%d", &vetor2[i]);
  }

  // As linhas acima de codigo premitem o usuario inserir o tamanho de vetor do
  // tipo inteiro que ira receber dados inteiros e preenche-lo.

  printf("\nMáximo valor: %.2f\n", maximoNumero(numero1, vetor1));
  printf("\nQuantidade de números ímpares: %d\n",
         numerosImpares(numero2, vetor2));

  // O codigo acima vai imprimir o resultado final das funcoes, mas para tal
  // seram chamadas as funcoes que vao receber os dados acima.

  return 0;
}
