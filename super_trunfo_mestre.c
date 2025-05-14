/******************************************************************************
Desafio: Super Trunfo - Nível Mestre
Objetivo: Cadastrar cartas, calcular atributos, Super Poder e comparar cartas.
*******************************************************************************/
#include <stdio.h>

int main()
{
    // Variáveis para a Carta 1
    char estado1;
    char codigo_carta1[4];
    char nome_cidade1[50];
    unsigned long int populacao1; // Alterado para unsigned long int
    float area1;
    float pib1; // Em bilhões de reais
    int pontos_turisticos1;
    float densidade_populacional1;
    float pib_per_capita1;
    float super_poder1;

    // Variáveis para a Carta 2
    char estado2;
    char codigo_carta2[4];
    char nome_cidade2[50];
    unsigned long int populacao2; // Alterado para unsigned long int
    float area2;
    float pib2; // Em bilhões de reais
    int pontos_turisticos2;
    float densidade_populacional2;
    float pib_per_capita2;
    float super_poder2;

    // Strings para resultado da comparação
    // C1_VENCE_STR[0] -> Carta 2 venceu, C1_VENCE_STR[1] -> Carta 1 venceu
    char* C1_VENCE_STR[] = {"Carta 2 venceu", "Carta 1 venceu"};

    // Variáveis para armazenar o resultado da comparação (0 ou 1)
    int pop_c1_vence;
    int area_c1_vence;
    int pib_c1_vence;
    int pts_c1_vence;
    int den_c1_vence; // Carta 1 vence se densidade MENOR
    int pib_pc_c1_vence;
    int sp_c1_vence;

    // Instruções para o usuário
    printf("Bem-vindo ao Super Trunfo de Cidades - Nível Mestre!\n");
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

    printf("Digite a População (número grande): ");
    scanf("%lu", &populacao1); // %lu para unsigned long int
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

    printf("Digite a População (número grande): ");
    scanf("%lu", &populacao2); // %lu para unsigned long int
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
    densidade_populacional1 = (float)populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000.0f) / (float)populacao1;
    super_poder1 = (float)populacao1 + area1 + pib1 + (float)pontos_turisticos1 + pib_per_capita1 + (1.0f / densidade_populacional1);

    // Cálculos para a Carta 2
    densidade_populacional2 = (float)populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontos_turisticos2 + pib_per_capita2 + (1.0f / densidade_populacional2);
    
    // Exibição dos dados calculados (opcional, mas bom para depuração e verificação)
    // Removido para focar na saída de comparação conforme o exemplo do desafio mestre.
    /*
    printf("--- Dados Calculados Carta 1 ---\n");
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n\n", super_poder1);

    printf("--- Dados Calculados Carta 2 ---\n");
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n\n", super_poder2);
    */

    // Comparações (1 se Carta 1 vence, 0 se Carta 2 vence ou empate)
    pop_c1_vence = populacao1 > populacao2;
    area_c1_vence = area1 > area2;
    pib_c1_vence = pib1 > pib2;
    pts_c1_vence = pontos_turisticos1 > pontos_turisticos2;
    den_c1_vence = densidade_populacional1 < densidade_populacional2; // Menor densidade vence
    pib_pc_c1_vence = pib_per_capita1 > pib_per_capita2;
    sp_c1_vence = super_poder1 > super_poder2;

    // Exibição dos Resultados das Comparações
    printf("Comparação de Cartas:\n");
    printf("População: %s (%d)\n", C1_VENCE_STR[pop_c1_vence], pop_c1_vence);
    printf("Área: %s (%d)\n", C1_VENCE_STR[area_c1_vence], area_c1_vence);
    printf("PIB: %s (%d)\n", C1_VENCE_STR[pib_c1_vence], pib_c1_vence);
    printf("Pontos Turísticos: %s (%d)\n", C1_VENCE_STR[pts_c1_vence], pts_c1_vence);
    printf("Densidade Populacional: %s (%d)\n", C1_VENCE_STR[den_c1_vence], den_c1_vence);
    printf("PIB per Capita: %s (%d)\n", C1_VENCE_STR[pib_pc_c1_vence], pib_pc_c1_vence);
    printf("Super Poder: %s (%d)\n", C1_VENCE_STR[sp_c1_vence], sp_c1_vence);
    printf("\nFim da Batalha - Nível Mestre.\n");

    return 0;
}
