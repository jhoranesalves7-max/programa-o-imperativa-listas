#include <stdio.h>

int main() {
    int q;
    scanf("%d", &q);

    //col representa a coluna atual do cursor

    int col = -1;

    for (int i = 0; i < q; i++) {
        int x;
        char c;
        scanf("%d %c", &x, &c);

        if (c == 'D') {
            //calcula até qual coluna o cursor vai chegar
            int nova_col = col + x;

            //imprime os espaços antes do primeiro ponto
            for (int j = 0; j < col + 1; j++) printf(" ");

            //imprime os pontos do movimento
            for (int j = 0; j < nova_col - col; j++) printf(".");

            printf("\n");
            col = nova_col;

        } else if (c == 'E') {
            //calcula até qual coluna o cursor vai recuar
            int nova_col = col - x;

            //verifica se o recuo ultrapassa a borda esquerda
            if (nova_col < 0) {
                printf("Informacao invalida\n");
                return 0;
            }

            //imprime os espaços antes do primeiro ponto
            for (int j = 0; j < nova_col; j++) printf(" ");

            //imprime os pontos do movimento (inclui a posição atual)
            for (int j = 0; j < col - nova_col + 1; j++) printf(".");

            printf("\n");
            col = nova_col;

        } else if (c == 'B') {
            //para cada passo para baixo, imprime uma nova linha
            for (int j = 0; j < x; j++) {
                //imprime os espaços para alinhar o ponto na coluna atual
                for (int k = 0; k < col; k++) printf(" ");
                printf(".\n");
            }
        }
    }

    return 0;
}