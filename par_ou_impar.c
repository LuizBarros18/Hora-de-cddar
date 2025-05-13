#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero); // Lê um inteiro (%d) e guarda em 'numero'

    // Verifica se o resto da divisão por 2 é 0
    if (numero % 2 == 0) { // Se o resto de 'numero' dividido por 2 FOR IGUAL a 0...
        printf("%d é um número PAR.\n", numero);
    } else { // Senão (se o resto não for 0)...
        printf("%d é um número ÍMPAR.\n", numero);
    }

    return 0;
}
