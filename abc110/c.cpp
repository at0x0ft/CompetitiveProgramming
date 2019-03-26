#include <bits/stdc++.h>

using namespace std;

#define ALPHABET_NUM 26

int num1[ALPHABET_NUM], num2[ALPHABET_NUM];

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        num1[s[i] - 'a']++;
        num2[t[i] - 'a']++;
    }

    sort(num1, num1 + ALPHABET_NUM);
    sort(num2, num2 + ALPHABET_NUM);

    bool j = true;
    for (int i = 0; i < ALPHABET_NUM; i++)
    {
        if (num1[i] != num2[i])
        {
            j = false;
            break;
        }
    }

    printf("%s\n", j ? "Yes" : "No");

    return 0;
}
