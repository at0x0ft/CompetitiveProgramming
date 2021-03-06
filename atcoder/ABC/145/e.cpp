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

// Constant variables
const long double PI = (acos(-1));
const long long MOD = 1000000007;

// I/O Asynchronizing
struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
}aaaaaaa;

#define MAX_N 3000
#define MAX_T 3000
int n, t;
pair<int, bitset<MAX_N>> dp[MAX_N + 1][MAX_T + 1];

int main() {
    cin >> n >> t;
    vi a(n), b(n);
    REP(i, n) {
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    bitset<MAX_N> st;
    REP(i, n) {
        REP(j, t) {
            if(j >= a[i]) {
                ll v = dp[i][j - a[i]].first + b[i];
                if(v > dp[i][j].first) {
                    dp[i + 1][j].first = v;
                    dp[i + 1][j].second = dp[i][j].second;
                    dp[i + 1][j].second[i] = true;
                    if(ans < v) {
                        ans = v;
                        st = dp[i + 1][j].second;
                    }
                }
                else {
                    dp[i + 1][j].first = dp[i][j - a[i]].first;
                    dp[i + 1][j].second = dp[i][j].second;
                }
            }
        }
    }
    int num = 0;
    REP(i, n) {
        if(!st[i]) num = max(a[i], num);
    }
    ans += num;

     REP(i, n) {
        if(t >= a[i]) {
            ll v = dp[i][t - a[i]].first + b[i];
            if(v > dp[i][t].first) {
                dp[i + 1][t].first = v;
                dp[i + 1][t].second = dp[i][t].second;
                dp[i + 1][t].second[i] = true;
                if(ans < v) {
                    ans = v;
                    st = dp[i + 1][t].second;
                }
            }
            else {
                dp[i + 1][t].first = dp[i][t - a[i]].first;
                dp[i + 1][t].second = dp[i][t].second;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
