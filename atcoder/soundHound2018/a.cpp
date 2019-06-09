#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%s\n", a + b == 15 ? "+" : (a * b == 15 ? "*" : "x"));

    return 0;
}