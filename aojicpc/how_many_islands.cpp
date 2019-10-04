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

#define MAX_H 50
#define MAX_W 50

int h, w;
bool is_land[MAX_H][MAX_W] = { false };

int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

inline bool is_in_range(const int y, const int x) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

void dfs(const int y, const int x) {
    is_land[y][x] = false;
    REP(i, 8) {
        int nx = x + dx[i], ny = y + dy[i];
        if(is_in_range(ny, nx) && is_land[ny][nx]) dfs(ny, nx);
    }
}

int main() {
    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        REP(j, h) {
            REP(i, w) {
                int c;
                cin >> c;
                is_land[j][i] = (c == 1);
            }
        }
        int ans = 0;
        REP(j, h) {
            REP(i, w) {
                if(is_land[j][i]) {
                    dfs(j, i);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
