#include <bits/stdc++.h>

using namespace std;

int s(int N) {
    if(N == 0) return 0;
    return (N % 10) + s(N / 10);
}

int main() {
    int N;

    scanf("%d", &N);

    printf("%s\n", N % s(N) == 0 ? "Yes" : "No");

    return 0;
}