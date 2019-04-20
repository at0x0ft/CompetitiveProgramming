#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = ((int)(n)-1); i >= 0; i--)

#define MAX_W 10000

int sw;
int dp[MAX_W + 1];

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

inline bool isRange(const int i)
{
    return 0 <= i && i <= sw;
}

int main()
{
    string nw;
    getline(cin, nw);
    auto nws = split(nw, ' ');
    int n = stoi(nws[0]);
    sw = stoi(nws[1]);

    vector<int> v(n), w(n);
    REP(i, n)
    {
        string vw;
        getline(cin, vw);
        auto vws = split(vw, ' ');
        v[i] = stoi(vws[0]);
        w[i] = stoi(vws[1]);
    }

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    int ans = INT_MIN;
    REP(i, n)
    {
        RREP(j, sw + 1)
        {
            if (dp[j] >= 0 && isRange(w[i] + j))
            {
                dp[w[i] + j] = max(dp[j] + v[i], dp[w[i] + j]);
                ans = max(dp[w[i] + j], ans);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
