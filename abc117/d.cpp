#include <bits/stdc++.h>

using namespace std;

#define MAX_DIG 40

int n, k;
int bit[MAX_DIG] = {0};

void inputBit(long long int a)
{
    for (int cnt = 0; cnt < MAX_DIG; cnt++)
    {
        if (a <= 0)
            break;
        bit[cnt] += a % 2;
        a >>= 1;
    }
}

long long int solve()
{
    long long int kt = 0, ans = 0;
    for (int i = MAX_DIG - 1; i >= 0; i--)
    {
        long long int nkt = kt, tmp = 1 << i;
        if (tmp > k)
            continue;
        kt += tmp;
        if (bit[i] < n / 2) // n - bit[i] < n : 0 > 1
        {
            printf("in i = %d, 0 is over!\n", i); // 4debug
            nkt += tmp;
        }

        if (k < nkt)
            break;

        kt = nkt;
        ans += max(n - bit[i], bit[i]) * tmp;
    }
    printf("k = %lld\n", kt); // 4debug
    return ans;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        long long int a;
        scanf("%lld", &a);
        inputBit(a);
    }

    // 4debug
    for (int i = 0; i < MAX_DIG; i++)
    {
        printf("bit[%d] = %d\n", i, bit[i]);
    }

    printf("%lld\n", solve());

    return 0;
}
