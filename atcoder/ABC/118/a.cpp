#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", b % a == 0 ? a + b : b - a);

    return 0;
}
