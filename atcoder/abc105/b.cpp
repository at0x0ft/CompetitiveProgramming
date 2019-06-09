#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    scanf("%d", &n);

    if(n % 2 != 0) n -= 7;
    while(n >= 0) {
        if(n % 4 == 0) {
            printf("Yes\n");
            break;
        }
        n -= 14;
    }

    if(n < 0) printf("No\n");

    return 0;
}