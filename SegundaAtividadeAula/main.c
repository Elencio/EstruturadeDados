#include <stdio.h>

int main(void) {

  int numero;
  int soma;
  int valor1 = 5, valor2 = 10; //declaracao das variaveis

  printf("Digite um número inteiro positivo: ");
  scanf("%d", &numero); // Nesse trecho comeca o programa onde vai receber um// numero inteiro, dessa forma procurar-si-a numeros
// pares no intervalo de 0 ate numero inserido;

  soma = somaDeNumerosPares(numero); // Aqui chama-se a funcao que procura os
  // numeros pares e faz a soma dos mesmos.

  printf("A soma de todos os números pares de 1 a %d é %d.\n", numero,soma); // Aqui o programa faz o print da soma dos numeros pares;


  

  printf("## \n\nPrograma 02, trocar variaveis atraves de ponteiros \n\n");

  printf("Antes da troca: valor1 = %d, valor1 = %d\n", valor1, valor2);

  trocaDeNumerosAtravesDePonteiros(&valor1, &valor2); //chama a funcao que recebe o conteudo de x e y;

  printf("Depois da troca: valor1 = %d, valor2 = %d\n", valor1, valor2);

  return 0; // Encerra o programa
}


int somaDeNumerosPares(
    int n) { // Criou-se uma funcao que vai receber um numero que sera digitado
             // pelo usuario, e partindo de 0 a esse numero o programa vai
             // procurar os numeros pares.
  int sum = 0; // nesse trecho declara uma variavel sum que vai armazenar a soma
               // dos mumeros pares

  for (int i = 2; i <= n;
       i += 2) { // Em seguida, fez-se um loop for para somar todos os números
    // pares de 1 a n. Iniciou-se a variável i em 2 e // incrementou-se de 2 em
    // 2 até i ser menor ou igual a n. Dentro do loop, adiciou-se o valor de i à
    // variável sum
    sum += i;
  }

  return sum; // depois retorna a soma dos numeros pares;
}



//Primeiro a funcao recebe dois ponteiros para numeros inteirosn a e b que apontam para variaveis.

int trocaDeNumerosAtravesDePonteiros(int *a, int *b) { 
  int temp;

  temp = *a; // o valor apontado por a é armazenado na variável temporária temp 
  *a = *b;  //o valor apontado por b é copiado para o local apontado por a 
  *b = temp; // o valor armazenado em temp é copiado para o local apontado por b

  
}
