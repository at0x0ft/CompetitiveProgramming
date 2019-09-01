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

#define MAX_N 100
int n;
pair<pii, bitset<MAX_N>> dp[MAX_N][MAX_N];

inline ll calc_sq_d(const pii c) {
    return (ll)c.first * c.first + (ll)c.second * c.second;
}

inline pii c_add(const pii a, const pii b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

void print_c(const pii a) {
    cerr << "(" << a.first << ", " << a.second << ")\n";
}

int main() {
    cin >> n;
    vpii c(n);
    REP(i, n) {
        cin >> c[i].first >> c[i].second;
    }
    ll ans = 0;
    REP(i, n) {
        REP(j, n) {
            if(j < i) continue;
            // DBG(j); // 4debug
            // DBG(i); // 4debug
            // print_c(dp[j][i]);  // 4debug
            if(i == 0) {
                dp[j][i].first = c[j];
                dp[j][i].second = bitset<MAX_N>().set(j);
                ans = max(ans, calc_sq_d(c[j]));
            }
            else {
                FOR(k, 1, n) {
                    if(j + k >= n) break;
                    // dp[(j + k) % n][i] = max(dp[(j + k) % n][i], dp[(j + k) % n][i - 1] + c[j])
                    if(dp[(j + k) % n][i - 1].second[j]) break;
                    pii tmp = c_add(dp[(j + k) % n][i - 1].first, c[j]);
                    if(calc_sq_d(dp[(j + k) % n][i].first) < calc_sq_d(tmp)) {
                        dp[(j + k) % n][i].first = tmp;
                        dp[(j + k) % n][i].second = dp[(j + k) % n][i - 1].second;
                        dp[(j + k) % n][i].second.set(j);
                        ans = max(ans, calc_sq_d(tmp));
                    }

                    DBG((j + k) % n); // 4debug
                    DBG(i); // 4debug
                    print_c(dp[(j + k) % n][i].first);  // 4debug
                    DBG(dp[(j + k) % n][i].second);
                }
            }
        }
    }

    cout << sqrtl(ans) << "\n";

    return 0;
}
