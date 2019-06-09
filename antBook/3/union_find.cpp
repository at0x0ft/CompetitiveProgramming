#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i = ((ll) a); i < ((ll) n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;
typedef long long ll;
typedef vector<long long> vll;

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
