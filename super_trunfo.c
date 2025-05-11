#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

void mostrar_carta(Carta c) {
    printf("Nome: %s\n", c.nome);
    printf("Força: %d\n", c.forca);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Inteligência: %d\n", c.inteligencia);
}

int main() {
    Carta carta1 = {"Dragão", 90, 70, 60};
    Carta carta2 = {"Fênix", 85, 75, 80};

    int escolha;

    printf("Sua carta:\n");
    mostrar_carta(carta1);

    printf("\nEscolha o atributo para competir:\n");
    printf("1 - Força\n2 - Velocidade\n3 - Inteligência\n");
    printf("Digite o número: ");
    scanf("%d", &escolha);

    int valor1, valor2;
    switch (escolha) {
        case 1:
            valor1 = carta1.forca;
            valor2 = carta2.forca;
            break;
        case 2:
            valor1 = carta1.velocidade;
            valor2 = carta2.velocidade;
            break;
        case 3:
            valor1 = carta1.inteligencia;
            valor2 = carta2.inteligencia;
            break;
        default:
            printf("Escolha inválida.\n");
            return 1;
    }

    printf("\nCarta do oponente:\n");
    mostrar_carta(carta2);

    printf("\nResultado:\n");
    if (valor1 > valor2) {
        printf("Você venceu!\n");
    } else if (valor1 < valor2) {
        printf("Você perdeu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
