#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[5][5]; // Matriz para representar o tabuleiro de 5x5

    // Inicializando o tabuleiro com 0 (vazio)
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            tabuleiro[i][j] = 0;
        }
    }
    // Posicionando navio horizontalmente na linha 2, colunas 1 a 3
    for(int j = 1; j <= 3; j++){
        tabuleiro[2][j] = 1; // 1 representa parte do navio
    }   
    // Posicionando navio verticalmente na coluna 4, linhas 0 a 2
    for(int i = 0; i <= 2; i++){
        tabuleiro[i][4] = 1; // 1 representa parte do navio
    }
    // Exibindo o tabuleiro com os navios posicionados
    printf("Tabuleiro:\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", tabuleiro[i][j]); // Exibe 0 para vazio e 1 para parte do navio
        }
        printf("\n");
    }
    
    
    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
