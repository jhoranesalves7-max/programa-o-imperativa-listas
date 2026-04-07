#include <stdio.h>

#define LINHAS 4
#define COLUNAS 4
#define MOVIMENTOS 20

void inicializarMatriz(int matriz[LINHAS][COLUNAS]) {
    int i, j;
    for (i = 0; i < LINHAS; i++)
        for (j = 0; j < COLUNAS; j++)
            matriz[i][j] = 0;
}

void imprimirMatriz(int matriz[LINHAS][COLUNAS]) {
    int i, j;
    printf("Mapa de visitas de Pedro:\n");
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("[%2d] ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mover(char direcao, int *linha, int *coluna) {
    int novaLinha = *linha;
    int novaColuna = *coluna;

    if (direcao == 'c') novaLinha--;       
    else if (direcao == 'b') novaLinha++; 
    else if (direcao == 'e') novaColuna--; 
    else if (direcao == 'd') novaColuna++; 

    if (novaLinha >= 0 && novaLinha < LINHAS &&
        novaColuna >= 0 && novaColuna < COLUNAS) {
        *linha = novaLinha;
        *coluna = novaColuna;
    }
}

void registrarCaminho(char movimentos[MOVIMENTOS], int matriz[LINHAS][COLUNAS]) {
    int linha = 0, coluna = 0;
    int i;


    matriz[linha][coluna]++;

    for (i = 0; i < MOVIMENTOS; i++) {
        mover(movimentos[i], &linha, &coluna);
        matriz[linha][coluna]++;
    }
}


void encontrarMaisVisitado(int matriz[LINHAS][COLUNAS], int *maxLinha, int *maxColuna) {
    int i, j;
    int maxVisitas = -1;

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            if (matriz[i][j] > maxVisitas) {
                maxVisitas = matriz[i][j];
                *maxLinha = i;
                *maxColuna = j;
            }
        }
    }
}

int main() {
    char movimentos[MOVIMENTOS];
    int matriz[LINHAS][COLUNAS];
    int maxLinha, maxColuna;
    int i;


    for (i = 0; i < MOVIMENTOS; i++) {
        scanf(" %c", &movimentos[i]);
    }

    inicializarMatriz(matriz);
    registrarCaminho(movimentos, matriz);
    imprimirMatriz(matriz);
    encontrarMaisVisitado(matriz, &maxLinha, &maxColuna);

    /* X representa a coluna, Y representa a linha */
    printf("Coordenada X:%d, Y:%d\n", maxColuna, maxLinha);

    return 0;
}