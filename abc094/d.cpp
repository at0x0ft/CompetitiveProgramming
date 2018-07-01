#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main()
{
    int n, ans;

    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &(a[i]));
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; i++)
    {
        if(a[i] * 2 > a[n - 1])
        {
            ans = a[i] - a[n - 1] / 2 > a[n - 1] / 2 - a[i - 1] ? a[i - 1] : a[i];
            break;
        }
        
        if(i == n - 2)
        ans = a[i];
    }

    printf("%d %d\n", a[n - 1], ans);

    return 0;
}
