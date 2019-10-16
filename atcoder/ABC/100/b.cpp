#include <bits/stdc++.h>

using namespace std;


int pow(int a, int n)
{
    if(n == 0) return 1;
    else return a * pow(a, n - 1);
}

int main()
{
    int D, N;

    scanf("%d %d", &D, &N);

    printf("%d\n", N != 100 ? N * pow(100, D) : (N + 1) * pow(100, D));

    return 0;
}