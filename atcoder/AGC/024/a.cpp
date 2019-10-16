#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int A, B, C, K;

    scanf("%lld %lld %lld %lld", &A, &B, &C, &K);

    printf("%lld\n", (K % 2 == 0) ? (A - B) : (B - A));

    return 0;
}