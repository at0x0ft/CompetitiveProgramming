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

int gcd(const int a, const int b) {
    if(a < 0 || b < 0) return gcd(abs(a), abs(b));
    else if(b > a) return gcd(b, a);
    else if(b == 1) return 1;
    else if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int n, k;
    cin >> n >> k;
    vi a(n), l(n, 0), r(n, 0), g(n);
    REP(i, n) {
        cin >> a[i];
        if(i > 0) {
            l[i] = gcd(l[i - 1], a[i]);
        }
    }
    REPR(i, n - 1) {
        r[i] = gcd(r[i + 1], a[i]);
    }

    cout << gcd(-12, -8) << "\n";

    return 0;
}
