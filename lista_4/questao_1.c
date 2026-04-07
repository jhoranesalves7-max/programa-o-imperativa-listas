#include <stdio.h>

int main()
{
    int valor_linha, valor_coluna, linha, coluna;

    //verifica se teve duas entradas
    if(scanf("%d %d", &valor_linha, &valor_coluna) != 2) return 0;

    //verifica se (1 <= m, n <= 100)
    if (valor_linha < 1 || valor_linha > 100 || valor_coluna < 1 || valor_coluna > 100) return 0;

    char vetor[valor_linha][valor_coluna];
    char original[valor_linha][valor_coluna];

    //forma o vetor com os inputs 
    for(linha = 0; linha < valor_linha; linha++)
    {
        for (coluna = 0; coluna < valor_coluna; coluna++)
        {
            scanf(" %c", &vetor[linha][coluna]);
            original[linha][coluna] = vetor[linha][coluna];
        }
        
    }

    //aqui procura a letra p dentro do vetor
    for(int i = 0; i < valor_linha; i++)
    {
        for (int j = 0; j < valor_coluna; j++)
        {
            if(original[i][j] == 'P')
            {
                int p_linha = i;
                int p_coluna = j;

                //cima
                if(p_linha > 0 && (vetor[p_linha - 1][p_coluna] == '-' || vetor[p_linha - 1][p_coluna] == 'x'))
                    vetor[p_linha - 1][p_coluna] = '+';

                //baixo
                if(p_linha < valor_linha - 1 && (vetor[p_linha + 1][p_coluna] == '-' || vetor[p_linha + 1][p_coluna] == 'x'))
                    vetor[p_linha + 1][p_coluna] = '+';
                
                //esquerda
                if(p_coluna > 0 && (vetor[p_linha][p_coluna - 1] == '-' || vetor[p_linha][p_coluna - 1] == 'x'))
                    vetor[p_linha][p_coluna - 1] = '+';

                //direita
                if(p_coluna < valor_coluna - 1 && (vetor[p_linha][p_coluna + 1] == '-' || vetor[p_linha][p_coluna + 1] == 'x'))
                    vetor[p_linha][p_coluna + 1] = '+';

                //diagonal superior esquerda
                if(p_linha > 0 && p_coluna > 0 && vetor[p_linha - 1][p_coluna - 1] == '-')
                    vetor[p_linha - 1][p_coluna - 1] = 'x';

                //diagonal superior direita
                if(p_linha > 0 && p_coluna < valor_coluna - 1 && vetor[p_linha - 1][p_coluna + 1] == '-')
                    vetor[p_linha - 1][p_coluna + 1] = 'x';

                //diagonal inferior esquerda
                if(p_linha < valor_linha - 1 && p_coluna > 0 && vetor[p_linha + 1][p_coluna - 1] == '-')
                    vetor[p_linha + 1][p_coluna - 1] = 'x';

                //diagonal inferior direita
                if(p_linha < valor_linha - 1 && p_coluna < valor_coluna - 1 && vetor[p_linha + 1][p_coluna + 1] == '-')
                    vetor[p_linha + 1][p_coluna + 1] = 'x';
            }  
        }
    }

    //esse for é pra printar o final
    for ( linha = 0; linha < valor_linha; linha++)
    {
        for(coluna = 0; coluna < valor_coluna; coluna++)
        {
            printf("%c", vetor[linha][coluna]);
        }
        printf("\n");
    } 
    
    return 0;
}

//realizei minha lógica por etapas, primeiro pensei em formar o vetor, em seguida fazer as alterações, quando fosse para os valores, a direita, a esquerda...
//e nas diagonais, usei i.a para aprender o assunto e tirar duvidas durante o processo de criação do código