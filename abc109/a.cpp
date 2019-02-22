#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%s\n", a % 2 == 1 && b % 2 == 1 ? "Yes" : "No");

    return 0;
}
