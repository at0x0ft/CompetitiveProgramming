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
    int b = 1, r = 0, q_cnt = 0;
    REPR(i, s.length()) {
        if(s[i] == '?') {
            int d = (s.length() - 1 - i);
            REP(j, 9) {
                dp[q_cnt][j] = ((b * (j + 1)) % 13 + r) % 13;
            }
            q_cnt++;
        }
        else {
            // int d = (s.length() - 1 - i);
            r += (b * (s[i] - '0')) % 13;
            r %= 13;
        }
        b *= 10;
        b %= 13;
    }


    return 0;
}
