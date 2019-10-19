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

#define MAX_SIZE 9
int t[MAX_SIZE][MAX_SIZE];

inline bool is_in_range(const int n) {
    return 0 <= n && n < MAX_SIZE;
}

pii make_direction(pii &c, const char d) {
    switch(d) {
        case 'R': {
            c.second++;
            break;
        }
        case 'L': {
            c.second--;
            break;
        }
        case 'U': {
            c.first--;
            break;
        }
        case 'D': {
            c.first++;
            break;
        }
    }
    return c;
}

inline pii turn(const int ny, const int nx, pii &d) {
    if(!is_in_range(ny)) d.first = -d.first;
    if(!is_in_range(nx)) d.second = -d.second;
    return d;
}

int main() {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    str bd;
    cin >> bd;
    pii c(0, 0);
    REP(i, bd.length()) {
        c = make_direction(c, bd[i]);
    }
    REP(j, MAX_SIZE) {
        REP(i, MAX_SIZE) {
            char c;
            cin >> c;
            t[j][i] = c - '0';
        }
    }
    REP(i, 4) {
        cout << t[y][x];
        int ny = y + c.first, nx = x + c.second;
        c = turn(ny, nx, c);
        ny = y + c.first, nx = x + c.second;
        y = ny, x = nx;
    }
    cout << "\n";

    return 0;
}
