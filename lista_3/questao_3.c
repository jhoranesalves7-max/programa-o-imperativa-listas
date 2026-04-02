#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[101];
    fgets(s, 101, stdin);

    int inicio[50], tam[50], n = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i]) && (i == 0 || !isalpha(s[i-1]))) {
            inicio[n] = i;
            tam[n] = 0;
            while (isalpha(s[i + tam[n]])) tam[n]++;
            n++;
        }
    }

    int pares = 0;

    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            if (tam[a] != tam[b]) continue;

            int freq[26] = {0};
            for (int k = 0; k < tam[a]; k++) freq[tolower(s[inicio[a]+k]) - 'a']++;
            for (int k = 0; k < tam[b]; k++) freq[tolower(s[inicio[b]+k]) - 'a']--;

            int anagrama = 1;
            for (int k = 0; k < 26; k++)
                if (freq[k] != 0) { anagrama = 0; break; }

            if (anagrama) {
                if (pares == 0) printf("Pares de anagramas encontrados:\n");
                for (int k = 0; k < tam[a]; k++) putchar(s[inicio[a]+k]);
                printf(" e ");
                for (int k = 0; k < tam[b]; k++) putchar(s[inicio[b]+k]);
                printf("\n");
                pares++;
            }
        }
    }

    if (pares == 0)
        printf("Nao existem anagramas na frase.\n");
    else
        printf("\nTotal de pares: %d\n", pares);

    return 0;
}