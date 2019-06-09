#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10000

int main() {
    int N, K, b = 0, c = 0;

    scanf("%d %d", &N, &K);
    int buf, aidx = -1;
    for(int i = 0; i < N; i++) {
        scanf("%d", &buf);
        if(buf == 1) aidx = i;
        else {
            if(aidx >= 0) {
                c++;
            }
            else {
                b++;
            }
        }
    }

    int cnd1 = (b % (K - 1) == 0 ? b / (K - 1) : b / (K - 1)) + 1 + ((c % (K - 1) == 0) ? c / (K - 1) : c / (K - 1) + 1);
    int cnd2 = (b + c - K + 1) % (K - 1) == 0 ? (b + c - K + 1) / (K - 1) + 1 : (b + c - K + 1) / (K - 1) + 2;

    printf("%d\n", min(cnd1, cnd2));

    return 0;
}
