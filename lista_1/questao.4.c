#include <stdio.h>
#include <stdlib.h> 

int main() {
    int x, y, c;
    if (scanf("%d %d %d", &x, &y, &c) != 3) return 0;

    // quadrante da origem
    int origem = (x > 0 && y > 0) ? 1 :
                (x < 0 && y > 0) ? 2 :
                (x < 0 && y < 0) ? 3 :
                (x > 0 && y < 0) ? 4 : 0;
    
    // quadrante do destino 
    int destino = (origem == 1) ? 3 :
                (origem == 2) ? 4 :
                (origem == 3) ? 1 :
                (origem == 4) ? 2 : 0;

    // Coordenadas do ponto de chegada (1 ou -1 dependendo do quadrante)
    int dx = (destino == 1 || destino == 4) ? 1 : -1;
    int dy = (destino == 1 || destino == 2) ? 1 : -1;

    // quadrante intermediário se mover primeiro em Y
    int mid_y = (x > 0 && dy > 0) ? 1 :
                (x < 0 && dy > 0) ? 2 :
                (x < 0 && dy < 0) ? 3 : 4;

    // quadrante intermediário se mover primeiro em X
    int mid_x = (dx > 0 && y > 0) ? 1 :
                (dx < 0 && y > 0) ? 2 :
                (dx < 0 && y < 0) ? 3 : 4;
                
    int passos_x = abs(dx - x);
    int passos_y = abs(dy - y);

    if (origem == 0 || destino == 0 || (c != mid_y && c != mid_x)) {
    printf("caminhada invalida\n");
    return 0;
}

    if (c == mid_x)
    printf("%d passos em y e %d passos em x\n", passos_y, passos_x);
    else
    printf("%d passos em x e %d passos em y\n", passos_x, passos_y);
    return 0;
}



// usei ia para corrigir esse trecho de código que estava com a logica errada

/*    if (origem == 0 || destino == 0 || (c != mid_y && c != mid_x)) {
    printf("caminhada invalida\n");
    return 0;
}

    if (c == mid_x)
    printf("%d passos em y e %d passos em x\n", passos_y, passos_x);
    else
    printf("%d passos em x e %d passos em y\n", passos_x, passos_y);
    return 0;*/