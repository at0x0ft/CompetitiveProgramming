#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    printf("%d %d %d %d\n", c - d + b, d + c - a, a - d + b, b + c - a);

    return 0;
}