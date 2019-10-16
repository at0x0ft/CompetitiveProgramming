#include <bits/stdc++.h>

#define MOD (long long int)1e9 + 7
#define MAX_N 100000

using namespace std;

int prime[MAX_N];
long long int fact[MAX_N];

long long int combi(const int n, const int r)
{
    cerr << "[debug] : n = " << n << "\n"; // 4debug
    cerr << "[debug] : r = " << r << "\n"; // 4debug
    long long int ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

int factorize(long long int n, int &csum)
{
    int cnt = 0;
    csum = 0;
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            prime[cnt]++;
            n /= i;
        }
        csum += prime[cnt];
        cnt++;
    }
    return cnt;
}

long long int factrial(const int n)
{
    if (fact[n] == 0)
    {
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact[i] = i * fact[i - 1];
            fact[i] %= MOD;
        }
    }
    return fact[n];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int csum;
    int pnum = factorize(m, csum);
    cerr << "[debug] : pnum = " << pnum << "\n"; // 4debug
    cerr << "[debug] : csum = " << csum << "\n"; // 4debug
    long long int a = factrial(csum), b = combi(csum + 1, n - 1);
    for (int i = 0; i < pnum; i++)
    {
        a /= factrial(prime[i]);
    }
    cerr << "[debug] : a = " << a << "\n"; // 4debug
    cerr << "[debug] : b = " << b << "\n"; // 4debug

    printf("%lld\n", (a * b) % MOD);

    return 0;
}
