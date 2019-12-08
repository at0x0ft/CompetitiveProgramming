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

ll n, k;

#define MAX_H 80
#define MAX_W 80
int h, w;

inline bool is_in_range(const int y, const int x) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

int bfs() {
    queue<pair<int, pii>> que;
    return 0;
}

int main() {
    cin >> n >> k;
    vpll s(n);
    ll ans = 0, a;
    cin >> a;
    s[0].first = a % k;
    s[0].second = 1;
    if(s[0].first == s[0].second) ans++;
    FOR(i, 1, n) {
        cin >> a;
        s[i].first = (a + s[i - 1].first) % k;
        s[i].second = (i + 1);
        if(s[i].first == s[i].second) ans++;
        FOR(j, max(0LL, i - k + 1), i) {
            ll d = s[i].first - s[j].first + k;
            d %= k;
            if(d == s[i].second - s[j].second) ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}
