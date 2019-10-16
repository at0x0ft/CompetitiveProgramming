#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a;
    long long int ans = 0;

    scanf("%d %d", &n, &m);
    vector<long long int> as(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        if(i == 0) as[i] = a % m;
        else as[i] = ((a % m) + as[i - 1]) % m;
    }

    sort(as.begin(), as.end());

    for(int i = 0; i < n; i++) {
        int now = i;
        while(i + 1 < m && as[now] == as[i + 1]) i++;
        if(as[now] == 0) ans += i - now + 1;
        ans += (i - now + 1) * (i - now) / 2;
    }

    printf("%lld\n", ans);

    return 0;
}
