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

ll gcd(const ll a, const ll b) {
    if(b > a) return gcd(b, a);
    else if(b == 1) return 1;
    else if(b == 0) return a;
    else return gcd(b, a % b);
}

map<ll, int> trial_division(ll n) {
    map<ll, int> res;
    // 2の場合のみ先行して処理 (次以降の更新効率を上げるため)
    while(n % 2 == 0) {
        res[2]++;
        n /= 2;
    }

    // 以降, 奇数のみ試し割りを行う
    for(ll f = 3; f * f <= n; f += 2) {
        while(n % f == 0) {
            res[f]++;
            n /= f;
        }
    }

    // 5以上の素数の場合, 上記までに一切割り切れないため, ここでresへ追加する.
    if(n != 1) res[n] = 1;

    return res;
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    ll cnt = g > 1 ? trial_division(g).size() + 1 : 1;
    cout << cnt << "\n";

    return 0;
}
