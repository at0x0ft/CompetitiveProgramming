#include <bits/stdc++.h>

using namespace std;

int digitSum(int n) {
    int ret = 0;
    while(n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    int N, ans = INT_MAX;

    scanf("%d", &N);

    int tmp = 0;
    for(int i = 1; i <= N / 2; i++) {
        tmp = digitSum(i) + digitSum(N - i);
        if(ans > tmp) {
            ans = tmp;
        }
    }

    printf("%d\n", ans);

    return 0;
}