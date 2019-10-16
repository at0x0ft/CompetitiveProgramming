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

void print_exp(const bitset<3> &b, const vi a) {
    REP(i, 4) {
        if(i == 3) cout << a[i] << "=7\n";
        else {
            cout << a[i] << (b[i] ? '+' : '-');
        }
    }
}

int main() {
    vi a(4);
    REP(i, 4) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    for(int bit = 0; bit < (1 << 3); bit++) {
        int ans = a[0];
        bitset<3> b(bit);
        REP(i, 3) {
            if(b[i]) {
                ans += a[i + 1];
            }
            else {
                ans -= a[i + 1];
            }
        }
        if(ans == 7)  {
            print_exp(b, a);
            break;
        }
    }

    return 0;
}
