#include <stdio.h>

int main() {
    int N, X, Y;
    scanf("%d %d %d", &N, &X, &Y);

    int latas[N + 1];
    for (int i = 0; i <= N; i++) latas[i] = 0;

    for (int i = 0; i < Y; i++) {
        int hh, mm, qtd, cliente;
        scanf(" %d:%d %d", &hh, &mm, &qtd);
        cliente = (hh * 60 + mm - 420) / 3;
        if (cliente >= 1 && cliente <= N)
            latas[cliente] = qtd;
    }

    int total = 0;
    for (int i = 1; i <= N; i++) {
        
        if (latas[i] == 0 && X != 0 && i % X == 0)
            latas[i] = 1;

        total += latas[i];

        if (total >= 50) {
            int min = 420 + i * 3;

            printf("Quem levou a cesta basica foi o %d* cliente atendido por "
                "coragem, as %02d:%02d. Que comprou %d lata%s.\n",
                i, min / 60, min % 60, latas[i],
                latas[i] != 1 ? "s" : "");  
            return 0;
        }
    }

    int faltam = 50 - total;
    if (faltam == 1) {
        printf("Ainda nao foram vendidas latas suficientes. Falta 1 lata.\n");
    } else {
        printf("Ainda nao foram vendidas latas suficientes. Faltam %d latas.\n", faltam);
    }
    
    return 0;
}