#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans;

    scanf("%d", &n);

    if(n < 105) ans = 0;    // 3 * 5 * 7
    else if(n < 135) ans = 1;   // 3^3 * 5
    else if(n < 165) ans = 2;   // 3 * 5 * 11
    else if(n < 189) ans = 3;   // 3^3 * 7
    else if(n < 195) ans = 4;   // 3 * 5 * 13
    else ans = 5;

    printf("%d\n", ans);

    return 0;
}