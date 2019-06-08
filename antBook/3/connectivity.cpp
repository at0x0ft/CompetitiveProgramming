#include <bits/stdc++.h>
#define FOR(i, s, g) for(int i = s; i < g; i++)
#define FORR(i, s, g) for(int i = s - 1; i >= g; i--)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n, 0)
#define ALL(v) v.begin(), v.end()
#define DMP(a) std::cerr << "[Debug] : " << #a << " = " << a << "\n"
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
    vi _par;
    vi _rank;
public:
    UnionFind(const int n);
    int find(const int n);
    void unite(int x, int y);
    bool same(const int x, const int y);
};

UnionFind::UnionFind(const int n) {
    REP(i,n) {
        _par.push_back(i);
        _rank.push_back(0);
    }
}

int UnionFind::find(const int x) {
    if(_par[x] == x) return x;
    else return _par[x] = find(_par[x]);
}

void UnionFind::unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(_rank[x] < _rank[y]) _par[x] = y;
    else {
        _par[y] = x;
        if(_rank[x] == _rank[y]) _rank[x]++;
    }
}

bool UnionFind::same(const int x, const int y) {
    return find(x) == find(y);
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
        p[i].first = ufr.find(i);
        p[i].second = ufl.find(i);
        ans[p[i]]++;
    }
    REP(i, n) {
        if(i != n - 1) cout << ans[p[i]] << " ";
        else cout << ans[p[i]] << "\n";
    }

    return 0;
}
