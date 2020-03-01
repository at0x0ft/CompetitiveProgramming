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

map<char, int> union_map(const map<char, int> &m1, const map<char, int> &m2) {
    map<char, int> m = m1;
    for(auto p : m2) {
        m[p.first] += p.second;
    }
    return m;
}

struct SegT {
private:
    int _n;
    vector<map<char, int>> _node;

public:
    SegT(str s) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        int sz = s.length();
        _n = 1;
        while(_n < sz) _n *= 2;
        _node.resize(2 * _n - 1, map<char, int>());

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        REP(i, sz) _node[i + _n - 1][s[i]]++;
        REPR(i, _n - 1) _node[i] = union_map(_node[2 * i + 1], _node[2 * i + 2]);
    }

    void update(int x, char val) {
        // 最下段のノードにアクセスする
        x += (_n - 1);

        // 消す
        _node[x].clear();
        // 最下段のノードを更新したら、あとは親に上って更新していく
        _node[x][val]++;
        while(x > 0) {
            x = (x - 1) / 2;
            _node[x] = union_map(_node[2 * x + 1], _node[2 * x + 2]);
        }
    }

    int get_sort(int a, int b, int k = 0, int l = 0, int r = -1) {
        // 最初に呼び出されたときの対象区間は [0, n)
        if(r < 0) r = _n;

        // 要求区間と対象区間が交わらない -> 適当に返す
        if(r <= a || b <= l) return 0;

        // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
        if(a <= l && r <= b) return _node[k].size();

        // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
        // 左側の子を vl ・ 右側の子を vr としている
        // 新しい対象区間は、現在の対象区間を半分に割ったもの
        int vl = get_sort(a, b, 2*k+1, l, (l+r)/2);
        int vr = get_sort(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main() {
    int n, q;
    str s;
    cin >> n >> s >> q;
    SegT st(s);
    REP(i, q) {
        int d;
        cin >> d;
        if(d == 1) {
            int i;
            char c;
            cin >> i >> c;
            st.update(i, c);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << st.get_sort(l, r) << "\n";
        }
    }
    return 0;
}
