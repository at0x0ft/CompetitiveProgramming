#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000

void addCost(long long int ans[3], int i, int j, long long int a[9 * MAX_N + 3 * MAX_N + 3], long long int b[3])
{
    for(int k = 0; k < 3; k++)
    {
        ans[k] = a[9 * i + 3 * j + k] + b[k];
    }
}

long long int calcCost(int i, int j, long long int c[9 * MAX_N + 3 * MAX_N + 3])
{
    return abs(c[9 * i + 3 * j + 0]) + abs(c[9 * i + 3 * j + 1]) + abs(c[9 * i + 3 * j + 2]);
}

void maxCost(long long int ans[3], long long int a[3], long long int b[3])
{
    if(calcCost(a) < calcCost(b))
    {
        for(int i = 0; i < 3; i++)
        {
            ans[i] = b[i];
        }
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            ans[i] = a[i];
        }
    }
}

long long int calc1MaxSum(int N, long long int x[MAX_N])
{
    long long int max = 0;
    for(int i = 0; i < N; i++)
    {
        if(abs(max) < abs(x[i])) max = x[i];
    }

    return max;
}

long long int calcSumAll(int N, long long int x[MAX_N])
{
    long long int ans = 0;
    for(int i = 0; i < N; i++)
    {
        ans += x[i];
    }
    return ans;
}

int main()
{
    int N, M;

    long long int x[MAX_N], y[MAX_N], z[MAX_N];

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);
    }

    long long int b[9 * MAX_N + 3 * MAX_N + 1 * 3], tmp[3];

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == 0 && j == 0)
            {
                b[9 * i + 3 * j + 0] = calc1MaxSum(j, x);
                b[9 * i + 3 * j + 1] = calc1MaxSum(j, y);
                b[9 * i + 3 * j + 2] = calc1MaxSum(j, z);
            }
            else if(i > j)
            {
                continue;
            }
            else if(i == j)
            {
                b[9 * i + 3 * j + 0] = calcSumAll(j, x);
                b[9 * i + 3 * j + 1] = calcSumAll(j, y);
                b[9 * i + 3 * j + 2] = calcSumAll(j, z);
            }
            else
            {
                tmp[0] = x[j];
                tmp[1] = y[j];
                tmp[2] = z[j];
                addCost(tmp, i, j, b[i - 1][j], tmp);
                maxCost(b[i][j], tmp, i, j, b[i][j - 1]);
            }
        }
    }

    printf("%lld\n", calcCost(b[M - 1][N - 1]));

    return 0;
}
