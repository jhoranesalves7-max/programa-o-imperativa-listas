#include <stdio.h>

int main()
{
    int dia1, mes1, ano1, dia2, mes2, ano2;
    scanf("%d/%d/%d %d/%d/%d" , &dia1, &mes1, &ano1, &dia2, &mes2, &ano2);
    
    //amor
    int amor = ((dia1 + mes1 + ano1 + dia2 + mes2 + ano2) * 7) % 101;
    printf("Amor: %d%% ", amor);

    if (amor < 20)
    printf("Pessimo dia para se apaixonar.\n");
    else if ( amor <= 40)
    printf("Melhor manter o coracao <3 longe de perigo.\n");
    else if(amor <= 69)
    printf("Se o papo e as ideias baterem, esta liberado pensar em algo.\n");
    else if (amor <=80)
    printf( "Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.\n");
    else
    printf("Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.\n");

    //sorte
    int diferenca = ano1 - ano2;
    if(diferenca < 0) diferenca = -diferenca;

    int sorte = ((dia1 + dia2 + mes1 + mes2) * 9 + diferenca) % 101;
    printf("Sorte: %d%% " , sorte);

    if (sorte < 30)
    printf("Nem jogue moedas pra cima hoje.\n");
    else if(sorte <= 50)
    printf("Melhor nao arriscar.");
    else if(sorte <= 79)
    printf("Por sua conta em risco.\n");
    else if(sorte <= 90)
    printf("Hoje vale a pena arriscar. Sem tigrinho nem jogos de azar, por favor!\n");
    else
    printf("Nao tenha medo de virar cartas hoje. Sem tigrinho nem jogos de azar, por favor!");

    //trabalho
    int trabalho = ((ano1 + ano2) - (dia1 + dia2 + mes1 +mes2) * 8) % 101;
    if (trabalho < 0) trabalho += 101;
    printf("Trabalho: %d%% " , trabalho);

    if (trabalho < 40)
    printf("Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.\n");
    else if (trabalho <= 50)
    printf("Segura a emocao, nao xinga ninguem, nao esquece de beber agua\n.");
    else if (trabalho <= 69)
    printf("Um dia proveitoso com certeza, leve sua simpatia consigo.\n");
    else if (trabalho <= 84)
    printf("Boas vibracoes hoje, chances podem estar ao seu redor.\n");
    else
    printf("Use do maximo de networking possível hoje, dia bom para negocios.\n");

    //cores
    int cor = (dia1*dia1 + mes1*mes1 + ano1*ano1 + dia2*dia2 + mes2*mes2 + ano2*ano2) % 11;
    if (cor < 0) cor =+ 11;

    printf("Cor: ");
    switch (cor) {
        case 0:  printf("Cinza.\n");     break;
        case 1:  printf("Vermelho.\n");  break;
        case 2:  printf("Laranja.\n");   break;
        case 3:  printf("Amarelo.\n");   break;
        case 4:  printf("Verde.\n");     break;
        case 5:  printf("Azul.\n");      break;
        case 6:  printf("Roxo.\n");      break;
        case 7:  printf("Marrom.\n");    break;
        case 8:  printf("Rosa.\n");      break;
        case 9:  printf("Preto.\n");     break;
        case 10: printf("Branco.\n");    break;
    }

    return 0;
}

// usei I.A para corrigir erros de sintaxe e também para aprender a usar a estrutura de switch