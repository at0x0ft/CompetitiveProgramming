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
using ll = long long;
using ld = long double;
using str = string;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vs = vector<str>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

// Constant variables
const ld PI = (acos(-1));
const ll MOD = 1000000007;

// I/O Asynchronizing
struct __io_async{
    __io_async(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
};

#define MAX_N 50
int n;
int connect[MAX_N][MAX_N];
set<pii> st;

bool can_reach(const int start_node, set<int> &ns) {
    ns.insert(start_node);
    REP(i, n) {
        if(i == start_node) continue;
        if(connect[start_node][i] == 1 && ns.count(i) == 0) {
            can_reach(i, ns);
        }
    }
    return ns.size() == n;
}

int search() {
    int ans = 0;
    for(auto e : st) {
        connect[e.first][e.second] = 0;
        connect[e.second][e.first] = 0;
        set<int> ns;
        if(!can_reach(e.first, ns)) ans++;
        connect[e.first][e.second] = 1;
        connect[e.second][e.first] = 1;
    }
    return ans;
}

int main() {
    int m;
    cin >> n >> m;
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        connect[a - 1][b - 1] = 1;
        connect[b - 1][a - 1] = 1;
        st.insert(make_pair(a -1, b - 1));
    }
    cout << search() << "\n";

    return 0;
}
