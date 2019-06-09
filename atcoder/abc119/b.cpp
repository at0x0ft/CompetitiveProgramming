#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string u;
    double x, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> u;
        if (u == "BTC")
            sum += x * 380000.0;
        else
            sum += x;
    }

    printf("%f\n", sum);

    return 0;
}
