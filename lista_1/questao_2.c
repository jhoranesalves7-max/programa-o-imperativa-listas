#include <stdio.h>

int main() {
    long long n, a, b;

    scanf("%lld", &n);
    scanf("%lld %lld", &a, &b);

    long long ma = n / a; //contam quantos multiplos de a no intervalo
    long long mb = n / b; //contam quantos multiplos de b no intervalo
    long long mab = n / (a * b); //contam quantos multiplos de  no intervalo

    long long soma = n * (n + 1) / 2; //formula de gauss
    long long soma_a =  a * ma * (ma + 1) / 2; //retira os multipos de a
    long long soma_b =  b * mb * (mb + 1) / 2; //retira os multiplos de b
    long long soma_ab =  (a * b) * mab * (mab + 1) / 2; //soma os multiplos de a e b

    long long soma_final = soma - soma_a - soma_b + soma_ab;

    if (soma_final % 2 == 0)
        printf("%lld Lá ele!!!\n", soma_final);
    else
        printf("%lld Opa xupenio AULAS...\n", soma_final);

    return 0;
}

// usei ia para a correção da logica matemática desse trecho de código:

/* long long soma = n * (n + 1) / 2; //formula de gauss
    long long soma_a =  a * ma * (ma + 1) / 2; //retira os multipos de a
    long long soma_b =  b * mb * (mb + 1) / 2; //retira os multiplos de b
    long long soma_ab =  (a * b) * mab * (mab + 1) / 2; //soma os multiplos de a e b

    long long soma_final = soma - soma_a - soma_b + soma_ab;*/

// e para relembrar a formula de gauss