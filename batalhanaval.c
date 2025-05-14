#include <stdio.h>

// Constantes para o Nível Novato
#define TAMANHO_NOVATO 5
#define AGUA_NOVATO 0
#define NAVIO_NOVATO 2

// Protótipos das funções - Nível Novato
void inicializar_tabuleiro_novato(int tabuleiro[TAMANHO_NOVATO][TAMANHO_NOVATO]);
void exibir_tabuleiro_novato(int tabuleiro[TAMANHO_NOVATO][TAMANHO_NOVATO]);
void posicionar_navios_novato(int tabuleiro[TAMANHO_NOVATO][TAMANHO_NOVATO]);
void exibir_coordenadas_navios_novato(int tabuleiro[TAMANHO_NOVATO][TAMANHO_NOVATO]);

// Constantes para o Nível Aventureiro
#define TAMANHO_AVENTUREIRO 10
#define AGUA_AVENTUREIRO 0
#define NAVIO_AVENTUREIRO 3

// Protótipos das funções - Nível Aventureiro
void inicializar_tabuleiro_aventureiro(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO]);
void exibir_tabuleiro_aventureiro(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO]);
int validar_posicao_navio(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO], int linha, int coluna, int tamanho, char orientacao);
void posicionar_navios_aventureiro(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO]);

// Constantes para o Nível Mestre
#define AFETADA_HABILIDADE 1
#define NAO_AFETADA_HABILIDADE 0

// Protótipos das funções - Nível Mestre
void inicializar_tabuleiro_habilidade(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO]);
void aplicar_habilidade_cone(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO], int origem_linha, int origem_coluna, int profundidade);
void aplicar_habilidade_cruz(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO], int centro_linha, int centro_coluna, int braco_tamanho);
void aplicar_habilidade_octaedro(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO], int centro_linha, int centro_coluna, int raio);

int main() {
    printf("Desafio Batalha Naval - Todos os Níveis\n");
    printf("----------------------------------------\n\n");

    // Nível Novato - Demonstração
    printf("### Nível Novato ###\n");
    int tabuleiro_novato[TAMANHO_NOVATO][TAMANHO_NOVATO];

    inicializar_tabuleiro_novato(tabuleiro_novato);
    printf("Tabuleiro Novato Inicializado (5x5 com água '%d'):\n", AGUA_NOVATO);
    exibir_tabuleiro_novato(tabuleiro_novato);

    posicionar_navios_novato(tabuleiro_novato);
    printf("\nTabuleiro Novato com Navios Posicionados (navio '%d'):\n", NAVIO_NOVATO);
    exibir_tabuleiro_novato(tabuleiro_novato);

    printf("\nCoordenadas dos Navios no Tabuleiro Novato:\n");
    exibir_coordenadas_navios_novato(tabuleiro_novato);

    printf("\n----------------------------------------\n");

    // Nível Aventureiro - Demonstração
    printf("\n### Nível Aventureiro ###\n");
    int tabuleiro_aventureiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO];

    inicializar_tabuleiro_aventureiro(tabuleiro_aventureiro);
    printf("Tabuleiro Aventureiro Inicializado (10x10 com água '%d'):\n", AGUA_AVENTUREIRO);
    exibir_tabuleiro_aventureiro(tabuleiro_aventureiro);

    posicionar_navios_aventureiro(tabuleiro_aventureiro);
    printf("\nTabuleiro Aventureiro com Navios Posicionados (navio '%d'):\n", NAVIO_AVENTUREIRO);
    exibir_tabuleiro_aventureiro(tabuleiro_aventureiro);

    printf("\n----------------------------------------\n");

    // Nível Mestre - Demonstração Habilidades Especiais
    printf("\n### Nível Mestre - Habilidades Especiais ###\n");
    int tabuleiro_habilidades[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO];

    // Habilidade Cone
    inicializar_tabuleiro_habilidade(tabuleiro_habilidades);
    // Exemplo: Cone com vértice em [2][4] e profundidade 3
    // 0 0 0 0 0
    // 0 0 0 1 0 0 -> i=0, j=0 (origem_coluna+j = 4)
    // 0 0 1 1 1 0 -> i=1, j=-1,0,1 (origem_coluna+j = 3,4,5)
    // 0 1 1 1 1 1 -> i=2, j=-2,-1,0,1,2 (origem_coluna+j = 2,3,4,5,6)
    aplicar_habilidade_cone(tabuleiro_habilidades, 2, 4, 3);
    printf("\nTabuleiro com Habilidade Cone (origem [2][4], profundidade 3) - '%d' representa área afetada:\n", AFETADA_HABILIDADE);
    exibir_tabuleiro_aventureiro(tabuleiro_habilidades); 

    // Habilidade Cruz
    inicializar_tabuleiro_habilidade(tabuleiro_habilidades);
    // Exemplo: Cruz com centro em [4][4] e braços de tamanho 2
    // 0 0 0 1 0 0 0
    // 0 0 0 1 0 0 0
    // 0 1 1 1 1 1 0
    // 0 0 0 1 0 0 0
    // 0 0 0 1 0 0 0
    aplicar_habilidade_cruz(tabuleiro_habilidades, 4, 4, 2);
    printf("\nTabuleiro com Habilidade Cruz (centro [4][4], braço 2) - '%d' representa área afetada:\n", AFETADA_HABILIDADE);
    exibir_tabuleiro_aventureiro(tabuleiro_habilidades);

    // Habilidade Octaedro
    inicializar_tabuleiro_habilidade(tabuleiro_habilidades);
    // Exemplo: Octaedro com centro em [5][5] e raio 2
    // 0 0 0 0 1 0 0 0 0
    // 0 0 0 1 1 1 0 0 0
    // 0 0 1 1 1 1 1 0 0
    // 0 1 1 1 1 1 1 1 0
    // 1 1 1 1 1 1 1 1 1
    // 0 1 1 1 1 1 1 1 0
    // 0 0 1 1 1 1 1 0 0
    // 0 0 0 1 1 1 0 0 0
    // 0 0 0 0 1 0 0 0 0
    aplicar_habilidade_octaedro(tabuleiro_habilidades, 5, 5, 2);
    printf("\nTabuleiro com Habilidade Octaedro (centro [5][5], raio 2) - '%d' representa área afetada:\n", AFETADA_HABILIDADE);
    exibir_tabuleiro_aventureiro(tabuleiro_habilidades);

    printf("\n----------------------------------------\n");
    printf("Fim da demonstração.\n");

    return 0;
}

// Implementações das funções - Nível Novato

/**
 * @brief Inicializa o tabuleiro do Nível Novato com água.
 * 
 * @param tabuleiro A matriz 5x5 do tabuleiro.
 */
void inicializar_tabuleiro_novato(int tabuleiro[TAMANHO_NOVATO][TAMANHO_NOVATO]) {
    for (int i = 0; i < TAMANHO_NOVATO; i++) {
        for (int j = 0; j < TAMANHO_NOVATO; j++) {
            tabuleiro[i][j] = AGUA_NOVATO;
        }
    }
}

/**
 * @brief Exibe o tabuleiro do Nível Novato no console.
 * 
 * @param tabuleiro A matriz 5x5 do tabuleiro.
 */
void exibir_tabuleiro_novato(int tabuleiro[TAMANHO_NOVATO][TAMANHO_NOVATO]) {
    printf("  "); // Espaço para alinhar com os índices das colunas
    for (int j = 0; j < TAMANHO_NOVATO; j++) {
        printf("%d ", j); // Imprime índices das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_NOVATO; i++) {
        printf("%d ", i); // Imprime índices das linhas
        for (int j = 0; j < TAMANHO_NOVATO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Posiciona dois navios no tabuleiro do Nível Novato.
 * Navio 1: Horizontal, tamanho 3, na linha 1, começando na coluna 1.
 * Navio 2: Vertical, tamanho 2, na coluna 3, começando na linha 3.
 * As posições são fixas e validadas internamente de forma simples.
 * 
 * @param tabuleiro A matriz 5x5 do tabuleiro.
 */
void posicionar_navios_novato(int tabuleiro[TAMANHO_NOVATO][TAMANHO_NOVATO]) {
    // Navio 1: Horizontal (tamanho 3)
    // Linha 1, Colunas 1, 2, 3
    if (1 < TAMANHO_NOVATO && (1 + 2) < TAMANHO_NOVATO) { // Checagem básica de limites para linha e coluna final
        tabuleiro[1][1] = NAVIO_NOVATO;
        tabuleiro[1][2] = NAVIO_NOVATO;
        tabuleiro[1][3] = NAVIO_NOVATO;
    } else {
        printf("Falha ao posicionar Navio 1 Novato (Horizontal).\n");
    }

    // Navio 2: Vertical (tamanho 2)
    // Coluna 3, Linhas 3, 4
    if (3 < TAMANHO_NOVATO && (3 + 1) < TAMANHO_NOVATO && 3 < TAMANHO_NOVATO) { // Checagem básica de limites para linha final e coluna
         if (tabuleiro[3][3] == AGUA_NOVATO && tabuleiro[4][3] == AGUA_NOVATO) { // Checagem básica de sobreposição
            tabuleiro[3][3] = NAVIO_NOVATO;
            tabuleiro[4][3] = NAVIO_NOVATO;
        } else {
             printf("Falha ao posicionar Navio 2 Novato (Vertical) - Sobreposição.\n");
        }
    } else {
        printf("Falha ao posicionar Navio 2 Novato (Vertical) - Limites.\n");
    }
}

/**
 * @brief Exibe as coordenadas de todas as partes dos navios no tabuleiro Novato.
 * 
 * @param tabuleiro A matriz 5x5 do tabuleiro.
 */
void exibir_coordenadas_navios_novato(int tabuleiro[TAMANHO_NOVATO][TAMANHO_NOVATO]) {
    int encontrou_navio = 0;
    for (int i = 0; i < TAMANHO_NOVATO; i++) {
        for (int j = 0; j < TAMANHO_NOVATO; j++) {
            if (tabuleiro[i][j] == NAVIO_NOVATO) {
                printf("- Navio em: [%d][%d]\n", i, j);
                encontrou_navio = 1;
            }
        }
    }
    if (!encontrou_navio) {
        printf("Nenhum navio encontrado no tabuleiro Novato.\n");
    }
}


// Implementações das funções - Nível Aventureiro

/**
 * @brief Inicializa o tabuleiro do Nível Aventureiro com água.
 * 
 * @param tabuleiro A matriz 10x10 do tabuleiro.
 */
void inicializar_tabuleiro_aventureiro(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO]) {
    for (int i = 0; i < TAMANHO_AVENTUREIRO; i++) {
        for (int j = 0; j < TAMANHO_AVENTUREIRO; j++) {
            tabuleiro[i][j] = AGUA_AVENTUREIRO;
        }
    }
}

/**
 * @brief Exibe o tabuleiro do Nível Aventureiro no console.
 * Usado também para exibir tabuleiro com habilidades no Nível Mestre.
 * 
 * @param tabuleiro A matriz 10x10 do tabuleiro.
 */
void exibir_tabuleiro_aventureiro(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO]) {
    printf("   "); // Espaço para alinhar com os índices das colunas
    for (int j = 0; j < TAMANHO_AVENTUREIRO; j++) {
        printf("%2d ", j); // Imprime índices das colunas com 2 dígitos para alinhamento
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_AVENTUREIRO; i++) {
        printf("%2d ", i); // Imprime índices das linhas com 2 dígitos
        for (int j = 0; j < TAMANHO_AVENTUREIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Valida se um navio pode ser posicionado no local especificado.
 * Verifica limites do tabuleiro e sobreposição com outros navios.
 * 
 * @param tabuleiro O tabuleiro do jogo.
 * @param linha Linha inicial do navio.
 * @param coluna Coluna inicial do navio.
 * @param tamanho Tamanho do navio.
 * @param orientacao 'H' para horizontal, 'V' para vertical, 'D' para diagonal principal, 'S' para diagonal secundária.
 * @return int 1 se a posição é válida, 0 caso contrário.
 */
int validar_posicao_navio(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO], int linha, int coluna, int tamanho, char orientacao) {
    for (int i = 0; i < tamanho; i++) {
        int r = linha;
        int c = coluna;

        if (orientacao == 'H') {
            c += i;
        } else if (orientacao == 'V') {
            r += i;
        } else if (orientacao == 'D') { // Diagonal principal (linha++, coluna++)
            r += i;
            c += i;
        } else if (orientacao == 'S') { // Diagonal secundária (linha++, coluna--)
            r += i;
            c -= i;
        } else {
            // printf("Erro: Orientação inválida %c\n", orientacao);
            return 0; // Orientação inválida
        }

        if (r < 0 || r >= TAMANHO_AVENTUREIRO || c < 0 || c >= TAMANHO_AVENTUREIRO) {
            // printf("Erro: Navio fora dos limites em [%d][%d] para orientação %c, tamanho %d\n", linha, coluna, orientacao, tamanho);
            return 0; // Fora dos limites
        }
        if (tabuleiro[r][c] != AGUA_AVENTUREIRO) {
            // printf("Erro: Sobreposição de navio em [%d][%d] para orientação %c, tamanho %d\n", linha, coluna, orientacao, tamanho);
            return 0; // Posição já ocupada
        }
    }
    return 1; // Posição válida
}

/**
 * @brief Posiciona quatro navios no tabuleiro do Nível Aventureiro.
 * Dois navios horizontal/vertical e dois na diagonal.
 * As posições são fixas e validadas.
 * 
 * @param tabuleiro A matriz 10x10 do tabuleiro.
 */
void posicionar_navios_aventureiro(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO]) {
    // Navio 1: Horizontal, tamanho 4 (ex: linha 1, colunas 1 a 4)
    int l1 = 1, c1 = 1, tam1 = 4;
    char o1 = 'H';
    if (validar_posicao_navio(tabuleiro, l1, c1, tam1, o1)) {
        for (int i = 0; i < tam1; i++) {
            tabuleiro[l1][c1 + i] = NAVIO_AVENTUREIRO;
        }
    } else {
        printf("Falha ao posicionar Navio 1 Aventureiro (Horizontal) em [%d][%d] com tamanho %d\n", l1, c1, tam1);
    }

    // Navio 2: Vertical, tamanho 3 (ex: coluna 6, linhas 3 a 5)
    int l2 = 3, c2 = 6, tam2 = 3;
    char o2 = 'V';
    if (validar_posicao_navio(tabuleiro, l2, c2, tam2, o2)) {
        for (int i = 0; i < tam2; i++) {
            tabuleiro[l2 + i][c2] = NAVIO_AVENTUREIRO;
        }
    } else {
        printf("Falha ao posicionar Navio 2 Aventureiro (Vertical) em [%d][%d] com tamanho %d\n", l2, c2, tam2);
    }

    // Navio 3: Diagonal principal (linha++, coluna++), tamanho 3 (ex: começando em 7,0 -> (7,0), (8,1), (9,2))
    int l3 = 7, c3 = 0, tam3 = 3;
    char o3 = 'D';
    if (validar_posicao_navio(tabuleiro, l3, c3, tam3, o3)) {
        for (int i = 0; i < tam3; i++) {
            tabuleiro[l3 + i][c3 + i] = NAVIO_AVENTUREIRO;
        }
    } else {
        printf("Falha ao posicionar Navio 3 Aventureiro (Diagonal Principal) em [%d][%d] com tamanho %d\n", l3, c3, tam3);
    }

    // Navio 4: Diagonal secundária (linha++, coluna--), tamanho 2 (ex: começando em 0,8 -> (0,8), (1,7) para não colidir com o limite em 0,9)
    // Ajustado para 0,8 para caber no tabuleiro 10x10 (0,9 e 1,8)
    int l4 = 0, c4 = 8, tam4 = 2; // Alterado c4 de 9 para 8
    char o4 = 'S';
    if (validar_posicao_navio(tabuleiro, l4, c4, tam4, o4)) {
        for (int i = 0; i < tam4; i++) {
            tabuleiro[l4 + i][c4 - i] = NAVIO_AVENTUREIRO;
        }
    } else {
        printf("Falha ao posicionar Navio 4 Aventureiro (Diagonal Secundária) em [%d][%d] com tamanho %d\n", l4, c4, tam4);
    }
}


// Implementações das funções - Nível Mestre

/**
 * @brief Inicializa um tabuleiro para demonstrar habilidades, preenchendo com NAO_AFETADA_HABILIDADE.
 * 
 * @param tabuleiro A matriz 10x10 do tabuleiro.
 */
void inicializar_tabuleiro_habilidade(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO]) {
    for (int i = 0; i < TAMANHO_AVENTUREIRO; i++) {
        for (int j = 0; j < TAMANHO_AVENTUREIRO; j++) {
            tabuleiro[i][j] = NAO_AFETADA_HABILIDADE;
        }
    }
}

/**
 * @brief Aplica uma habilidade em forma de cone no tabuleiro.
 * O cone se expande para "baixo" (aumento do índice da linha) a partir do ponto de origem (vértice).
 * A largura do cone aumenta em 1 para cada lado a cada linha de profundidade.
 * Ex: profundidade 1 -> 1 célula; profundidade 2 -> 3 células na base; profundidade 3 -> 5 células na base.
 * 
 * @param tabuleiro O tabuleiro 10x10.
 * @param origem_linha Linha do vértice superior do cone.
 * @param origem_coluna Coluna do vértice superior do cone.
 * @param profundidade Número de linhas que o cone ocupa (altura do cone).
 */
void aplicar_habilidade_cone(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO], int origem_linha, int origem_coluna, int profundidade) {
    // printf("Aplicando Habilidade Cone em [%d][%d] com profundidade %d\n", origem_linha, origem_coluna, profundidade);
    for (int i = 0; i < profundidade; i++) { // i representa a linha atual do cone em relação à origem_linha
        for (int j = -i; j <= i; j++) { // j representa o deslocamento na coluna em relação à origem_coluna
            int r = origem_linha + i;
            int c = origem_coluna + j;
            if (r >= 0 && r < TAMANHO_AVENTUREIRO && c >= 0 && c < TAMANHO_AVENTUREIRO) {
                tabuleiro[r][c] = AFETADA_HABILIDADE;
            }
        }
    }
}

/**
 * @brief Aplica uma habilidade em forma de cruz no tabuleiro.
 * 
 * @param tabuleiro O tabuleiro 10x10.
 * @param centro_linha Linha do centro da cruz.
 * @param centro_coluna Coluna do centro da cruz.
 * @param braco_tamanho Comprimento de cada braço da cruz a partir do centro (o centro é incluído, então um braço de tamanho 0 é só o centro).
 */
void aplicar_habilidade_cruz(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO], int centro_linha, int centro_coluna, int braco_tamanho) {
    // printf("Aplicando Habilidade Cruz em [%d][%d] com braço de tamanho %d\n", centro_linha, centro_coluna, braco_tamanho);
    // Marca o centro e os braços
    for (int i = -braco_tamanho; i <= braco_tamanho; i++) {
        // Braço horizontal
        int rh = centro_linha;
        int ch = centro_coluna + i;
        if (rh >= 0 && rh < TAMANHO_AVENTUREIRO && ch >= 0 && ch < TAMANHO_AVENTUREIRO) {
            tabuleiro[rh][ch] = AFETADA_HABILIDADE;
        }
        // Braço vertical
        int rv = centro_linha + i;
        int cv = centro_coluna;
        if (rv >= 0 && rv < TAMANHO_AVENTUREIRO && cv >= 0 && cv < TAMANHO_AVENTUREIRO) {
            tabuleiro[rv][cv] = AFETADA_HABILIDADE;
        }
    }
}

/**
 * @brief Aplica uma habilidade em forma de octaedro (losango/diamante) no tabuleiro.
 * A forma é definida pela distância de Manhattan do centro.
 * 
 * @param tabuleiro O tabuleiro 10x10.
 * @param centro_linha Linha do centro do octaedro.
 * @param centro_coluna Coluna do centro do octaedro.
 * @param raio Distância máxima de Manhattan do centro para uma célula ser afetada.
 *             Um raio 0 afeta apenas o centro. Raio 1 afeta o centro e seus 4 vizinhos diretos.
 */
void aplicar_habilidade_octaedro(int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO], int centro_linha, int centro_coluna, int raio) {
    // printf("Aplicando Habilidade Octaedro em [%d][%d] com raio %d\n", centro_linha, centro_coluna, raio);
    for (int i = 0; i < TAMANHO_AVENTUREIRO; i++) {
        for (int j = 0; j < TAMANHO_AVENTUREIRO; j++) {
            int dist_linha = (i > centro_linha) ? (i - centro_linha) : (centro_linha - i); // abs(i - centro_linha)
            int dist_coluna = (j > centro_coluna) ? (j - centro_coluna) : (centro_coluna - j); // abs(j - centro_coluna)
            if (dist_linha + dist_coluna <= raio) {
                if (i >= 0 && i < TAMANHO_AVENTUREIRO && j >= 0 && j < TAMANHO_AVENTUREIRO) { // Dupla checagem, embora o loop já limite
                    tabuleiro[i][j] = AFETADA_HABILIDADE;
                }
            }
        }
    }
}

