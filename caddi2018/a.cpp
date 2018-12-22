#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    scanf("%d", &k);

    printf("%d\n", k % 2 == 0 ? k * k / 4 : (k * k - 1) / 4);

    return 0;
}