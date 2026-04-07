#include <stdio.h>

int valor_linha, valor_coluna;
char matriz_parede[100][101];

void cair(int linha, int coluna) {
    while(linha < valor_linha - 1 && matriz_parede[linha + 1][coluna] == '.') {
        matriz_parede[linha][coluna] = 'o';
        linha++;
    }
    //realiza a escorregada para a esquerda, quando acha a prateleira
    int col_esq = coluna;
    while (col_esq >= 0 && matriz_parede[linha + 1][col_esq] == '#')
    {
        matriz_parede[linha][col_esq] = 'o';
        col_esq--;
    }
    
        //realiza a escorregada para a direita, quando acha a prateleira
        int coluna_direita = coluna;
        while (coluna_direita < valor_coluna && matriz_parede[linha + 1][coluna_direita] == '#')
        {
            matriz_parede[linha][coluna_direita] = 'o';
            coluna_direita++;
        }
        matriz_parede[linha][coluna_direita] = 'o';
        matriz_parede[linha][col_esq] = 'o';
        if (linha + 1 < valor_linha) {
            cair(linha + 1, col_esq);
            cair(linha + 1, coluna_direita);
        }
}


int main()
{

    //recebe o valor da linha e coluna
    if (scanf("%d %d", &valor_linha, &valor_coluna) != 2) return 0;

    //verifica se ambos são maiores que 3
    if (valor_linha < 3 || valor_coluna <3){
        return 0;
    }
    
    //recebe os inputs da matriz
    for (int i = 0; i < valor_linha; i++)
    {
        scanf(" %s", matriz_parede[i]);
    }
    
    int linha_da_gota = -1;
    int coluna_da_gota = -1;

    //procura a primeira gota e marca a posição dela. linha e coluna
    for (int i = 0; i < valor_linha; i++)
    {
        for(int j = 0; j < valor_coluna; j++)
        {
        if (matriz_parede[i][j] == 'o')
        {
            linha_da_gota = i;
            coluna_da_gota = j;

        }
        }
    }

    cair(linha_da_gota, coluna_da_gota);

    for (int i = 0; i < valor_linha; i++)
    {
        for (int j = 0; j < valor_coluna; j++)
        {
            printf("%c", matriz_parede[i][j]);
        }
        printf("\n");
    } 


    return 0;
}