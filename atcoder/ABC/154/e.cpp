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

#define MAX_NLEN 100
int n_len;
#define MAX_K 3
int k;

ll dp[MAX_NLEN + 1][MAX_K + 1];

int main() {
    str n;
    cin >> n >> k;
    n_len = n.length();
    REP(i, n_len + 1) {
        REP(j, k + 1) {
            if(j > i) continue;
            if(j == 0) dp[i][j] = 1;
            if(i + 1 <= n_len) {
                dp[i + 1][j] += dp[i][j];
                if(j + 1 <= k) {
                    dp[i + 1][j + 1] += (i == j ? (n[i] - '0') + (dp[i][j] - 1) * 9 : dp[i][j] * 9);
                }
            }
        }
    }
    cout << dp[n_len][k] << "\n";

    return 0;
}
