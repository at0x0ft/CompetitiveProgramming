#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int nh = n / 2;
    set<int> os, es;
    vector<pair<int, int>> oc, ec;
    for (int i = 0; i < nh; i++)
    {
        int on, en;
        scanf("%d %d", &on, &en);

        if (os.count(on) > 0)
        {
            oc.push_back(pair<int, int>(on, 1));
        }
        os.insert(on);
        es.insert(en);
    }

    for (auto &&i : oc)
    {
        cerr << "odd = " << i.first << ", counts = " << i.second << "\n";
    }

    for (auto &&i : ec)
    {
        cerr << "even = " << i.first << ", counts = " << i.second << "\n";
    }

    sort(ec.begin(), ec.end());

    // printf("%s\n", j ? "Yes" : "No");

    return 0;
}
