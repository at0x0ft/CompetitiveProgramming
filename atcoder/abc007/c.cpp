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

#define MAX_R 50
#define MAX_C 50
int r, c;
char f[MAX_R][MAX_C];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

inline bool is_in_range(const int y, const int x) {
    return 0 <= y && y < r && 0 <= x && x < c;
}

int bfs(const int sy, const int sx, const int gy, const int gx) {
    queue<pair<pii, int> > que;
    que.push(make_pair(make_pair(sy, sx), 0));
    f[sy][sx] = '#';
    while(!que.empty()) {
        pii coor = que.front().first;
        int step = que.front().second;
        step++;
        que.pop();
        REP(i, 4) {
            int ny = coor.first + dy[i], nx = coor.second + dx[i];
            if(is_in_range(ny, nx)) {
                if(ny == gy && nx == gx) return step;
                else if(f[ny][nx] == '.') {
                    f[ny][nx] = '#';
                    que.emplace(make_pair(make_pair(ny, nx), step));
                }
            }
        }
    }
    return -1;
}

int main() {
    int sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    REP(j, r) {
        REP(i, c) {
            cin >> f[j][i];
        }
    }

    cout << bfs(sy, sx, gy, gx) << "\n";

    return 0;
}
