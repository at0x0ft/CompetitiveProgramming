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

#define MAX_H 1000
#define MAX_W 1000

int h, w;
char board[MAX_H][MAX_W];

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

inline bool is_in_range(const int y, const int x) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

int bfs(const pii &start, const pii &end) {
    bool visited[MAX_H][MAX_W] = { false };
    visited[start.first][start.second] = true;
    queue<pair<int, pii> > que;
    que.push(make_pair(0, start));
    while(!que.empty()) {
        int stp = que.front().first;
        pii now = que.front().second;
        que.pop();
        REP(i, 4) {
            int ny = now.first + dy[i], nx = now.second + dx[i];
            if(is_in_range(ny, nx) && board[ny][nx] != 'X' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                if(ny == end.first && nx == end.second) return stp + 1;
                else {
                    que.push(make_pair(stp + 1, make_pair(ny, nx)));
                }
            }
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> h >> w >> n;
    vpii loc(n + 1);
    REP(j, h) {
        REP(i, w) {
            char c;
            cin >> c;
            if(c == 'S') {
                loc[0].first = j;
                loc[0].second = i;
            }
            else if('1' <= c && c <= '9') {
                int idx = c - '0';
                loc[idx].first = j;
                loc[idx].second = i;
            }
            board[j][i] = c;
        }
    }
    int ans = 0;
    REP(i, n) {
        ans += bfs(loc[i], loc[i + 1]);
    }
    cout << ans << "\n";

    return 0;
}
