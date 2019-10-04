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

#define SIZE 10

char a[SIZE][SIZE];
int cnt;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline bool is_in_range(const int y, const int x) {
    return 0 <= y && y < SIZE&& 0 <= x && x < SIZE;
}

void dfs(const int y, const int x, bool visited[SIZE][SIZE]) {
    visited[y][x] = true;
    REP(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if(is_in_range(ny, nx) && a[ny][nx] == 'o' && !visited[ny][nx]) dfs(ny, nx, visited);
    }
}

bool can_connect(const int y, const int x) {
    bool visited[SIZE][SIZE] = {false};
    dfs(y, x, visited);
    REP(j, SIZE) {
        REP(i, SIZE) {
            if(a[j][i] == 'o' && !visited[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool check() {
    REP(j, SIZE) {
        REP(i, SIZE) {
            if(a[j][i] == 'x' && can_connect(j, i)) return true;
        }
    }
    return false;
}

int main() {
    REP(j, SIZE) {
        REP(i, SIZE) {
            char c;
            cin >> c;
            if(c == 'o') cnt++;
            a[j][i] = c;
        }
    }
    cout << (check() ? "YES" : "NO") << "\n";

    return 0;
}
