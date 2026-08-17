#include <stdio.h>
#include <stdbool.h>

/**
 * ============================================================================
 * Desafio de Batalha Naval - Nível Intermediário: Navios Diagonais
 * ============================================================================
 */

// Definição de constantes globais
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define QTD_NAVIOS 4
#define AGUA 0
#define NAVIO 3

int main() {
    // =========================================================================
    // 1. INICIALIZAÇÃO DO TABULEIRO E DOS VETORES DOS NAVIOS
    // =========================================================================

    // Declaração da matriz 10x10 que representa o tabuleiro do Batalha Naval
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Preenchimento inicial do tabuleiro com 0 (Água) usando loops aninhados
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Declaração e inicialização dos vetores unidimensionais dos 4 navios (tamanho 3, preenchidos com 3)
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAMANHO_NAVIO]   = {NAVIO, NAVIO, NAVIO};
    int navioDiagDesc[TAMANHO_NAVIO]   = {NAVIO, NAVIO, NAVIO};
    int navioDiagAsc[TAMANHO_NAVIO]    = {NAVIO, NAVIO, NAVIO};

    // =========================================================================
    // 2. DEFINIÇÃO DAS COORDENADAS INICIAIS DOS 4 NAVIOS (ÍNDICES 0-BASED)
    // =========================================================================

    // Navio 1 (Horizontal): Linha 3 (índice 2), Coluna B (índice 1) -> (2,1), (2,2), (2,3)
    int linhaH = 2, colunaH = 1;

    // Navio 2 (Vertical): Linha 6 (índice 5), Coluna G (índice 6) -> (5,6), (6,6), (7,6)
    int linhaV = 5, colunaV = 6;

    // Navio 3 (Diagonal Descendente \): Linha 1 (índice 0), Coluna F (índice 5) -> (0,5), (1,6), (2,7)
    int linhaD1 = 0, colunaD1 = 5;

    // Navio 4 (Diagonal Anti-diagonal /): Linha 8 (índice 7), Coluna C (índice 2) -> (7,2), (8,1), (9,0)
    int linhaD2 = 7, colunaD2 = 2;

    printf("=====================================================\n");
    printf("   BATALHA NAVAL - TABULEIRO COMPLETO E DIAGONAIS   \n");
    printf("=====================================================\n\n");

    // =========================================================================
    // 3. POSICIONAMENTO DO NAVIO 1 (HORIZONTAL)
    // =========================================================================
    bool limiteValidoH = (linhaH >= 0 && linhaH < TAMANHO_TABULEIRO) &&
                         (colunaH >= 0 && (colunaH + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO);

    if (!limiteValidoH) {
        printf("[ERRO] Navio horizontal excede os limites do tabuleiro!\n");
        return 1;
    }

    bool sobreposicaoH = false;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] != AGUA) {
            sobreposicaoH = true;
            break;
        }
    }

    if (sobreposicaoH) {
        printf("[ERRO] Navio horizontal se sobrepõe a outro navio!\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }
    printf("[OK] Navio 1 (Horizontal) posicionado na Linha %d (Colunas %c a %c).\n",
           linhaH + 1, 'A' + colunaH, 'A' + colunaH + TAMANHO_NAVIO - 1);

    // =========================================================================
    // 4. POSICIONAMENTO DO NAVIO 2 (VERTICAL)
    // =========================================================================
    bool limiteValidoV = (colunaV >= 0 && colunaV < TAMANHO_TABULEIRO) &&
                         (linhaV >= 0 && (linhaV + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO);

    if (!limiteValidoV) {
        printf("[ERRO] Navio vertical excede os limites do tabuleiro!\n");
        return 1;
    }

    bool sobreposicaoV = false;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] != AGUA) {
            sobreposicaoV = true;
            break;
        }
    }

    if (sobreposicaoV) {
        printf("[ERRO] Navio vertical se sobrepõe a outro navio!\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }
    printf("[OK] Navio 2 (Vertical) posicionado na Coluna %c (Linhas %d a %d).\n",
           'A' + colunaV, linhaV + 1, linhaV + TAMANHO_NAVIO);

    // =========================================================================
    // 5. POSICIONAMENTO DO NAVIO 3 (DIAGONAL DESCENDENTE \)
    // Regra: Linha e coluna aumentam simultaneamente (linha + i, coluna + i)
    // =========================================================================
    bool limiteValidoD1 = (linhaD1 >= 0 && (linhaD1 + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO) &&
                          (colunaD1 >= 0 && (colunaD1 + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO);

    if (!limiteValidoD1) {
        printf("[ERRO] Navio diagonal descendente excede os limites do tabuleiro!\n");
        return 1;
    }

    bool sobreposicaoD1 = false;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA) {
            sobreposicaoD1 = true;
            break;
        }
    }

    if (sobreposicaoD1) {
        printf("[ERRO] Navio diagonal descendente se sobrepõe a outro navio!\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagDesc[i];
    }
    printf("[OK] Navio 3 (Diagonal \\) posicionado de (%d,%c) até (%d,%c).\n",
           linhaD1 + 1, 'A' + colunaD1, linhaD1 + TAMANHO_NAVIO, 'A' + colunaD1 + TAMANHO_NAVIO - 1);

    // =========================================================================
    // 6. POSICIONAMENTO DO NAVIO 4 (DIAGONAL ANTI-DIAGONAL /)
    // Regra: Linha aumenta e coluna diminui (linha + i, coluna - i)
    // =========================================================================
    bool limiteValidoD2 = (linhaD2 >= 0 && (linhaD2 + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO) &&
                          (colunaD2 - (TAMANHO_NAVIO - 1) >= 0 && colunaD2 < TAMANHO_TABULEIRO);

    if (!limiteValidoD2) {
        printf("[ERRO] Navio diagonal anti-diagonal excede os limites do tabuleiro!\n");
        return 1;
    }

    bool sobreposicaoD2 = false;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaD2 + i][colunaD2 - i] != AGUA) {
            sobreposicaoD2 = true;
            break;
        }
    }

    if (sobreposicaoD2) {
        printf("[ERRO] Navio diagonal anti-diagonal se sobrepõe a outro navio!\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = navioDiagAsc[i];
    }
    printf("[OK] Navio 4 (Diagonal /) posicionado de (%d,%c) até (%d,%c).\n\n",
           linhaD2 + 1, 'A' + colunaD2, linhaD2 + TAMANHO_NAVIO, 'A' + colunaD2 - (TAMANHO_NAVIO - 1));

    // =========================================================================
    // 7. EXIBIÇÃO FORMATADA DO TABULEIRO COMPLETO (10x10)
    // =========================================================================
    printf("--- TABULEIRO DE BATALHA NAVAL (10x10) ---\n\n");

    // Imprime o cabeçalho com as letras das colunas (A a J)
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

    // Imprime cada linha do tabuleiro numerada de 1 a 10 com a matriz
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d | ", i + 1); // Exibe número da linha (1 a 10)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe elemento da matriz
        }
        printf("\n");
    }

    // Exibição da legenda do tabuleiro
    printf("\nLegenda:\n");
    printf("  0 : Água\n");
    printf("  3 : Parte de Navio\n\n");

    return 0;
}
