#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, n) for(ll i = ((ll) a); i < ((ll) n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define DMP(x) cerr << #x << " = " << (x) << endl
#define DBG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl

#define MAX_N 100000
#define MAX_M 100000

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


int n, m;
int w[MAX_N];
vector<int> link[MAX_N];
bool is_in_cycle[MAX_N];
bool visited[MAX_N];

struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(20);
    };
}aaaaaaa;

inline int adjacent(const int node, const pii e) {
    return e.first == node ? e.second : e.first;
}

inline bool is_in_edge(const int node, const pii e) {
    return e.first == node || e.second == node;
}

ll calc_max_tree_val(const int now, const int prev) {
    visited[now] = true;
    ll res = w[now];
    // cerr << "now : " << now << endl;
    for(auto next : link[now]) {
        if(next != prev && !is_in_cycle[next] && !visited[next]) {
            // cerr << "next : " << next << endl;  // 4debug
            res = max(res, w[now] + calc_max_tree_val(next, now));
            // DBG(res);
        }
    }
    visited[now] = false;
    return res;
}

void search(const int now, const int prev) {
    visited[now] = true;
    // cerr << "now searching : " << now << " and prev : " << prev << endl;
    for(auto next : link[now]) {
        // DBG(es[j].first);
        // DBG(es[j].second);
        // cerr << "next : " << next << endl;
        if(next == prev) continue;
        else if(visited[next]) {
            // cerr << "found cycle" << endl;  // 4debug
            REP(i, n) {
                is_in_cycle[i] |= visited[i];
            }
        }
        else{
            search(next, now);
        }
    }
    visited[now] = false;
}

int main() {
    cin >> n >> m;
    REP(i, n) {
        cin >> w[i];
    }
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        link[u - 1].push_back(v - 1);
        link[v - 1].push_back(u - 1);
    }

    search(0, -1);
    ll sum = 0;
    vector<int> roots;
    REP(i, n) {
        if(!is_in_cycle[i]) {
            for(auto next : link[i]) {
                if(is_in_cycle[next]) roots.push_back(i);
            }
        }
        else {
            sum += w[i];
        }
    }


    ll mp = LLONG_MIN;
    for(auto root : roots) {
        // DBG(root);
        mp = max(mp, calc_max_tree_val(root, -1));
    }
    // cerr << "debug" << endl;    // 4debug

    cout << mp + sum << endl;

    return 0;
}
