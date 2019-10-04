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

#define MAX_D 10

int main() {
    int d, g;
    cin >> d >> g;
    vi p(d), c(d);
    REP(i, d) {
        cin >> p[i] >> c[i];
    }
    int ans = INT_MAX;
    for(int bit = 0; bit < (1 << d); bit++) {
        bitset<MAX_D> b(bit);
        int score = 0, max_not_select_idx = -1, count = 0;
        REP(i, d) {
            if(b[i]) {
                score += p[i] * 100 * (i + 1) + c[i];
                count += p[i];
            }
            else {
                max_not_select_idx = max(max_not_select_idx, (int)i);
            }
        }
        if(score >= g) ans = min(ans, count);
        else if(score + (p[max_not_select_idx] - 1) * 100 * (max_not_select_idx + 1) >= g) {
            ans = min(ans, count + (g - score + (100 * (max_not_select_idx + 1)) - 1) / (100 * (max_not_select_idx + 1)));
        }
    }
    cout << ans << "\n";

    return 0;
}