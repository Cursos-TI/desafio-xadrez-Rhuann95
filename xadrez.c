#include <stdio.h>

// Função para exibir o tabuleiro
void mostrarTabuleiro(int linhas, int colunas, int tabuleiro[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ===============================
// Nível Mestre - Funções Recursivas
// ===============================

// Movimento recursivo do Bispo (diagonal ↘)
void movimentoBispoRec(int tabuleiro[8][8], int i, int j) {
    if (i >= 8 || j >= 8) return;
    tabuleiro[i][j] = 1;
    movimentoBispoRec(tabuleiro, i+1, j+1);
}

// Movimento recursivo da Torre (para direita)
void movimentoTorreRec(int tabuleiro[8][8], int i, int j) {
    if (j >= 8) return;
    tabuleiro[i][j] = 1;
    movimentoTorreRec(tabuleiro, i, j+1);
}

// Movimento recursivo da Rainha (para esquerda)
void movimentoRainhaRec(int tabuleiro[8][8], int i, int j) {
    if (j < 0) return;
    tabuleiro[i][j] = 1;
    movimentoRainhaRec(tabuleiro, i, j-1);
}

int main() {
    // ===============================
    // Nível Novato - Movimentação simples
    // ===============================
    int tabuleiro[8][8] = {0};

    printf("=== Nível Novato ===\n");

    // Movimento do Bispo (diagonal)
    for (int i = 0, j = 0; i < 8 && j < 8; i++, j++) {
        tabuleiro[i][j] = 1;
    }
    printf("Bispo (diagonal ↘):\n");
    mostrarTabuleiro(8, 8, tabuleiro);

    // Zera tabuleiro
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) tabuleiro[i][j] = 0;

    // Movimento da Torre (para direita)
    for (int j = 0; j < 8; j++) {
        tabuleiro[3][j] = 1;
    }
    printf("Torre (linha 3 → direita):\n");
    mostrarTabuleiro(8, 8, tabuleiro);

    // Zera tabuleiro
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) tabuleiro[i][j] = 0;

    // Movimento da Rainha (para esquerda)
    for (int j = 7; j >= 0; j--) {
        tabuleiro[4][j] = 1;
    }
    printf("Rainha (linha 4 ← esquerda):\n");
    mostrarTabuleiro(8, 8, tabuleiro);

    // ===============================
    // Nível Aventureiro - Cavalo
    // ===============================
    printf("=== Nível Aventureiro ===\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    int x = 4, y = 4; // posição inicial do cavalo
    int movimentos[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    for (int k = 0; k < 8; k++) {
        int nx = x + movimentos[k][0];
        int ny = y + movimentos[k][1];
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
            tabuleiro[nx][ny] = 1;
        }
    }
    printf("Cavalo (posições possíveis a partir de [4,4]):\n");
    mostrarTabuleiro(8, 8, tabuleiro);

    // ===============================
    // Nível Mestre - Recursividade
    // ===============================
    printf("=== Nível Mestre ===\n");

    // Bispo recursivo
    int tabBispo[8][8] = {0};
    movimentoBispoRec(tabBispo, 0, 0);
    printf("Bispo (recursivo):\n");
    mostrarTabuleiro(8, 8, tabBispo);

    // Torre recursiva
    int tabTorre[8][8] = {0};
    movimentoTorreRec(tabTorre, 3, 0);
    printf("Torre (recursiva):\n");
    mostrarTabuleiro(8, 8, tabTorre);

    // Rainha recursiva
    int tabRainha[8][8] = {0};
    movimentoRainhaRec(tabRainha, 4, 7);
    printf("Rainha (recursiva):\n");
    mostrarTabuleiro(8, 8, tabRainha);

    return 0;
}

