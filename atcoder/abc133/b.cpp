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

bool is_sq(const int x) {
    int low = sqrt(x);
    while(low * low <= x) {
        if((low + 1) * (low + 1) <= x) low++;
        else break;
    }

    return (low * low) == x;
}

int sq_d(const vi &x, const vi &y) {
    int res = 0;
    REP(i, x.size()) {
        res += (x[i] - y[i]) * (x[i] - y[i]);
    }
    return res;
}

int main() {
    int n, d;
    cin >> n >> d;
    vvi x(n, vi(d));
    REP(i, n) {
        REP(j, d) {
            cin >> x[i][j];
        }
    }

    int cnt = 0;
    REP(i, n) {
        FOR(j, i + 1, n) {
            if(is_sq(sq_d(x[i], x[j]))) cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
