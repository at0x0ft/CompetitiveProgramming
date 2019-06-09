#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    printf("%s\n", abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d) ? "Yes" : "No");
}