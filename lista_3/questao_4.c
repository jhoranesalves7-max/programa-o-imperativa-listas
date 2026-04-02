#include <stdio.h>
#include <string.h>

int main() {
    int R;
    scanf("%d", &R);

    char gigante[100000];
    int tam = 0;

    for (int t = 0; t < R; t++) {
        char s[61];
        int C;
        scanf("%s %d", s, &C);
        int n = strlen(s);

        for (int c = 0; c < C; c++) {
            s[0] = (s[0] == 'O') ? 'X' : 'O';
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == 'X')
                    s[i+1] = (s[i+1] == 'O') ? 'X' : 'O';
                else
                    break;
            }
        }

        printf("%s\n", s);

        if (t == 0) {
            strcpy(gigante, s);
            tam = n;
        } else {
            char orn;
            if (tam % 2 == 0 && gigante[tam-1] == s[0]) orn = '@';
            if (tam % 2 == 1 && gigante[tam-1] == s[0]) orn = '#';
            if (tam % 2 == 0 && gigante[tam-1] != s[0]) orn = '$';
            if (tam % 2 == 1 && gigante[tam-1] != s[0]) orn = '%';

            gigante[tam++] = orn;
            strcpy(gigante + tam, s);
            tam += n;
        }
    }

    printf("%s\n", gigante);
    return 0;
}