#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, X;

    scanf("%d %d %d", &A, &B, &X);

    printf("%s\n", A <= X && X <= A + B ? "YES" : "NO");

    return 0;
}