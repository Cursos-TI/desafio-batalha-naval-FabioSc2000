#include <stdio.h>
#include <stdbool.h>

/**
 * ============================================================================
 * Desafio de Batalha Naval - Nível Novato: Posicionando Navios no Tabuleiro
 * ============================================================================
 * 
 */

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // =========================================================================
    // 1. INICIALIZAÇÃO DO TABULEIRO E DOS NAVIOS
    // =========================================================================

    // Declaração da matriz 10x10 que representa o tabuleiro de Batalha Naval
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Preenchimento inicial do tabuleiro com 0 (Água) usando loops aninhados
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Declaração e inicialização dos vetores unidimensionais dos navios (tamanho 3, preenchidos com 3)
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // =========================================================================
    // 2. DEFINIÇÃO DAS COORDENADAS INICIAIS DOS NAVIOS
    // =========================================================================
    
    // Navio 1 (Horizontal): Linha 2, Coluna 1 -> ocupará (2,1), (2,2), (2,3)
    int linhaNavioH = 2;
    int colunaNavioH = 1;

    // Navio 2 (Vertical): Linha 5, Coluna 6 -> ocupará (5,6), (6,6), (7,6)
    int linhaNavioV = 5;
    int colunaNavioV = 6;

    printf("=========================================\n");
    printf("   BATALHA NAVAL - POSICIONANDO NAVIOS   \n");
    printf("=========================================\n\n");

    // =========================================================================
    // 3. VALIDAÇÃO E POSICIONAMENTO DO NAVIO HORIZONTAL
    // =========================================================================

    // Valida se o navio horizontal cabe dentro dos limites do tabuleiro
    bool limiteValidoH = (linhaNavioH >= 0 && linhaNavioH < TAMANHO_TABULEIRO) &&
                         (colunaNavioH >= 0 && (colunaNavioH + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO);

    if (!limiteValidoH) {
        printf("[ERRO] Navio horizontal excede os limites do tabuleiro!\n");
        return 1;
    }

    // Posiciona o navio horizontal copiando os valores do vetor para a matriz do tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioH][colunaNavioH + i] = navioHorizontal[i];
    }
    printf("[OK] Navio Horizontal posicionado com sucesso na Linha %d (Colunas %c a %c).\n",
           linhaNavioH + 1, 'A' + colunaNavioH, 'A' + colunaNavioH + TAMANHO_NAVIO - 1);

    // =========================================================================
    // 4. VALIDAÇÃO E POSICIONAMENTO DO NAVIO VERTICAL
    // =========================================================================

    // Valida se o navio vertical cabe dentro dos limites do tabuleiro
    bool limiteValidoV = (colunaNavioV >= 0 && colunaNavioV < TAMANHO_TABULEIRO) &&
                         (linhaNavioV >= 0 && (linhaNavioV + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO);

    if (!limiteValidoV) {
        printf("[ERRO] Navio vertical excede os limites do tabuleiro!\n");
        return 1;
    }

    // Valida se há sobreposição com algum navio já posicionado no tabuleiro
    bool sobreposicao = false;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaNavioV + i][colunaNavioV] != AGUA) {
            sobreposicao = true;
            break;
        }
    }

    if (sobreposicao) {
        printf("[ERRO] Navio vertical se sobrepõe a outro navio existente!\n");
        return 1;
    }

    // Posiciona o navio vertical copiando os valores do vetor para a matriz do tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioV + i][colunaNavioV] = navioVertical[i];
    }
    printf("[OK] Navio Vertical posicionado com sucesso na Coluna %c (Linhas %d a %d).\n\n",
           'A' + colunaNavioV, linhaNavioV + 1, linhaNavioV + TAMANHO_NAVIO);

    // =========================================================================
    // 5. EXIBIÇÃO FORMATADA DO TABULEIRO
    // =========================================================================

    printf("--- TABULEIRO DE BATALHA NAVAL (10x10) ---\n\n");

    // Imprime as letras das colunas na parte superior (A até J)
    printf("    ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("--");
    }
    printf("-\n");

    // Imprime cada linha do tabuleiro com seu respectivo índice numérico (1 a 10)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d | ", i + 1); // Índice da linha exibido de 1 a 10
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Elemento da matriz seguido de espaço separador
        }
        printf("\n");
    }

    // Exibição da legenda
    printf("\nLegenda:\n");
    printf("  0 : Água\n");
    printf("  3 : Parte de Navio\n\n");

    return 0;
}
