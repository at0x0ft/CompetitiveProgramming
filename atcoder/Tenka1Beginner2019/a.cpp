#include <bits/stdc++.h>

using namespace std;
struct CinInit
{
    CinInit()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
    };
} CinInit;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    printf("%s\n", (a <= c && c <= b) || (b <= c && c <= a) ? "Yes" : "No");

    return 0;
}
