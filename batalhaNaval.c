#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * ============================================================================
 * Desafio de Batalha Naval - Nível Avançado: Habilidades Especiais e Áreas de Efeito
 * ============================================================================
 * 
 * Este programa finaliza o jogo de Batalha Naval integrando:
 * 1. Um tabuleiro 10x10 preenchido com água (0).
 * 2. Posicionamento validado de 4 navios de tamanho 3 (horizontal, vertical e 2 diagonais).
 * 3. Geração dinâmica de matrizes 5x5 com áreas de efeito de habilidades especiais:
 *    - CONE: Origem no topo, expandindo para baixo.
 *    - CRUZ: Origem no centro, formato de cruz +.
 *    - OCTAEDRO (LOSANGO): Origem no centro, formato diamantado.
 * 4. Sobreposição das habilidades no tabuleiro com checagem de limites.
 * 5. Exibição organizada com cabeçalho de colunas (A a J), linhas (1 a 10) e legenda visual:
 *    - 0 : Água
 *    - 3 : Navio
 *    - 5 : Área Afetada por Habilidade Especial
 */

// Definições de constantes globais
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5
#define CENTRO_HABILIDADE 2

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

int main() {
    // =========================================================================
    // 1. INICIALIZAÇÃO DO TABULEIRO E NAVIOS
    // =========================================================================
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Preenche o tabuleiro com 0 (Água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Vetores unidimensionais dos navios
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAMANHO_NAVIO]   = {NAVIO, NAVIO, NAVIO};
    int navioDiagDesc[TAMANHO_NAVIO]   = {NAVIO, NAVIO, NAVIO};
    int navioDiagAsc[TAMANHO_NAVIO]    = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos 4 navios (0-based)
    int linhaH = 2, colunaH = 1; // Navio 1: Linha 3 (B a D)
    int linhaV = 5, colunaV = 6; // Navio 2: Coluna G (Linhas 6 a 8)
    int linhaD1 = 0, colunaD1 = 5; // Navio 3: Diagonal Descendente \ (1,F) a (3,H)
    int linhaD2 = 7, colunaD2 = 2; // Navio 4: Diagonal Anti-diagonal / (8,C) a (10,A)

    printf("=================================================================\n");
    printf("   BATALHA NAVAL - HABILIDADES ESPECIAIS E ÁREAS DE EFEITO       \n");
    printf("=================================================================\n\n");

    // Posicionamento dos Navios na Matriz
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagDesc[i];
        tabuleiro[linhaD2 + i][colunaD2 - i] = navioDiagAsc[i];
    }
    printf("[OK] 4 Navios (Horizontal, Vertical, Diagonal \\ e Diagonal /) posicionados.\n\n");

    // =========================================================================
    // 2. GERAÇÃO DINÂMICA DAS MATRIZES DE HABILIDADE (5x5) COM CONDICIONAIS
    // =========================================================================

    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Constrói matriz de Habilidade Cone
    // Ponto de origem no topo (0, CENTRO_HABILIDADE). Expande para baixo.
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i <= CENTRO_HABILIDADE && abs(j - CENTRO_HABILIDADE) <= i) {
                cone[i][j] = 1; // Área afetada
            } else {
                cone[i][j] = 0; // Área não afetada
            }
        }
    }

    // Constrói matriz de Habilidade Cruz
    // Ponto de origem no centro (CENTRO_HABILIDADE, CENTRO_HABILIDADE).
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == CENTRO_HABILIDADE || j == CENTRO_HABILIDADE) {
                cruz[i][j] = 1; // Área afetada
            } else {
                cruz[i][j] = 0; // Área não afetada
            }
        }
    }

    // Constrói matriz de Habilidade Octaedro (Losango)
    // Ponto de origem no centro (CENTRO_HABILIDADE, CENTRO_HABILIDADE).
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - CENTRO_HABILIDADE) + abs(j - CENTRO_HABILIDADE) <= 1) {
                octaedro[i][j] = 1; // Área afetada
            } else {
                octaedro[i][j] = 0; // Área não afetada
            }
        }
    }

    // Exibição isolada dos padrões das habilidades
    printf("--- PADRÕES DAS MATRIZES DE HABILIDADE (5x5) ---\n\n");

    printf("Habilidade CONE:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Habilidade CRUZ:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Habilidade OCTAEDRO:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // =========================================================================
    // 3. INTEGRAÇÃO E SOBREPOSIÇÃO DAS HABILIDADES NO TABULEIRO
    // =========================================================================

    // Pontos de origem das habilidades no tabuleiro 10x10 (0-based)
    int origemConeL = 0, origemConeC = 4;   // Origem do Cone: Linha 1, Coluna E
    int origemCruzL = 4, origemCruzC = 2;   // Origem da Cruz: Linha 5, Coluna C
    int origemOctL  = 7, origemOctC  = 7;   // Origem do Octaedro: Linha 8, Coluna H

    // Aplicação da Habilidade CONE no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cone[i][j] == 1) {
                int tabL = origemConeL + i;
                int tabC = origemConeC + (j - CENTRO_HABILIDADE);
                // Valida os limites do tabuleiro antes de aplicar a habilidade
                if (tabL >= 0 && tabL < TAMANHO_TABULEIRO && tabC >= 0 && tabC < TAMANHO_TABULEIRO) {
                    tabuleiro[tabL][tabC] = HABILIDADE;
                }
            }
        }
    }

    // Aplicação da Habilidade CRUZ no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cruz[i][j] == 1) {
                int tabL = origemCruzL + (i - CENTRO_HABILIDADE);
                int tabC = origemCruzC + (j - CENTRO_HABILIDADE);
                // Valida os limites do tabuleiro antes de aplicar a habilidade
                if (tabL >= 0 && tabL < TAMANHO_TABULEIRO && tabC >= 0 && tabC < TAMANHO_TABULEIRO) {
                    tabuleiro[tabL][tabC] = HABILIDADE;
                }
            }
        }
    }

    // Aplicação da Habilidade OCTAEDRO no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (octaedro[i][j] == 1) {
                int tabL = origemOctL + (i - CENTRO_HABILIDADE);
                int tabC = origemOctC + (j - CENTRO_HABILIDADE);
                // Valida os limites do tabuleiro antes de aplicar a habilidade
                if (tabL >= 0 && tabL < TAMANHO_TABULEIRO && tabC >= 0 && tabC < TAMANHO_TABULEIRO) {
                    tabuleiro[tabL][tabC] = HABILIDADE;
                }
            }
        }
    }

    // =========================================================================
    // 4. EXIBIÇÃO FORMATADA DO TABULEIRO FINAL
    // =========================================================================
    printf("--- TABULEIRO COM NAVIOS E ÁREAS DE EFEITO (10x10) ---\n\n");

    // Imprime cabeçalho das colunas (A a J)
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

    // Imprime linhas do tabuleiro com os valores (0 = Água, 3 = Navio, 5 = Habilidade)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d | ", i + 1); // Exibe número da linha de 1 a 10
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Legenda explicativa
    printf("\nLegenda:\n");
    printf("  0 : Água\n");
    printf("  3 : Parte de Navio\n");
    printf("  5 : Área Afetada por Habilidade Especial\n\n");

    return 0;
}
