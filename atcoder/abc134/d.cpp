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

#define MAX_N 200000
bitset<MAX_N> b(0);

void print_b(const int n) {
    REP(i, n) {
        cerr << b[i];
    }
    cerr << "\n";
}

int main() {
    int n;
    cin >> n;
    vi a(n);
    int cnt = 0;
    REP(i, n) {
        cin >> a[i];
    }
    REPR(i, n) {
        bool cnd = a[i];
        // print_b(n);
        FOR(j, 2, n / (i + 1) + 1) {
            // DBG(j * (i + 1));
            // DBG(cnd);
            cnd ^= b[j * (i + 1) - 1];
        }
        // DBG(i);
        // DBG(cnd);
        if(cnd) {
            b.set(i);
            cnt++;
        }
        else b.reset(i);
    }
    cout << cnt << "\n";
    bool out_flg = false;
    if(cnt > 0) {
        REP(i, n) {
            if(b[i] && !out_flg) {
                cout << i + 1;
                out_flg = true;
            }
            else if(b[i]) cout << " " << i + 1;
        }
        cout << "\n";
    }

    return 0;
}
