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

inline bool can_create_triangle(const int a, const int b, const int c) {
    return a < b + c && b < c + a && c < a + b;
}

#define MAX_L 1000

int cnt[MAX_L + 1] = { 0 };

inline ll combi3(const int n) {
    return ((ll)n) * (n - 1) * (n - 2) / 6;
}

inline ll combi2(const int n) {
    return ((ll)n) * (n - 1) / 2;
}

int main() {
    int n;
    cin >> n;
    vi l;
    set<int> st;
    REP(i, n) {
        int a;
        cin >> a;
        if(st.count(a) == 0) l.push_back(a);
        cnt[a]++;
        st.insert(a);
    }
    SORTALL(l);
    ll ans = 0;
    REP(i, l.size()) {
        FOR(j, i + 1, l.size()) {
            for(int k = j + 1; l[k] < l[i] + l[j] && k < l.size(); k++) {
                ans += ((ll)cnt[l[k]]) * cnt[l[i]] * cnt[l[j]];
            }
        }
    }
    REP(i, l.size()) {
        if(cnt[l[i]] >= 2) {
            for(int j = 0; l[j] < 2 * l[i] && j < l.size(); j++) {
                if(i == j) continue;
                ans += combi2(cnt[l[i]]) * cnt[l[j]];
            }
        }
    }
    REP(i, l.size()) {
        if(cnt[l[i]] >= 3) ans += combi3(cnt[l[i]]);
    }
    cout << ans << "\n";

    return 0;
}
