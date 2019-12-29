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

ll decide_maxn(const ll k) {
    ll n = sqrt(2 * k) - 1;
    while((n + 1) * (n + 2) / 2 <= k) n++;
    return n;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vll a(n), s(2 * n, 0);
    REP(i, n) {
        cin >> a[i];
    }
    sort(ALL(a), greater<ll>());
    a.resize(2 * n);
    REP(i, a.size()) {
        if(i > 0) s[i] = a[i] + s[i - 1];
        else s[i] = a[i];
    }
    ll k = decide_maxn(m);
    m -= k * (k + 1) / 2;
    ll ans = 0;
    REP(i, k) {
        ans += a[i] * (k - i) + s[k - 1 - i];
        DBG(ans);
    }
    DBG(k);
    REP(i, m) {
        DBG(k / 2 - i);
        DBG(k - k / 2 + i);
        ll tmp = a[k / 2 - i] + a[k - k / 2 + i];
        ans += tmp;
        if(i + 1 < m && k / 2 - i != k - k / 2 - i) {
            ans += tmp;
            i++;
        }
        DBG(ans);
    }

    cout << ans << "\n";

    return 0;
}
