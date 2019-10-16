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
char s[MAX_H][MAX_W];

inline bool is_in_range(const int y, const int x) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs() {
    queue<pair<int, pii>> que;
    que.push(make_pair(0, make_pair(0, 0)));
    s[0][0] = '#';
    while(!que.empty()) {
        int cost = que.front().first;
        pii now = que.front().second;
        que.pop();
        if(now.first == h - 1 && now.second == w - 1) return cost;
        cost++;
        REP(i, 4) {
            int ny = now.first + dy[i], nx = now.second + dx[i];
            if(is_in_range(ny, nx) && s[ny][nx] == '.') {
                s[ny][nx] = '#';
                que.push(make_pair(cost, make_pair(ny, nx)));
            }
        }
    }
    return -1;
}

int main() {
    cin >> h >> w;
    int ans = h * w;
    REP(j, h) {
        REP(i, w) {
            cin >> s[j][i];
            if(s[j][i] == '#') {
                ans--;
            }
        }
    }
    int cst = bfs();
    cout << (cst == -1 ? -1 : ans - cst - 1) << "\n";

    return 0;
}
