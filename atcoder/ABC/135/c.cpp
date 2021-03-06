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

inline bool is_in(const int x, const int a, const int b) {
    return a <= x && x <= b;
}

int main() {
    int n;
    cin >> n;
    vi a(n + 1), b(n);
    REP(i, n + 1) {
        cin >> a[i];
    }
    REP(i, n) {
        cin >> b[i];
    }

    ll ans = 0;
    for(int i = 0; i - (n - i - 1) <= 1; i++) {
        ans += min(a[i], b[i]);
        if(a[i] < b[i]) {
            b[i] -= a[i];
            a[i] = 0;
        }
        else {
            a[i] -= b[i];
            b[i] = 0;
        }
        ans += min(a[i + 1], b[i]);
        if(a[i + 1] < b[i]) {
            b[i] -= a[i + 1];
            a[i + 1] = 0;
        }
        else {
            a[i + 1] -= b[i];
            b[i] = 0;
        }
        // DBG(ans); // 4debug
        ans += min(a[n - i], b[n - i - 1]);
        if(a[n - i] < b[n - i - 1]) {
            b[n - i - 1] -= a[n - i];
            a[n - i] = 0;
        }
        else {
            a[n - i] -= b[n - i - 1];
            b[n - i - 1] = 0;
        }
        ans += min(a[n - i - 1], b[n - i - 1]);
        if(a[n - i - 1] < b[n - i - 1]) {
            b[n - i - 1] -= a[n - i - 1];
            a[n - i - 1] = 0;
        }
        else {
            a[n - i - 1] -= b[n - i - 1];
            b[n - i - 1] = 0;
        }
        // DBG(ans); // 4debug
    }

    cout << ans << "\n";

    return 0;
}
