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

int c[3][3];

bool judge() {
    int d1 = c[0][2] - c[1][2], d2 = c[1][2] - c[2][2];
    REP(i, 2) {
        if(d1 != c[0][i] - c[1][i] || d2 != c[1][i] - c[2][i]) return false;
    }
    d1 = c[2][0] - c[2][1], d2 = c[2][1] - c[2][2];
    REP(i, 2) {
        if(d1 != c[i][0] - c[i][1] || d2 != c[i][1] - c[i][2]) return false;
    }
    return true;
}

int main() {
    REP(i, 3) {
        REP(j, 3) {
            cin >> c[i][j];
        }
    }

    cout << (judge() ? "Yes" : "No") << "\n";

    return 0;
}
