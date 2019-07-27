#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, n) for(ll i = ((ll) a); i < ((ll) n); ++i)
#define FORR(i, s, g) for(ll i = ((ll) s - 1); i >= ((ll) g); --i)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n, 0)

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline pair<int, string> unpack_format(const string fmt) {
    int cnt = 0;
    while(fmt[cnt] == '.') cnt++;
    return make_pair(cnt, fmt);
}

int main() {
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        vector<pair<int, string> > posts(n);
        vi bars;
        REP(i, n) {
            string buf;
            cin >> buf;
            posts[i] = unpack_format(buf);
        }

        FORR(i, n, 1) {
            // cerr << "Debug : " << bars.back() << endl;
            while(!bars.empty() && posts[i].first - 1 <= bars.back()) bars.pop_back();
            // 4debug
            cerr << "bars = ";
            REP(i, bars.size()) {
                cerr << bars[i] << ", ";
            }
            cerr << endl;
            // 4debug
            if(posts[i].first > 0) posts[i].second[posts[i].first - 1] = '+';
            REP(j, bars.size()) {
                if(bars[j] < posts[i].first - 1) posts[i].second[bars[j]] = '|';
            }
            REP(j, posts[i].first) {
                // cerr << "posts[" << i << "].second[" << j << "] = " << posts[i].second[j] << endl;
                if(posts[i].second[j] == '.') posts[i].second[j] = ' ';
            }
            if(posts[i].first > 0 && posts[i].first < posts[i - 1].first) {
                bars.push_back(posts[i].first - 1);
                // cerr << "bars = " << bars.back() << "@i = " << i << endl;
                // 4debug
                cerr << "bars = ";
                REP(i, bars.size()) {
                    cerr << bars[i] << ", ";
                }
                cerr << endl;
                // 4debug
            }
        }

        // 4debug
        REP(i, n) {
            cout << posts[i].second << endl;
        }
        // 4debug
        // cout << ans << endl;
    }
}
