#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, a, preA = -1, nextA = -1, cnt = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &a);
        if(a == preA) {
            cnt++;
            scanf("%d", &preA);
            i++;
        }
        else {
            preA  = a;
        }
    }

    printf("%d\n", cnt);

    return 0;
}