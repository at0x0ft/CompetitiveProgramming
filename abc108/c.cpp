#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    long long int cnt = 0, tmp;

    if(k % 2 == 0) {
        tmp = floor(1.0 * (n - k / 2) / k) + 1;
        cnt += tmp < 0 ? 0 : tmp * tmp * tmp;
    }

    tmp = floor(n / k);
    cnt += tmp < 0 ? 0 : tmp * tmp * tmp;

    printf("%lld\n", cnt);

    return 0;
}