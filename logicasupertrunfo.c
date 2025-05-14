// Inclusão de bibliotecas padrão necessárias
#include <stdio.h>
#include <string.h> // Para operações com strings, como strcpy

// Definição da estrutura para representar uma carta do Super Trunfo
struct Carta {
    char estado[3];                 // Sigla do estado (ex: "SP")
    char codigo_carta[5];           // Código único da carta (ex: "SP01")
    char nome_cidade[50];           // Nome da cidade ou capital
    int populacao;                  // Número de habitantes
    float area;                     // Área em km²
    double pib;                     // Produto Interno Bruto em R$
    int pontos_turisticos;          // Número de pontos turísticos relevantes
    float densidade_populacional;   // Calculado: População / Área
    double pib_per_capita;          // Calculado: PIB / População
};

// Função principal do programa
int main() {
    // Comentário: Declaração e inicialização de duas cartas pré-definidas.
    struct Carta carta1;
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo_carta, "SP01");
    strcpy(carta1.nome_cidade, "Sao Paulo");
    carta1.populacao = 12396372;
    carta1.area = 1521.11f;
    carta1.pib = 748000000000.00;
    carta1.pontos_turisticos = 10;

    struct Carta carta2;
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo_carta, "RJ01");
    strcpy(carta2.nome_cidade, "Rio de Janeiro");
    carta2.populacao = 6775561;
    carta2.area = 1200.329f;
    carta2.pib = 358000000000.00;
    carta2.pontos_turisticos = 8;

    // Comentário: Cálculo dos atributos derivados para ambas as cartas.
    // Densidade Populacional = População / Área
    // PIB per capita = PIB / População
    if (carta1.area > 0) {
        carta1.densidade_populacional = (float)carta1.populacao / carta1.area;
    } else {
        carta1.densidade_populacional = 0; // Evita divisão por zero
    }
    if (carta1.populacao > 0) {
        carta1.pib_per_capita = carta1.pib / carta1.populacao;
    } else {
        carta1.pib_per_capita = 0; // Evita divisão por zero
    }

    if (carta2.area > 0) {
        carta2.densidade_populacional = (float)carta2.populacao / carta2.area;
    } else {
        carta2.densidade_populacional = 0; // Evita divisão por zero
    }
    if (carta2.populacao > 0) {
        carta2.pib_per_capita = carta2.pib / carta2.populacao;
    } else {
        carta2.pib_per_capita = 0; // Evita divisão por zero
    }

    // Comentário: Escolha do atributo para comparação (fixo no código).
    // Atributo escolhido: População.
    // Para População, Área, PIB, PIB per capita e Pontos Turísticos, o maior valor vence.
    // Para Densidade Populacional, o menor valor vence.
    char atributo_comparado_nome[50] = "Populacao";
    // Para este exemplo, vamos comparar a População. Poderia ser qualquer outro atributo numérico.
    // Se fosse Densidade Populacional, a lógica de vitória seria invertida (menor vence).
    long int valor_carta1_comparado = carta1.populacao;
    long int valor_carta2_comparado = carta2.populacao;
    int carta_vencedora = 0; // 0 para empate, 1 se carta1 vence, 2 se carta2 vence

    // Comentário: Lógica de comparação utilizando if e if-else.
    if (valor_carta1_comparado > valor_carta2_comparado) {
        carta_vencedora = 1;
    } else if (valor_carta2_comparado > valor_carta1_comparado) {
        carta_vencedora = 2;
    } else {
        carta_vencedora = 0; // Empate
    }

    // Comentário: Exibição do resultado da comparação.
    printf("Comparacao de cartas (Atributo: %s):\n\n", atributo_comparado_nome);
    printf("Carta 1 - %s (%s): %ld\n", carta1.nome_cidade, carta1.estado, valor_carta1_comparado);
    printf("Carta 2 - %s (%s): %ld\n\n", carta2.nome_cidade, carta2.estado, valor_carta2_comparado);

    if (carta_vencedora == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta_vencedora == 2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
    
    // Exibe também os valores calculados de Densidade Populacional e PIB per capita
    printf("\n--- Dados Adicionais ---\n");
    printf("Carta 1 (%s - %s):\n", carta1.nome_cidade, carta1.estado);
    printf("  Densidade Populacional: %.2f hab/km^2\n", carta1.densidade_populacional);
    printf("  PIB per capita: R$ %.2f\n", carta1.pib_per_capita);

    printf("\nCarta 2 (%s - %s):\n", carta2.nome_cidade, carta2.estado);
    printf("  Densidade Populacional: %.2f hab/km^2\n", carta2.densidade_populacional);
    printf("  PIB per capita: R$ %.2f\n", carta2.pib_per_capita);

    return 0; // Indica que o programa terminou com sucesso
