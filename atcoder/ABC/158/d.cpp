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

int main() {
    str s;
    int q;
    cin >> s >> q;
    bool rev = false;
    vector<char> hd, tl;
    REP(i, q) {
        int t;
        cin >> t;
        if(t == 1) rev = !rev;
        if(t == 2) {
            int f;
            char c;
            cin >> f >> c;
            if(rev) f = 3 - f;
            if(f == 1) hd.push_back(c);
            else tl.push_back(c);
        }
    }
    if(rev) {
        REPR(i, tl.size()) {
            cout << tl[i];
        }
        REPR(i, s.size()) {
            cout << s[i];
        }
        REP(i, hd.size()) {
            cout << hd[i];
        }
        cout << "\n";
    }
    else {
        REPR(i, hd.size()) {
            cout << hd[i];
        }
        cout << s;
        REP(i, tl.size()) {
            cout << tl[i];
        }
        cout << "\n";
    }
    return 0;
}
