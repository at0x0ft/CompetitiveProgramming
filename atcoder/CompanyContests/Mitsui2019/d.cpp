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

vs create_ss(const vector<char> &cl) {
    vs ret;
    set<str> st;
    REP(i, cl.size()) {
        REP(j, cl.size()) {
            REP(k, cl.size()) {
                str s = to_string(cl[i] - '0') + to_string(cl[j] - '0') + to_string(cl[k] - '0');
                if(st.count(s) == 0) {
                    ret.push_back(s);
                    st.insert(s);
                }
            }
        }
    }
    return ret;
}

bool judge(const str &ss, const str &s) {
    int idx = 0;
    // DBG(ss);
    REP(i, s.size()) {
        if(idx == 3) return true;
        else if(idx < 3 && ss[idx] == s[i]) {
            // DBG(idx);
            // DBG(i);
            idx++;
            if(idx == 3) return true;
        }
    }
    return false;
}

int main() {
    int n;
    str s;
    cin >> n >> s;
    set<char> st;
    vector<char> clist;
    REP(i, n) {
        if(st.count(s[i]) == 0) {
            clist.push_back(s[i]);
            st.insert(s[i]);
        }
    }
    vs sl = create_ss(clist);
    ll ans = 0;
    REP(i, sl.size()) {
        if(judge(sl[i], s)) {
            // DBG("OK");
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}
