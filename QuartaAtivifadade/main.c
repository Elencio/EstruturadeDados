#include <stdio.h>

// Define-se os tamnahos globais dos vetores para que sejam acessados em
// qualquer parte do codigo

#define N 10
#define M 8

// O mesmo definiu-se para as funcoes

void imprime(int *v, int size);
int buscar(int *v, int size, int x);
int contar(int *v, int size, int x);
void mover(int *v, int size, int x);
void troca(int *num1, int *num2);
void separa_par_impar(int *v, int size);
void separa_par_impar_2(int *v, int size);
int espacos_ocupados(int *v, int size);
void insere_fim(int *v, int size, int x);
void insere_inicio(int *v, int size, int x);
void insere_inicio_2(int *v, int size, int x);
int remover(int *v, int size, int x);
void remover_todos(int *v, int size, int x);
void remover_todos_2(int *v, int size, int x);

int main(void) {

  // Essa e a funcao principal que vai chamar todas as funcoes implementadas,
  // com os valores, para verificar o seu funcionamento
  int v[N] = {8, 32, 21, 14, 42, 1, 38, 92, 92, 10};
  imprime(v, N);

  printf("Procurando 4 na lista: %d\n", buscar(v, N, 4));
  printf("Procurando 10 na lista: %d\n", buscar(v, N, 10));

  printf("Contando quantos 7's tem na lista: %d\n", contar(v, N, 4));
  printf("Contando quantos 92's tem na lista: %d\n", contar(v, N, 92));
  printf("Contando quantos 10's tem na lista: %d\n", contar(v, N, 10));

  mover(v, N, 10);
  imprime(v, N);

  mover(v, N, 10);
  imprime(v, N);

  int u[M] = {3, 8, 2, 7, 6, 4, 0, 5};
  imprime(u, M);

  separa_par_impar(u, M);
  imprime(u, M);

  int t[M] = {3, 8, 2, 7, 6, 4, 0, 5};
  imprime(t, M);

  separa_par_impar_2(t, M);
  imprime(t, M);

  int w[M] = {43, 5, 99};
  imprime(w, M);

  insere_fim(w, M, 10);
  imprime(w, M);

  insere_fim(w, M, 10);
  imprime(w, M);

  insere_inicio(w, M, 7);
  imprime(w, M);

  insere_inicio_2(w, M, 7);
  imprime(w, M);

  remover(w, M, 5);
  imprime(w, M);

  remover_todos(w, M, 7);
  imprime(w, M);

  remover_todos_2(w, M, 10);
  imprime(w, M);

  return 0;
}

void imprime(int *v, int size) {
  // Essa funcao recebe um endereco de um vetor e o seu tamanho
  for (int i = 0; i < size; i++)
    // Percorre o vetor
    printf("%d\t", v[i]);
  // Imprime o vetor com tabulacao para evitar que os numeros fiquem juntos
  printf("\n");
  // Quebra a linha
}

int buscar(int *v, int size, int x) {
  int i = 0;         // declara uma variavel i que comeca de zero
  while (i < size) { // depois coloca uma condicao que diz que enquanto a
                     // variavel i for menor que o tamanho
    if (v[i] == x) { // procura o valor no vetor
      return i;      // depois retorna a posicao
    }
    i++; // incrementa
  }
  return -1; // Se o while nao se cumprir retorna -1 que significa que o valor
             // nao foi encontrado
}

void insere_inicio(int *v, int size, int x) {
  int t = espacos_ocupados(v, size); // declara-se uma variavel que vai receber
                                     // o numeros de espacos ocupados do vetor

  if (t == size) // verifica se o vetor esta cheio, se tiver para a execucao
    return;

  int i = t - 1; // declara a variavel i que vai indicar a ultima posicao
  while (
      i >=
      0) { // enquanto o for maior ou igual a zero vai comprir a condicao aaixo
    v[i + 1] = v[i]; // desloca o vetor uma posicao a direita
    i--;             // depois decrementa
  }
  // A condicao acima vai deslocar os valores uma posicao para direita

  v[0] = x; // depois vai colocar na primeira posicao um valor x
}

void insere_inicio_2(int *v, int size, int x) {
  int t = espacos_ocupados(v, size); // declara-se uma variavel que vai receber
                                     // o numeros de espacos ocupados do vetor

  if (t == size) // verifica se o vetor esta cheio, se tiver para a execucao
    return;

  v[t] = v[0]; // se tiver mais espaco no vetor as linhas seguintes vao mover
               // para proxima posicao
  v[0] = x; // depois vai inserir um valor na primeira posicao
}

void insere_fim(int *v, int size, int x) {
  int t = espacos_ocupados(v, size); // declara-se uma variavel que vai receber
                                     // o numeros de espacos ocupados do vetor

  if (t == size) // verifica se o vetor esta cheio, se tiver para a execucao
    return;

  v[t] = x; // se nao coloca um valor na ultima posicao
}

int espacos_ocupados(int *v, int size) {
  int c = 0;
  // declara o variavel c contadora

  for (int i = 0; i < size; i++)
    // percorre o vetor ate i menor que o seu tamanho
    if (v[i] != 0)
      // depois verifica quais sao os espacos que foram ocupados
      c++;
  // a variavel c e incrementada ate terminar o ciclo
  return c;
  // retorna o numero de espacos preeenchidos
}

int contar(int *v, int size, int x) {
  int c = 0;
  // declara uma variavel c que vai contar os valores

  for (int i = 0; i < size; i++)
    // entra no ciclo for onde vai percorrer ate i menor que o tamanho do vetor
    if (v[i] == x)
      // se o vetor numa certa posicao for igual a x, entao conta esse valor
      c++;

  return c; // finaliza a funcao retornando a a variavel c contento a quantidade
            // que o numero se repete
}

void troca(int *num1, int *num2) {
  // Declara-se a funcao troca que vai receber o endereco de dois numeros
  int temp = *num1; // delara uma variavel temp que armazenar o valor do num1
  *num1 = *num2;    // depois coloca na variavel num1 o valor do num2
  *num2 = temp;     // apos isso o valor armazenar na variavel temp e passado na
                    // varivel num2
}

void separa_par_impar(int *v, int size) {
  int i = 0; // declara a variavel i que e incializada com zero
  for (int j = 0; j < size; j++) {
    // percorrer-se o vetor atraves da variavel j que foi inicializada como 0
    if (v[j] % 2 == 0) {
      // depois atraves da variavel j procura a os numeros pares
      troca(&v[i], &v[j]); // Entao troca os valores na posicao i e j, pois ele
                           // so procura os pares para um certo lado, e
                           // consequentemente estara separandos os impares
      i++; // depois incrementa
    }
  }
}

void separa_par_impar_2(int *v, int size) {
  // Declara-se uma funcao que recebe um ponteiro do array v e o tamanho do
  // mesmo array
  int i = 0; // declara-se a variavel i que e inicializada como 0
  int j =
      size -
      1; // declara-se a variavel i que e inicializada como no final do vetor

  while (i < j) {
    // O while vai verificar se i e menor que j, e enquanto se acontecer vai
    // executar o codigo abaixo
    if (v[i] % 2 == 0)
      // Apos a verificacao cai no if que procurar todos numeros que sao que sao
      // pares no array, e enquanto acontece a variavel i vai incrementado
      i++;
    else if (v[j] % 2 != 0)
      // Se nao cumprir a condicao acima ele verificara esse condicao procura se
      // o numero e impar e se for vai decrementar
      j--;
    else
      troca(&v[i], &v[j]);
    // quando nemhuma das condicoes acima sao satisfeitas chama-se a funcao que
    // vai trocar os dois valores
  }
}

void mover(int *v, int size, int x) {
  // E uma funcao que recebe um vetor de inteiros v, o tamanho do vetor  e um
  // valor inteiro x que sera removido
  int pos = buscar(v, size, x); // declara uma variavel pos que vai armazenar a
                                // posicao retornanda pela funcao buscar.

  if (pos == -1) { // se a posicao for -1, ela nao existe no vetor entao ira
                   // retornar o.
    return;
  }

  int i =
      pos; // Se existir o numero no vetor ele coloca essa posicao na variavel i
  while (i < size - 1) {
    // depois verifica enquanto a posicao i for menor que size menos 1, executa
    // a linha abaixo
    v[i] =
        v[i +
          1]; // começa a deslocar os elementos do vetor a partir da posição pos
              // para a esquerda, sobrescrevendo o elemento na posição pos.
    i++; // enquanto essa condicao se completa ele incrementa
  }

  // quando o While termina de executar coloca na posicao final o valor 0 e
  // termina a funcao
  v[size - 1] = 0;
}

int remover(int *v, int size, int x) {

    int t = espacos_ocupados(v, size);

  
    for (int i = 0; i < t; i++) {
        if (v[i] == x) {
            // verifica se o numero na posicao i e o x
            
            for (int j = i; j < t- 1; j++) {
                v[j] = v[j + 1]; //um ciclo que vai remover o numero desejado 
            }
            t--; // decrementa o tamanho do array depois de remover
        }
    }
    return t; // Retorna o novo tamanho do array
}

void remover_todos(int *v, int size, int x) {
  // A funcao foi declarada recebendo tres paramentros, um valor inteiro, o
  // tamanho do vetor, e o valor x
  int t = espacos_ocupados(v, size);

  // A Variavel t buscando quantos espacos tem o vetor
  for (int i = 0; i < t; i++) {
    // Depois entra em um loop que vai verificar de i=0 ate i<t procura ver se o
    // valor atual e igual a x.
    if (v[i] == x) {
      remover(v, size,
              x); // se for igual chama a funcao remover para remover o valor
      i--;
      t--;
      // Os valores de i e t vao decrementando ate que i seja igual 0., quando
      // isso aconteca a condicao if encerra e a condicao for, de modo que a
      // funcao para.
    }
  }
}

void remover_todos_2(int *v, int size, int x) {

  int t = espacos_ocupados(v, size); // declara-se uma variavel que vai receber
                                     // o numeros de espacos ocupados do vetor

  for (int i = 0, j = 0; i < t;
       i++) { // Um ciclo for que vai pecorrer o array em duas variaveis que sao
              // inicializada sendo zero
    if (v[i] != x) {
      // depois quando o valor na posicao i e diferente de x, o valor e colocado
      // na posicao j
      v[j] = v[i];
      j++; // incrementa ate que se feche o ciclo
    }
  }

  for (int j = 0; j < t;
       j++) { // depois cria-se um ciclo que vai remover todos os numeros
              // colocados na posicao j, sendo assim igualados a zero
    v[j] = 0;
  }
  // termina a funcao
}
