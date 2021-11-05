#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CharToInt(const char c) {
    switch (c) {
        case '0':

            return 0;

        case '1':

            return 1;

        case '2':

            return 2;

        case '3':

            return 3;

        case '4':

            return 4;

        case '5':

            return 5;

        case '6':

            return 6;

        case '7':

            return 7;

        case '8':

            return 8;

        case '9':

            return 9;

        default:

            return 0;

    }

}

int main() {
    char op1[200] = {};

    printf("Enter op1:");

    scanf("%s", op1);

    if (strlen(op1) % 2 > 0) {

        printf("op1 dolgno bit chetnoe!");

        return (-1);

    }

    int sop1 = strlen(op1);

    int *a;

    a = (int *) malloc(sop1 * sizeof(int) / 2);

    int m = 0;

    int n = 0;

    while (n < sop1 / 2) {

        int d = CharToInt(op1[m]) * 10;

        m++;

        int e = CharToInt(op1[m]);

        m++;

        a[n] = d + e;

        n++;
    }

    char op2[200] = {};

    printf("Enter op2:");

    scanf("%s", op2);

    if (strlen(op2) % 2 > 0) {

        printf("op2 dolgno bit chetnoe!");

        return (-1);

    }

    int sop2 = strlen(op2);

    int *b;

    b = (int *) malloc(sop1 * sizeof(int) / 2);

    m = 0;

    n = 0;

    while (n < sop2 / 2) {

        int d = CharToInt(op2[m]) * 10;

        m++;

        int e = CharToInt(op2[m]);

        m++;

        b[n] = d + e;

        n++;
    }


    int sizeA = sop1 / 2;
    int sizeB = sop2 / 2;

    for (int t = 0; t < sizeA; t++) printf("%d ", a[t]);
    puts("");
    for (int y = 0; y < sizeB; y++) printf("%d ", b[y]);

    printf("\nsizeA=%d sizeB=%d\n", sizeA, sizeB);


    int i, u = sizeB - 1, a1, b1, s, p = 0;
    int c[sizeA];
    for (int i = 0; i < sizeA; i++) c[i] = 0;

    int k = sizeA - 1;

    for (i = sizeA - 1; i >= 0; i--) {

        while (u >= 0) {

            a1 = a[i] - p;

            b1 = b[u];

            s = a1 - b1;

            p = 0;

            if (s < 0) {
                p = 1;
                s = s + 58;
                u--;
                i--;
                c[k] = s;
                k--;
            } else {

                u--;

                i--;

                c[k] = s;
                k--;

            }


        }

        a1 = a[i] - p;

        s = a1;

        p = 0;

        if (s < 0) {

            p = 1;

            s = s + 58;

            i--;

            c[k] = s;
            k--;
        } else {

            i--;

            c[k] = s;
            k--;

        }

    }

    puts("a-b");

    for (int i = 0; i < sizeA; i++) {

        if (c[i] != 0) printf("%d ", c[i]);

    }

    return 0;

}