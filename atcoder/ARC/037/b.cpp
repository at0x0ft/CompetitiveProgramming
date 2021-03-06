#include <bits/stdc++.h>

using namespace std;

// Repetitions
#define FOR(i,a,n) for(ll i = ((ll) a); i < ((ll) n); ++i)
#define FORR(i, s, g) for(ll i = ((ll)s - 1); i >= ((ll) g); --i)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n, 0)

// Container Utils
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SORTALL(v) sort(ALL(v))
#define SZ(a) int((a).size())
#define CLR(a) memset((a), 0 ,sizeof(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())

// For Debug
#define DMP(x)  cerr << #x << " = " << (x) << endl
#define DBG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

// Aliases
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef string str;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// I/O Asynchronizing
struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
}aaaaaaa;

#define MAX_N 100
int n;
bool connection[MAX_N][MAX_N] = { false };
bool visited[MAX_N] = { false };

bool dfs(const int node, const int prev) {
    visited[node] = true;
    bool res = true;
    REP(i, n) {
        if(i != prev && connection[node][i]) {
            if(!visited[i]) res &= dfs(i, node);
            else return false;
        }
    }
    return res;
}

int main() {
    int m;
    cin >> n >> m;
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        connection[u][v] = true;
        connection[v][u] = true;
    }
    int ans = 0;
    REP(i, n) {
        if(!visited[i] && dfs(i, -1)) {
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}
