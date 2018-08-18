#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, q, ans, l, r, a, b;

    scanf("%d %d %d", &n, &m, &q);
    vector<pair<int, int>> len(m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &l, &r);
        len[i].first = r - l;
        len[i].second = l;
    }
    sort(len.begin(), len.end());

    for(int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        ans = 0;
        for(int j = 0; j < m; j++) {
            if(len[j].first <= b - a && a <= len[j].second && b >= len[j].first + len[j].second) ans++;
            else if(len[j].first > b - a) break;
        }
        printf("%d\n", ans);
    }

    return 0;
}
