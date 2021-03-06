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
using ll = long long;
using ld = long double;
using str = string;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vs = vector<str>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

// Constant variables
const ld PI = (acos(-1));
const ll MOD = 1000000007;

// I/O Asynchronizing
struct __io_async{
    __io_async(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
};

#define MAX_H 500
#define MAX_W 500
int h, w;
int a[MAX_H][MAX_W];
bool is_selected[MAX_H][MAX_W];
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };
queue<pair<pii, pii>> que;

inline bool is_in_range(const int y, const int x) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

void op() {
    REP(j, h) {
        REP(i, w) {
            if(a[j][i] % 2 == 1) {
                REP(k, 2) {
                    int ny = j + dy[k], nx = i + dx[k];
                    if(is_in_range(ny, nx)) {
                        a[j][i]--;
                        a[ny][nx]++;
                        que.push(make_pair(make_pair(j + 1, i + 1), make_pair(ny + 1, nx + 1)));
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> h >> w;
    REP(j, h) {
        REP(i, w) {
            cin >> a[j][i];
        }
    }
    op();
    cout << que.size() << endl;
    while(!que.empty()) {
        int oy = que.front().first.first, ox = que.front().first.second, ny = que.front().second.first, nx = que.front().second.second;
        que.pop();
        cout << oy << " " << ox << " " << ny << " " << nx << endl;
    }
    return 0;
}
