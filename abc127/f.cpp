#include <bits/stdc++.h>
#define FOR(i, s, g) for(int i = s; i < g; i++)
#define FORR(i, s, g) for(int i = s - 1; i >= g; i--)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n, 0)
#define ALL(v) v.begin(), v.end()
#define DMP(a) std::cerr << #a << " = " << std::a << "\n"
using namespace std;
typedef long long ll;
struct aaa{
    aaa(){
        std::cin.tie(0); std::ios::sync_with_stdio(0); std::cout<<std::fixed<<std::setprecision(20);
    };
}aaaaaaa;

inline int mid(const int len) {
    return (len - 1) / 2;
}

int main() {
    int q;
    vector<int> v;
    ll sum = 0, b = 0;
    vector<ll> l;
    cin >> q;
    REP(i, q) {
        int op;
        cin >> op;
        switch (op)
        {
        case 1: {
            int a, tb;
            cin >> a >> tb;
            v.push_back(a);
            sum += a;
            b += tb;
            break;
            }
        case 2:
            int midx = mid(v.size());
            partial_sort(v.begin(), v.begin() + midx, v.end());
            ll pos = 0;
            REP(j, midx) pos += v[j];
            cout << v[midx] << " " << (sum - 2 * pos - v[midx] - (v.size() % 2 != 0 ? v[midx] : 0) + b) << "\n";
            break;
        }

    }

    return 0;
}
