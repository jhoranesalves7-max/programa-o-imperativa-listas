#include <stdio.h>

int main()
{
    int T, N;
    int vetor[100];
    scanf("%i", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%i", &N);
            for (int j = 0; j < N; j++)
            {
                scanf("%i", &vetor[j]);
            }
            int tamanho_atual = 1,
                tamanho_maior = 1,
                inicio_atual = 0,
                melhor_inicio = 0;
                    for (int i = 1; i < N; i++)
                    {
                        if(vetor[i] < vetor[i-1]){
                            tamanho_atual++;
                            if(tamanho_atual > tamanho_maior){
                                tamanho_maior = tamanho_atual;
                                melhor_inicio = inicio_atual;
                            }
                        }
                        else{
                            inicio_atual = i;
                            tamanho_atual = 1;
                        }
                    }
        if(tamanho_maior == 1)
        printf("0");
        else{
            printf("%d\n", tamanho_maior);
            for(int k = melhor_inicio; k < melhor_inicio + tamanho_maior; k++){
                printf("%d ", vetor[k]);
                    }
            }
                    printf("\n");
            
    }
    

}