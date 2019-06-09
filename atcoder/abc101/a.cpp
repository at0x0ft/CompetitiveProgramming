#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans = 0;
    string S;

    cin >> S;
    for(int i = 0; i < 4; i++) {
        S[i] == '+' ? ans++ : ans--;
    }

    printf("%d\n", ans);
}