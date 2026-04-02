#include <stdio.h>
#include <stdlib.h>
int main()
{
int x, n;
scanf("%d %d", &x, &n);

int melhor_distancia_geral = 99999999, canal_vencedor = 0, minuto_vencedor = 0, termo_vencedor = 0, melhor_termo, melhor_minuto;

    for (int canal = 1; canal <= n; canal++) {
        int f1, f2, i = 2;
        scanf("%d %d", &f1, &f2);
    
    while (x >= f2)
    {
    int f3 = f1 + f2;
    i++;
    f3 = f1 + f2;
    f1 = f2;
    f2 = f3;
    }
        if (abs(f2 - x) < abs (f1 - x)){
        melhor_termo = f2;
        melhor_minuto = i;
        }else{
        melhor_termo = f1;
        melhor_minuto = i - 1;
        }

        if (abs(melhor_termo - x) <= melhor_distancia_geral){
        melhor_distancia_geral = abs(melhor_termo - x);
        termo_vencedor = melhor_termo;
        minuto_vencedor = melhor_minuto;
        canal_vencedor = canal;
        }

}

        int temp = termo_vencedor, soma = 0;
        
        while (temp != 0)
        {
        soma = soma + (temp % 10);
        temp = temp / 10;
        }

        if (soma > 10)
        {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %i e sera chamado mais ou menos no minuto %i e com o VIP garantido!!!\n", canal_vencedor, minuto_vencedor);
        }
        else
        {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %i e sera chamado mais ou menos no minuto %i, mas o ingresso VIP não vai rolar :(\n", canal_vencedor ,minuto_vencedor );
        }
        
        
        
return 0;
}  

