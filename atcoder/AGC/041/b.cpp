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

ll solve(const ll n, const ll m, ll v, ll p, const vll &a) {
    DBG(p); // 4debug
    REP(i, n) { // 4debug
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    ll bound_val = a[n - p];
    if(bound_val != a[n - p - 1]) return p;
    auto def_idx = upper_bound(a.begin() + (n - p), a.end(), bound_val);
    DBG((ll)(def_idx - a.begin())); // 4debug
    p -= (ll)(a.end() - def_idx);
    def_idx--;
    auto max_idx = lower_bound(a.begin(), def_idx, bound_val);
    DBG((ll)(max_idx - a.begin()));
    if((ll)(max_idx - a.begin()) <= v) return (ll)(a.end() - max_idx);
    DBG(bound_val - m);
    auto cnd_idx = lower_bound(a.begin(), max_idx - 1, bound_val - m);
    DBG((ll)(cnd_idx - a.begin()));
    return (ll)(a.end() - cnd_idx);
}

int main() {
    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    vll a(n);
    REP(i, n) {
        cin >> a[i];
    }
    sort(ALL(a));
    ll ans = solve(n, m, v, p, a);
    cout << ans << "\n";

    return 0;
}
