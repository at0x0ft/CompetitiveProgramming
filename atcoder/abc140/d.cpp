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

string rev(str &s, const int l, const int r) {
    str ss = s.substr(l, r - l + 1);
    int si = l;
    REPR(i, ss.length()) {
        s[si] = ss[i] == 'L' ? 'R' : 'L';
        si++;
    }
    return s;
}

int calc_cost(str &s) {
    int ans = 0;
    FOR(i, 1, s.length()) {
        if(s[i] == s[i - 1]) ans++;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    str s;
    cin >> s;

INITIALIZE:
    int li = 1, ri = s.length() - 2;
    while(k > 0) {
        while(s[li] == s[li - 1] && li < s.length()) li++;
        while(s[ri] == s[ri + 1] && ri >= 0) ri--;
        // DBG(li);    // 4debug
        // DBG(ri);    // 4debug
        if(s[li - 1] == s[ri + 1]) {
            s = rev(s, li, ri);
        }
        else if(li >= s.length() - ri - 1) {
            ri--;
            while(s[ri] == s[ri + 1] && ri >= 0) ri--;
            s = rev(s, li, ri);
        }
        else {
            li++;
            while(s[li] == s[li - 1] && li < s.length()) li++;
            s = rev(s, li, ri);
        }
        // DBG(s); // 4debug
        k--;
        if(li > ri) goto INITIALIZE;
    }

    cout << calc_cost(s) << "\n";

    return 0;
}
