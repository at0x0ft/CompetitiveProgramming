#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;
    int n = input.length();

    int cnt = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i == input.length() - 1)
            continue;
        if (input[i + 1] != input[i])
        {
            if (i < n - 2 && i > 0)
                input = input.substr(0, i) + input.substr(i + 2, n - i - 2);
            else if (i < n - 2)
                input = input.substr(i + 2, n - i - 2);
            else
                input = input.substr(0, i);
            cnt++;
        }
    }

    printf("%d\n", cnt * 2);

    return 0;
}
