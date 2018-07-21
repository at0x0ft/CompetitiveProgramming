#include <bits/stdc++.h>

#define DIV 998244353

using namespace std;

void swap(long long int *a, long long int *b) {
    long long int tmp = *a;
    *a = *b;
    *b = tmp;
}

long long int calcBiCombi(long long int N, long long int a, long long int b, long long int K) {
    long long int ans = 0;

    long long int tmp = K / b;
    for(int i = 0; i <= tmp ; i++) {
        if((tmp - i) + (K - (tmp - i) * b) / a > K) break;
        if((K - (tmp - i) * b) % a == 0) {
            ans++;
        }
    }

    return ans;
}

int main() {
    long long int N, A, B, K, ans = 0;
    scanf("%lld %lld %lld %lld", &N, &A, &B, &K);

    if(K == 0) ans = 1;
    else {
        if(A > B) swap(A, B);

        long long int tmp = K / (A + B);
        for(int i = 0; i <= tmp ; i++) {
            if((tmp - i) + (K - (tmp - i) * (A + B)) / B > K) break;
            ans += calcBiCombi(N - tmp + i, A, B, K - (A + B) * (tmp - i));
            ans %= DIV;
        }
    }

    printf("%lld\n", ans);

    return 0;
}