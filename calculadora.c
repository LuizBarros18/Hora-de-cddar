#include <stdio.h>

int main() {
    int a = 10, b = 3;
    int soma, subtracao, multiplicacao, resto;
    float divisao;

    soma = a + b;          // soma = 10 + 3 = 13
    subtracao = a - b;     // subtracao = 10 - 3 = 7
    multiplicacao = a * b; // multiplicacao = 10 * 3 = 30
    divisao = (float)a / b;  // divisao = 10 / 3 = 3.333... (Veja a nota abaixo!)
    resto = a % b;         // resto = 10 dividido por 3 dá 3 e sobra 1

    printf("Soma: %d\n", soma);
    printf("Subtração: %d\n", subtracao);
    printf("Multiplicação: %d\n", multiplicacao);
    printf("Divisão: %.2f\n", divisao);
    printf("Resto: %d\n", resto);

    return 0;
}
