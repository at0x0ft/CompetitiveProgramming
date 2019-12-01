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

ll n, k;

#define MAX_N 100000
int cnt[MAX_N + 1];

struct Mint {
    static constexpr ll MOD = 1000000007;

    // Constructors
    Mint() : num(1ll) {}
    Mint(ll num_) : num(num_ % MOD) {}
    Mint(const Mint& Mint) : num(Mint.num % MOD) {}
    ll get()const { return num; }

    // operator etc
    operator ll() const { return num; }
    ll operator*() { return num; }
    Mint& operator+=(const Mint& r) { (num += r.num) %= MOD; return *this; }
    Mint& operator-=(const Mint& r) { ((num += -r.num) < 0) ? (num += MOD) : num ; return *this; }
    Mint& operator*=(const Mint& r) { (num *= r.num) %= MOD; return *this; }
    Mint& operator/=(const Mint& r) { (num *= r.inv().num) %= MOD; return *this; }
    Mint& operator+=(const ll& r) { (num += r) %= MOD; return *this; }
    Mint& operator-=(const ll& r) { (num += -r + MOD) %= MOD; return *this; }
    Mint& operator*=(const ll& r) { (num *= r) %= MOD; return *this; }
    Mint& operator/=(const ll& r) { (num *= Mint(r).inv().num) %= MOD; return *this; }
    Mint operator+(const Mint& r)const { return Mint(*this) += r; }
    Mint operator-(const Mint& r)const { return Mint(*this) -= r; }
    Mint operator*(const Mint& r)const { return Mint(*this) *= r; }
    Mint operator/(const Mint& r)const { return Mint(*this) /= r; }
    Mint operator+(const ll& r)const { return *this + Mint(r); }
    Mint operator-(const ll& r)const { return *this - Mint(r); }
    Mint operator*(const ll& r)const { return *this * Mint(r); }
    Mint operator/(const ll& r)const { return *this / Mint(r); }
    Mint inv()const {
        ll a = num, b = MOD, x = 1, y = 0;
        while(b) {
            ll q = a / b;
            a -= b * q;
            swap(a, b);
            x -= y * q;
            swap(x, y);
        }
        return ((x %= MOD) < 0) ? x += MOD : x;
    }
    Mint pow(const Mint& r)const {
        ll res = 1;
        ll x = num;
        ll n = r.num;
        while (n > 0) {
            if (n & 1)res = (res * x) % MOD;
            x = (x * x) % MOD;
            n >>= 1;
        }
        return res;
    }

private:
    ll num;
    inline void swap(ll &a, ll &b)const { ll tmp = a; a = b; b = tmp; }
};
ostream& operator<<(ostream& stream, const Mint& val) { stream << val.get(); return stream; }


struct Cmb {
    static constexpr ll LIM = 2000010;
    vector<Mint> fact, inv;

    Cmb() : fact(LIM, 1), inv(LIM, 1) {
        FOR(i, 1, LIM) fact[i] = fact[i - 1] * i;
        inv[LIM - 1] = fact[LIM - 1].inv();
        FORR(i, LIM - 1, 1) inv[i] = inv[i + 1] * (i + 1);
    }

    ll calc(const ll n, const ll k) {
        if(n < k) return 0;
        return (fact[n] * inv[k] * inv[n - k]).get();
    }
};

// index が条件を満たすかどうか
bool isOK(int index, int key) {
    if (cnt[index] < key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(const int key, const int n) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = n; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    int n;
    cin >> n;
    REP(i, n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int lim = binary_search(0, MAX_N + 1);
    ll k = binary_search(3, lim), l = binary_search(2, lim), m = binary_search(1, lim);
    m -= l;
    l -= k;
    DBG(k);
    DBG(l);
    DBG(m);

    Mint a = 6, b = 2, c = 1;
    a = a.pow(k);
    b = (l > 0) ? (b.pow(l) * 3LL) : Mint(1LL);
    c = (m > 0) ? c.pow(m) * 3LL : Mint(1LL);
    cout << (a * b * c) << "\n";

    return 0;
}

/*
15
0 0 0 1 1 1 2 2 2 3 3 4 4 5 6
*/
