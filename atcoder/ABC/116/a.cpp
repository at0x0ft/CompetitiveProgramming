#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    printf("%d\n", min(x * y, min(y * z, z * x)) / 2);

    return 0;
}