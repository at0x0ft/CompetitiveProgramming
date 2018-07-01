#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    int ans = 0;
    string S;

    cin >> N;

    printf("%d\n", N % 2 == 0 ? N : N * 2);

    return 0;
}