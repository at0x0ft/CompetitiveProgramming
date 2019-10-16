#include <bits/stdc++.h>

using namespace std;

int main()
{
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);

    string ans = "TBD";
    if (y < 2019)
        ans = "Heisei";
    else if (y == 2019 && m <= 4)
        ans = "Heisei";

    cout << ans << "\n";

    return 0;
}
