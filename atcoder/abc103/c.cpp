#include <bits/stdc++.h>
    
using namespace std;
    
int main() {
    int N, ans = 0;

    scanf("%d", &N);
    int a;
    for(int i = 0; i < N; i++) {
        scanf("%d", &a);
        ans += a - 1;
    }

    printf("%d\n", ans);

    return 0;
}