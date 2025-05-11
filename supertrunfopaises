#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a estrutura para uma carta do Super Trunfo
typedef struct {
    char nome[50];
    long int populacao; // Usar long int para populações grandes
    float area;         // em km²
    float idh;          // Índice de Desenvolvimento Humano
    // int trunfo;      // 1 se for trunfo, 0 caso contrário (simplificado, não implementado na lógica principal)
} CartaPais;

// Define o número de cartas no baralho
#define NUM_CARTAS_TOTAL 6 // Um número pequeno para facilitar o teste e desenvolvimento
#define ATRIBUTOS 3 // População, Área, IDH

// Estrutura para representar a mão de um jogador (usando array dinâmico simples)
typedef struct {
    CartaPais cartas[NUM_CARTAS_TOTAL];
    int num_cartas;
} MaoJogador;

// Protótipos das funções
void inicializarBaralhoCompleto(CartaPais baralho[]);
void embaralharCartas(CartaPais baralho[], int n);
void distribuirCartas(CartaPais baralho_completo[], MaoJogador *jogador, MaoJogador *computador);
void mostrarCarta(CartaPais carta, const char* nomeJogador);
int escolherAtributoJogador();
int escolherAtributoComputador(CartaPais carta);
void jogarRodada(MaoJogador *jogador, MaoJogador *computador, MaoJogador *monte_empate, int *jogadorDaVez);
void adicionarCartasAoVencedor(MaoJogador *vencedor, CartaPais cartaGanha1, CartaPais cartaGanha2, MaoJogador *monte_empate);
void removerCartaDoTopo(MaoJogador *mao);
void imprimirPontuacao(const MaoJogador *jogador, const MaoJogador *computador);

int main() {
    CartaPais baralho_completo[NUM_CARTAS_TOTAL];
    MaoJogador jogador, computador, monte_empate;
    jogador.num_cartas = 0;
    computador.num_cartas = 0;
    monte_empate.num_cartas = 0;

    int rodada = 1;
    int jogadorDaVez = 1; // 1 para jogador, 0 para computador (quem começa a primeira rodada)

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    printf("--- Bem-vindo ao Super Trunfo de Países! ---\n\n");

    // 1. Inicializar o baralho com os dados dos países
    inicializarBaralhoCompleto(baralho_completo);
    printf("Baralho inicializado com %d cartas.\n", NUM_CARTAS_TOTAL);

    // 2. Embaralhar as cartas
    embaralharCartas(baralho_completo, NUM_CARTAS_TOTAL);
    printf("Cartas embaralhadas!\n");

    // 3. Distribuir as cartas
    distribuirCartas(baralho_completo, &jogador, &computador);
    printf("Cartas distribuídas: %d para você e %d para o computador.\n\n", jogador.num_cartas, computador.num_cartas);

    // Loop principal do jogo
    while (jogador.num_cartas > 0 && computador.num_cartas > 0) {
        printf("\n--- Rodada %d ---\n", rodada);
        imprimirPontuacao(&jogador, &computador);

        if (jogadorDaVez) {
            printf("Sua vez de jogar!\n");
        } else {
            printf("Vez do Computador!\n");
        }

        jogarRodada(&jogador, &computador, &monte_empate, &jogadorDaVez);

        rodada++;
        // Pequena pausa para o jogador ler - pode ser útil
        // printf("Pressione Enter para continuar...");
        // while(getchar() != '\n' && getchar() != EOF); // Limpa o buffer de entrada
        // getchar(); // Espera por um Enter

    }

    // Fim do jogo
    printf("\n--- FIM DE JOGO ---\n");
    imprimirPontuacao(&jogador, &computador);
    if (jogador.num_cartas > 0) {
        printf("Parabéns! Você venceu o jogo!\n");
    } else {
        printf("Que pena! O computador venceu desta vez.\n");
    }

    return 0;
}

void inicializarBaralhoCompleto(CartaPais baralho[]) {
    strcpy(baralho[0].nome, "Brasil");
    baralho[0].populacao = 213993437;
    baralho[0].area = 8515767.0f;
    baralho[0].idh = 0.754f;

    strcpy(baralho[1].nome, "Argentina");
    baralho[1].populacao = 45376763;
    baralho[1].area = 2780400.0f;
    baralho[1].idh = 0.842f;

    strcpy(baralho[2].nome, "Canada");
    baralho[2].populacao = 38005238;
    baralho[2].area = 9984670.0f;
    baralho[2].idh = 0.936f;

    strcpy(baralho[3].nome, "Japao");
    baralho[3].populacao = 125800000;
    baralho[3].area = 377975.0f;
    baralho[3].idh = 0.925f;

    strcpy(baralho[4].nome, "Alemanha");
    baralho[4].populacao = 83200000;
    baralho[4].area = 357022.0f;
    baralho[4].idh = 0.942f;

    strcpy(baralho[5].nome, "India");
    baralho[5].populacao = 1393400000; 
    baralho[5].area = 3287590.0f;
    baralho[5].idh = 0.633f;
}

void embaralharCartas(CartaPais baralho[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        CartaPais temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void distribuirCartas(CartaPais baralho_completo[], MaoJogador *jogador, MaoJogador *computador) {
    int i;
    for (i = 0; i < NUM_CARTAS_TOTAL / 2; i++) {
        jogador->cartas[i] = baralho_completo[i];
        jogador->num_cartas++;
    }
    for (int j = 0; i < NUM_CARTAS_TOTAL; i++, j++) {
        computador->cartas[j] = baralho_completo[i];
        computador->num_cartas++;
    }
}

void mostrarCarta(CartaPais carta, const char* nomeJogador) {
    printf("\nCarta de %s: %s\n", nomeJogador, carta.nome);
    printf("1. População: %ld\n", carta.populacao);
    printf("2. Área (km²): %.2f\n", carta.area);
    printf("3. IDH: %.3f\n", carta.idh);
}

int escolherAtributoJogador() {
    int escolha = 0;
    char buffer[10];
    do {
        printf("Escolha o atributo para comparar (1-População, 2-Área, 3-IDH): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &escolha) == 1) {
                 if (escolha >= 1 && escolha <= ATRIBUTOS) {
                    break; // Entrada válida
                 } else {
                    printf("Escolha inválida. Tente novamente.\n");
                 }
            } else {
                printf("Entrada não numérica. Tente novamente.\n");
            }
        } else {
            // Tratar erro de leitura ou EOF
            printf("Erro ao ler entrada. Tente novamente.\n");
            // Limpar erro do stdin se necessário, ou sair
            clearerr(stdin);
        }
    } while (1);
    return escolha;
}

int escolherAtributoComputador(CartaPais carta) {
    // Estratégia simples: escolhe o atributo com o maior valor numérico (normalizado toscamente)
    double valPop = (double)carta.populacao / 1000000.0; // Escala para comparar melhor
    double valArea = (double)carta.area / 100000.0;    // Escala para comparar melhor
    double valIdh = carta.idh * 100.0;                   // Escala para comparar melhor

    // printf("[DEBUG Computador] Valores para %s: Pop: %.2f, Area: %.2f, IDH: %.2f\n", carta.nome, valPop, valArea, valIdh);

    if (valPop >= valArea && valPop >= valIdh) return 1; 
    if (valArea >= valPop && valArea >= valIdh) return 2; 
    return 3; 
}

void adicionarCartasAoVencedor(MaoJogador *vencedor, CartaPais cartaGanha1, CartaPais cartaGanha2, MaoJogador *monte_empate) {
    // Adiciona as cartas da rodada ao monte do vencedor
    vencedor->cartas[vencedor->num_cartas++] = cartaGanha1;
    vencedor->cartas[vencedor->num_cartas++] = cartaGanha2;

    // Se houver cartas no monte de empate, o vencedor leva todas elas também
    int cartasDoMonteEmpateAdicionadas = 0;
    while(monte_empate->num_cartas > 0) {
        CartaPais cartaDoMonte = monte_empate->cartas[0]; // Pega a primeira carta do monte de empate
        // Adiciona ao vencedor
        vencedor->cartas[vencedor->num_cartas++] = cartaDoMonte;
        // Remove do monte de empate (deslocando as restantes)
        for(int i=0; i < monte_empate->num_cartas -1; ++i) {
            monte_empate->cartas[i] = monte_empate->cartas[i+1];
        }
        monte_empate->num_cartas--;
        cartasDoMonteEmpateAdicionadas++;
    }
    if (cartasDoMonteEmpateAdicionadas > 0) {
        // printf("%d carta(s) do monte de empate foram para o vencedor.\n", cartasDoMonteEmpateAdicionadas);
    }
}

void removerCartaDoTopo(MaoJogador *mao) {
    if (mao->num_cartas > 0) {
        // Desloca todas as cartas uma posição para frente
        // A carta do topo (índice 0) é "perdida" e as outras sobem
        for (int i = 0; i < mao->num_cartas - 1; i++) {
            mao->cartas[i] = mao->cartas[i + 1];
        }
        mao->num_cartas--;
    } else {
        // Isso não deveria acontecer em um jogo normal se a lógica de fim de jogo estiver correta
        // printf("Erro: Tentativa de remover carta de uma mão vazia.\n");
    }
}

void jogarRodada(MaoJogador *jogador, MaoJogador *computador, MaoJogador *monte_empate, int *jogadorDaVez) {
    if (jogador->num_cartas == 0 || computador->num_cartas == 0) return;

    CartaPais cartaJogador = jogador->cartas[0];
    CartaPais cartaComputador = computador->cartas[0];
    int atributoEscolhido;
    int vencedorRodada = 0; // 0: Empate, 1: Jogador, 2: Computador

    if (*jogadorDaVez) {
        mostrarCarta(cartaJogador, "Jogador");
        atributoEscolhido = escolherAtributoJogador();
    } else {
        mostrarCarta(cartaComputador, "Computador");
        atributoEscolhido = escolherAtributoComputador(cartaComputador);
        const char* nomesAtributos[] = {"População", "Área", "IDH"};
        printf("Computador escolheu: %s\n", nomesAtributos[atributoEscolhido-1]);
    }
    
    // Mostra a carta do oponente também para o jogador ver a comparação
    if (*jogadorDaVez) {
         mostrarCarta(cartaComputador, "Computador (Oponente)");
    } else {
         mostrarCarta(cartaJogador, "Jogador (Oponente)");
    }

    printf("\n--- Comparando Cartas ---\n");

    long int valJogadorPop = cartaJogador.populacao;
    float valJogadorArea = cartaJogador.area;
    float valJogadorIdh = cartaJogador.idh;

    long int valComputadorPop = computador->cartas[0].populacao;
    float valComputadorArea = computador->cartas[0].area;
    float valComputadorIdh = computador->cartas[0].idh;


    printf("Atributo escolhido: ");
    switch (atributoEscolhido) {
        case 1: // População
            printf("População\n");
            printf("%s: %ld vs %s: %ld\n", cartaJogador.nome, valJogadorPop, cartaComputador.nome, valComputadorPop);
            if (valJogadorPop > valComputadorPop) vencedorRodada = 1;
            else if (valComputadorPop > valJogadorPop) vencedorRodada = 2;
            break;
        case 2: // Área
            printf("Área\n");
            printf("%s: %.2f vs %s: %.2f\n", cartaJogador.nome, valJogadorArea, cartaComputador.nome, valComputadorArea);
            if (valJogadorArea > valComputadorArea) vencedorRodada = 1;
            else if (valComputadorArea > valJogadorArea) vencedorRodada = 2;
            break;
        case 3: // IDH
            printf("IDH\n");
            printf("%s: %.3f vs %s: %.3f\n", cartaJogador.nome, valJogadorIdh, cartaComputador.nome, valComputadorIdh);
            if (valJogadorIdh > valComputadorIdh) vencedorRodada = 1;
            else if (valComputadorIdh > valJogadorIdh) vencedorRodada = 2;
            break;
    }

    // As cartas são removidas das mãos dos jogadores ANTES de serem adicionadas ao vencedor ou ao monte de empate
    removerCartaDoTopo(jogador); 
    removerCartaDoTopo(computador);

    if (vencedorRodada == 1) {
        printf("Você ganhou a rodada!\n");
        int cartasDoMonteAntes = monte_empate->num_cartas;
        adicionarCartasAoVencedor(jogador, cartaJogador, cartaComputador, monte_empate);
        if (cartasDoMonteAntes > 0) printf("Você também levou %d carta(s) do monte de empate!\n", cartasDoMonteAntes);
        *jogadorDaVez = 1; // Jogador que ganhou começa a próxima
    } else if (vencedorRodada == 2) {
        printf("O Computador ganhou a rodada!\n");
        int cartasDoMonteAntes = monte_empate->num_cartas;
        adicionarCartasAoVencedor(computador, cartaJogador, cartaComputador, monte_empate);
         if (cartasDoMonteAntes > 0) printf("O computador também levou %d carta(s) do monte de empate!\n", cartasDoMonteAntes);
        *jogadorDaVez = 0; // Computador que ganhou começa a próxima
    } else {
        printf("Empate! As cartas (%s e %s) vão para o monte de empate.\n", cartaJogador.nome, cartaComputador.nome);
        monte_empate->cartas[monte_empate->num_cartas++] = cartaJogador;
        monte_empate->cartas[monte_empate->num_cartas++] = cartaComputador;
        // Quem começa a próxima rodada: pode ser quem começou esta, ou alternar.
        // No Super Trunfo clássico, se não me engano, quem jogou e empatou, joga de novo.
        // Se o jogadorDaVez era 1 (jogador) e empatou, ele continua 1.
        // Se era 0 (computador) e empatou, continua 0.
        // A lógica atual de *jogadorDaVez não mudar em caso de empate já faz isso.
    }
}

void imprimirPontuacao(const MaoJogador *jogador, const MaoJogador *computador) {
    printf("PLACAR: Jogador %d cartas | Computador %d cartas\n", jogador->num_cartas, computador->num_cartas);
}


