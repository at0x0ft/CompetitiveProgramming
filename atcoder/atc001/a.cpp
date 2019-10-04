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

#define MAX_H 500
#define MAX_W 500
int h, w;
char c[MAX_H][MAX_W];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

inline bool is_range(const int x, const int y) {
    return 0 <= x && x < w && 0 <= y && y < h;
}

bool dfs(const int x, const int y) {
    bool ret = false;
    c[y][x] = '#';
    REP(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if(is_range(nx, ny)) {
            if(c[ny][nx] == '.') {
                ret |= dfs(nx, ny);
            }
            else if(c[ny][nx] == 'g') return true;
        }
    }
    return ret;
}

int main() {
    cin >> h >> w;
    int sx, sy;
    REP(i, h) {
        REP(j, w) {
            cin >> c[i][j];
            if(c[i][j] == 's') {
                sy = i;
                sx = j;
            }
        }
    }

    cout << (dfs(sx, sy) ? "Yes" : "No") << endl;

    return 0;
}
