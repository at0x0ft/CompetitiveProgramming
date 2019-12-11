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

inline bool ok(const str &s, const ll loc, const str &t) {
    int i = loc;
    REPR(j, t.length()) {
        if(i < 0) return false;
        if(s[i] == '?' || s[i] == t[j]) i--;
        else return false;
    }
    return true;
}

int main() {
    str s, t, ans = "";
    cin >> s >> t;
    REPR(i, s.length()) {
        if(ok(s, i, t)) {
            s = s.substr(0, i - t.length() + 1) + t + s.substr(i + 1);
            break;
        }
        if(i <= 0) ans = "UNRESTORABLE";
    }
    REP(i, s.length()) {
        if(s[i] == '?') s[i] = 'a';
    }

    cout << (ans != "" ? ans : s) << endl;

    return 0;
}
