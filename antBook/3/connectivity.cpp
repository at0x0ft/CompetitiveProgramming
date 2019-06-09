#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i = ((ll) a); i < ((ll) n); ++i)
#define FORR(i, s, g) for(ll i = ((ll)s - 1); i >= ((ll) g); --i)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n, 0)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SORT_ALL(v) sort(ALL(v))
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define DMP(x)  cerr << #x << " = " << (x) << endl;
#define DBG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define CLR(a) memset((a), 0 ,sizeof(a))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<std::string> vs;
struct aaa{
    aaa(){
        std::cin.tie(0); std::ios::sync_with_stdio(0); std::cout<<std::fixed<<std::setprecision(20);
    };
}aaaaaaa;

class UnionFind {
private:
    vll _par;
    vll _rank;
public:
    UnionFind(const ll n);
    ll root(const ll n);
    bool unite(ll x, ll y);
    bool same(const ll x, const ll y);
};

UnionFind::UnionFind(const ll n) : _par(n), _rank(n, 1LL) {
    REP(i,n) _par[i] = i;
}

ll UnionFind::root(const ll x) {
    if(_par[x] == x) return x;
    else return _par[x] = root(_par[x]);
}

bool UnionFind::unite(ll x, ll y) {
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(_rank[x] < _rank[y]) _par[x] = y;
    else {
        _par[y] = x;
        if(_rank[x] == _rank[y]) _rank[x]++;
    }
    return true;
}

bool UnionFind::same(const ll x, const ll y) {
    return root(x) == root(y);
}

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    UnionFind ufr(n), ufl(n);
    REP(i, k) {
        int p, q;
        cin >> p >> q;
        ufr.unite(p - 1, q - 1);
    }
    vi a(n,1);
    REP(i, l) {
        int r, s;
        cin >> r >> s;
        ufl.unite(r - 1, s - 1);
    }

    map<pair<int, int>, int> ans;
    vector<pair<int, int>> p(n);
    REP(i, n) {
        p[i].first = ufr.root(i);
        p[i].second = ufl.root(i);
        ans[p[i]]++;
    }
    REP(i, n) {
        if(i != n - 1) cout << ans[p[i]] << " ";
        else cout << ans[p[i]] << "\n";
    }

    return 0;
}
