#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    long long int k;

    cin >> s;
    scanf("%lld", &k);

    for(long long int i = 0; i < k; i++) {
        if(s[i] != '1' || i == k - 1) {
            printf("%c\n", s[i]);
            break;
        }
    }

    return 0;
}