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

#define MAX_SLEN 100000
#define MOD 1000000000 + 7

ll ans = 0;
int s_len = 0;
int dp[MAX_SLEN][9];

void update_ans(const ll add) {
    ans += add;
    ans %= MOD;
}

int main() {
    string s;
    cin >> s;
    vi ans(s.length(), 0);
    int low_lim = 0, up_lim = -1;
    REP(i, s.length() - 1) {
        if(s[i] == 'R' && s[i + 1] == 'L') {
            ans[i]++;
            ans[i + 1]++;
            up_lim = i + 1;
            while(up_lim < s.length() && s[up_lim + 1] == 'L') up_lim++;
            FOR(j, low_lim, i) {
                if((i - j) % 2 == 1) ans[i + 1]++;
                else ans[i]++;
            }
            FOR(j, i + 2, up_lim + 1) {
                if((j - i - 2) % 2 == 1) ans[i + 1]++;
                else ans[i]++;
            }
            low_lim = up_lim + 1;
            i = up_lim;
        }
    }

    REP(i, s.length()) {
        if(i < s.length() - 1) cout << ans[i] << " ";
        else cout << ans[i] << "\n";
    }

    return 0;
}
