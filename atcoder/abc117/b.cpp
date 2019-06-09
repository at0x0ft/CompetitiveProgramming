#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, max = INT_MIN, sum = 0, l;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &l);
        if (l > max)
            max = l;
        sum += l;
    }

    printf("%s\n", max < sum - max ? "Yes" : "No");

    return 0;
}
