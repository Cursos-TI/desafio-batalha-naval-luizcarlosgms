#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHAS 10// Definindo o número de linhas do tabuleiro
#define COLUNAS 10// Definindo o número de colunas do tabuleiro

// Funções para aplicar habilidades especiais no tabuleiro
void aplicarCone(int habilidades[LINHAS][COLUNAS], int centroX, int centroY) {
    for (int i = 0; i < 3; i++) { // altura do cone
        for (int j = -i; j <= i; j++) {
            int x = centroX + i;
            int y = centroY + j;
            if (x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS)
                habilidades[x][y] = 4; // 4 representa a área atingida pelo cone
        }
    }
}
void aplicarOctaedro(int habilidades[LINHAS][COLUNAS], int centroX, int centroY) {
    for (int dx = -2; dx <= 2; dx++) {
        for (int dy = -2; dy <= 2; dy++) {
            if (abs(dx) + abs(dy) <= 2) {
                int x = centroX + dx;
                int y = centroY + dy;
                if (x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS)
                    habilidades[x][y] = 5; // 5 representa a área atingida pelo octaedro
            }
        }
    }
}

void aplicarCruz(int habilidades[LINHAS][COLUNAS], int centroX, int centroY) {
    for (int i = -2; i <= 2; i++) {
        if (centroX + i >= 0 && centroX + i < LINHAS)
            habilidades[centroX + i][centroY] = 6; // 6 representa a área atingida pela cruz
        if (centroY + i >= 0 && centroY + i < COLUNAS)
            habilidades[centroX][centroY + i] = 6; // 6 representa a área atingida pela cruz
    }
}

void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    printf("Tabuleiro Batalha Naval:\n");
    printf("  "); // Espaço para alinhar as colunas
    // Exibe as colunas numeradas de A a J
    for (char letra = 'A'; letra < 'A' + COLUNAS; letra++) {
        printf(" %c", letra); // Exibe as colunas A, B, C, D, E, F, G, H, I, J
    }
    printf("\n");
    // Exibe o tabuleiro com as linhas numeradas
    for(int i = 0; i < LINHAS; i++){
        printf("%2d ", i + 1); // Exibe as linhas numeradas de 1 a 10
        for(int j = 0; j < COLUNAS; j++){
            printf("%d ", tabuleiro[i][j]); // Exibe o valor da célula do tabuleiro
        }
        printf("\n");
    }
}

void exibirHabilidade(int habilidades[LINHAS][COLUNAS]) {
    printf("\n Áreas Atingidas por Habilidades: \n");
    printf("  "); // Espaço para alinhar as colunas
    for (char letra = 'A'; letra < 'A' + COLUNAS; letra++) {
        printf(" %c", letra); // Exibe as colunas A, B, C, D, E, F, G, H, I, J
    }
    printf("\n");
    {
        for(int i = 0; i < LINHAS; i++){
            printf("%2d ", i + 1); // Exibe as linhas numeradas de 1 a 10
            for(int j = 0; j < COLUNAS; j++){
                printf("%d ", habilidades[i][j]); // Exibe o valor da célula do tabuleiro
            }
            printf("\n");
        }
    }
    
}
int main() {

    // Nível Novato - Posicionamento dos Navios
    
    int tabuleiro[LINHAS][COLUNAS]; // Matriz para representar o tabuleiro de 10x10
    int habilidades[LINHAS][COLUNAS]; // Matriz para representar as áreas afetadas pelas habilidades especiais

    // Inicializando o tabuleiro com 0 (vazio)
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            tabuleiro[i][j] = 0;
            habilidades[i][j] = 0; // Inicializando a matriz de habilidades com 0 (não afetado)
        }
    }

    // Posicionando navios no tabuleiro
    // Posicionando navio horizontalmente na linha 2, colunas 1 a 3
    for(int j = 1; j <= 3; j++){
        tabuleiro[2][j] = 1; // 1 = representa parte do navio
    }   
    // Posicionando navio verticalmente na coluna 4, linhas 0 a 2
    for(int i = 0; i <= 2; i++){
        tabuleiro[i][5] = 2; // 2 = representa parte do navio
    }


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    //Posicionnando navios na diagonal
    for(int i = 0; i < 3; i++){
        tabuleiro[i][i + 6] = 3; // Posiciona navio diagonalmente da posição (0,6) até (2,8)
    }
    for(int i = 0; i < 3; i++){
        tabuleiro[i + 6][i] = 3; // Posiciona navio diagonalmente da posição (6,0) até (8,2)
    }


    // Nível Mestre - Habilidades Especiais com Matrizes(Cone, Octaedro e Cruz)
   
    // Aplicando habilidades especiais
    aplicarCone(habilidades, 1,2); // Aplicando habilidade em cone na posição (1,2)
    aplicarOctaedro(habilidades, 5,5); // Aplicando habilidade em octaedro na posição (5,5)
    aplicarCruz(habilidades, 8,8); // Aplicando habilidade em cruz na posição (8,8)


    // Exibindo o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    exibirHabilidade(habilidades);

    return 0;
}
