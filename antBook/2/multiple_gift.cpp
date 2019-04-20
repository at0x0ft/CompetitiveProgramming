#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<std::string> split(const string &input, char delimiter)
{
    std::istringstream stream(input);

    std::string field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter))
    {
        result.push_back(field);
    }
    return result;
}

int main()
{
    string input;
    getline(cin, input);

    auto inputs = split(input, ' ');
    ll x = stoll(inputs[0]);
    ll y = stoll(inputs[1]);

    int cnt = 1;
    while (true)
    {
        x *= 2;
        if (x <= y)
            cnt++;
        else
            break;
    }

    printf("%d\n", cnt);

    return 0;
}
