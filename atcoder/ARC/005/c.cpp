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
bool visited[MAX_H][MAX_W] = { false };

inline bool is_in_range(const int y, const int x) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

priority_queue<pair<int, pii>> pq;

bool bfs() {
    while(!pq.empty()) {
        int rest = pq.top().first, y = pq.top().second.first, x = pq.top().second.second;
        pq.pop();
        visited[y][x] = true;
        if(c[y][x] == 'g') return true;
        REP(i, 4) {
            int ny = y + dy[i], nx = x + dx[i];
            if(is_in_range(ny, nx) && !visited[ny][nx]) {
                visited[ny][nx] = true;
                int n_rest = (c[ny][nx] == '#' ? rest - 1 : rest);
                if(n_rest >= 0) pq.push(make_pair(n_rest, make_pair(ny, nx)));
            }
        }
    }
    return false;
}

int main() {
    cin >> h >> w;
    REP(j, h) {
        REP(i, w) {
            cin >> c[j][i];
            if(c[j][i] == 's') pq.push(make_pair(2, make_pair(j, i)));
        }
    }
    cout << (bfs() ? "YES" : "NO") << "\n";

    return 0;
}
