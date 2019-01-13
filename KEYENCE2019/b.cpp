#include <bits/stdc++.h>

using namespace std;

bool searchFromHead(string, string, const int);
bool searchFromTail(string, string, const int);

bool searchFromHead(string input, string sample, const int cnt)
{
    int sampleLen = sample.length();
    for (int i = 0; i < sampleLen; i++)
    {
        if (input[i] != sample[i])
        {
            if (cnt > 0)
                return searchFromTail(input, sample.substr(i, sampleLen - i), cnt - 1);
            else
                return false;
        }
    }
    return true;
}

bool searchFromTail(string input, string sample, const int cnt)
{
    int sampleLen = sample.length(), inputLen = input.length();
    for (int i = 0; i < sampleLen; i++)
    {
        if (input[inputLen - 1 - i] != sample[sampleLen - 1 - i])
        {
            if (cnt > 0)
                return searchFromHead(input, sample.substr(0, i + 1), cnt - 1);
            else
                return false;
        }
    }
    return true;
}

bool judge(string input)
{
    return input[0] == 'k' ? searchFromHead(input, "keyence", 1) : (input[input.length() - 1] == 'e' ? searchFromTail(input, "keyence", 1) : false);
}

int main()
{
    string input;
    cin >> input;

    printf("%s\n", judge(input) ? "YES" : "NO");

    return 0;
}