#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    long long int tmp = 0, cnd = LLONG_MAX;
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &(x[i]));
        if(i > 0) {
            tmp += x[i] - x[i - 1];
            if(i >= k) tmp -= x[i - k + 1] - x[i - k];
        }
        if(i >= k - 1) cnd = min(cnd, tmp + min(abs(x[i - k + 1]), abs(x[i])));
    }

    printf("%lld\n", cnd);

    return 0;
}