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

int main() {
    str s, t, u;
    ll k, cnt = 0, cnt_2 = 0, cnt_3 = 0;
    cin >> s >> k;
    int len = s.length();
    t = s + s;
    u = t + s;
    FOR(i, 1, len) {
        if(s[i] == s[i - 1]) {
            cnt++;
            s[i] = '0';
        }
    }
    FOR(i, 1, t.length()) {
        if(t[i] == t[i - 1]) {
            cnt_2++;
            t[i] = '0';
        }
    }
    FOR(i, 1, u.length()) {
        if(u[i] == u[i - 1]) {
            cnt_3++;
            u[i] = '0';
        }
    }
    DBG(cnt);
    DBG(cnt_2);
    DBG(cnt_3);
    cout << (cnt_3 - cnt_2 != cnt_2 - cnt ? cnt_2 * (k / 2) + cnt * (k % 2) : cnt + (cnt_2 - cnt) * (k - 1)) << "\n";

    return 0;
}