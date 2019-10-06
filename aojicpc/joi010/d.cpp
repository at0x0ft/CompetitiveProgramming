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

#define MAX_VAL 20
#define MAX_N 100
ll cnt[MAX_N - 1][MAX_VAL + 1] = { 0 };

inline bool is_in_range(const int v) {
    return 0 <= v && v <= MAX_VAL;
}

int main() {
    int n, a;
    cin >> n >> a;
    cnt[0][a] = 1;
    REP(i, n - 2) {
        int v;
        cin >> v;
        REP(j, MAX_VAL + 1) {
            if(cnt[i][j] > 0) {
                int v1 = j + v, v2 = j - v;
                if(is_in_range(v1)) {
                    cnt[i + 1][v1] += cnt[i][j];
                }
                if(is_in_range(v2)) {
                    cnt[i + 1][v2] += cnt[i][j];
                }
            }
        }
    }
    int ans;
    cin >> ans;
    cout << cnt[n - 2][ans] << "\n";

    return 0;
}
