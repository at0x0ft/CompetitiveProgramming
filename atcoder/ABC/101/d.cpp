#include <bits/stdc++.h>

using namespace std;

int main() {
    int K;
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int b = 9, digit = 1;

    scanf("%d", &K);
    int i = 0;
    for(i = 0; i < 9 && i < K; i++) {
        printf("%d\n", a[i % 9]);
    }
    digit++;
    for(; i < K; i++) {
        if(digit % 2 != 0) {
        }
        if(b[i % 9] == 0) {
            printf("%d\n", a[i % 9]);
        }
        else {
            for(int j = 0; j < a[0]; j++) {
                printf("%d%d\n", a[i % 9] + j + 1, b[i % 9]);
                if((i / 9) % 2 == 0) {
                    a[i % 9] *= 10;
                }
            }
        }

        for(int j = 0; j < digit / 2; j++) {
                printf("%d", b);
        }
        printf("\n");
    }

    return 0;
}
