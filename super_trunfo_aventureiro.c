/******************************************************************************
Desafio: Super Trunfo - Nível Aventureiro (Intermediário)
Objetivo: Cadastrar, calcular novos atributos e exibir os dados de duas cartas.
*******************************************************************************/
#include <stdio.h>

int main()
{
    // Variáveis para a Carta 1
    char estado1;
    char codigo_carta1[4];
    char nome_cidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade_populacional1;
    float pib_per_capita1;

    // Variáveis para a Carta 2
    char estado2;
    char codigo_carta2[4];
    char nome_cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade_populacional2;
    float pib_per_capita2;

    // Instruções para o usuário
    printf("Bem-vindo ao cadastro de cartas do Super Trunfo - Nível Aventureiro!\n");
    printf("Você precisará inserir os dados de duas cartas.\n\n");

    // Leitura dos dados da Carta 1
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o Estado (uma letra de A a H): ");
    scanf(" %c", &estado1);
    getchar(); 

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%3s", codigo_carta1);
    getchar(); 

    printf("Digite o Nome da Cidade: ");
    scanf("%49[^
]", nome_cidade1);
    getchar(); 

    printf("Digite a População: ");
    scanf("%d", &populacao1);
    getchar(); 

    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);
    getchar(); 

    printf("Digite o PIB (em bilhões de reais, ex: 699.28): ");
    scanf("%f", &pib1);
    getchar(); 

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);
    getchar(); 
    printf("\n");

    // Leitura dos dados da Carta 2
    printf("--- Cadastro da Carta 2 ---\n");
    printf("Digite o Estado (uma letra de A a H): ");
    scanf(" %c", &estado2);
    getchar(); 

    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%3s", codigo_carta2);
    getchar(); 

    printf("Digite o Nome da Cidade: ");
    scanf("%49[^
]", nome_cidade2);
    getchar(); 

    printf("Digite a População: ");
    scanf("%d", &populacao2);
    getchar(); 

    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);
    getchar(); 

    printf("Digite o PIB (em bilhões de reais, ex: 300.50): ");
    scanf("%f", &pib2);
    getchar(); 

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);
    getchar(); 
    printf("\n");

    // Cálculos para a Carta 1
    // Densidade Populacional = População / Área
    densidade_populacional1 = (float)populacao1 / area1;
    // PIB per Capita = (PIB * 1,000,000,000) / População (assumindo PIB em bilhões)
    pib_per_capita1 = (pib1 * 1000000000) / populacao1;

    // Cálculos para a Carta 2
    densidade_populacional2 = (float)populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000) / populacao2;

    // Exibição dos dados da Carta 1
    printf("--- Carta 1 Cadastrada ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo_carta1);
    printf("Nome da Cidade: %s\n", nome_cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("\n");

    // Exibição dos dados da Carta 2
    printf("--- Carta 2 Cadastrada ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo_carta2);
    printf("Nome da Cidade: %s\n", nome_cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("\n");

    printf("Fim do cadastro - Nível Aventureiro.\n");

    return 0;
}
