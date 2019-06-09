#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, d = INT_MAX, cnt = 0;
    double ave = 0.0;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        cin>>ab[i].first>>ab[i].second;
        if(d > ab[i].second - ab[i].first)
    }

    sort(ab.begin(), ab.end());

    vector<set<int>> g(2);

    g[0].insert(ab[0].first);
    g[1].insert(ab[0].second);

    for(int i = 1; i < ab.size(); i++) {
        bool fstFlg = false;
        for(int j = 0; j < g.size(); j++) {
            if(!fstFlg && g[j].count(ab[i].first) > 0) {
                fstFlg = true;
                continue;
            }
            else if(fstFlg && g[j].count(ab[i].second) > 0) break;
            if(!fstFlg && j == g.size() - 1 && !fstFlg) {
                fstFlg = true;
                set<int> tmp{ ab[i].first };
                g.push_back(tmp);
            }
            else if(fstFlg && j == g.size() - 1) {
                set<int> tmp{ ab[i].second };
                g.push_back(tmp);
            }
        }
    }

    printf("%d\n", (int)ab.size() - 1);

    return 0;
}
