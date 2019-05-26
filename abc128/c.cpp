#include <bits/stdc++.h>
#define FOR(i, s, g) for(int i = s; i < g; i++)
#define FORR(i, s, g) for(int i = s - 1; i >= g; i--)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n, 0)
#define ALL(v) v.begin(), v.end()
#define DMP(a) std::cerr << "[Debug] : " << #a << " = " << a << "\n"
using namespace std;
typedef long long ll;
struct aaa{
    aaa(){
        std::cin.tie(0); std::ios::sync_with_stdio(0); std::cout<<std::fixed<<std::setprecision(20);
    };
}aaaaaaa;

bool cmp(const pair<vector<int>, int> &a, const pair<vector<int>, int> &b) {
    return a.first.size() < b.first.size();
}

#define MAX_N 10
int n;
int mat[MAX_N][MAX_N];

int main() {
    int m;
    cin >> n >> m;
    vector<int> s(n, 0);
    auto cmp = [](pair<set<int>, int> &l, pair<set<int>, int> &r) { return l.first.size() > r.first.size(); };
    priority_queue<pair<set<int>, int>, vector<pair<set<int>, int>>, decltype(cmp)> c;
    REP(i, m) {
        int k;
        cin >> k;
        REP(j, k) {
            int tc;
            cin >> tc;
            c[i].first.push_back(tc);
        }
    }
    vector<int> p(m);
    REP(i, m) {
        cin >> p[i];
    }

    while(!c.empty()) {
        auto ct = c.top();
        c.pop();
        for(int i = 0; ct.first.size()
    }

    cout << (r >= l ? r - l + 1 : 0) << "\n";

    return 0;
}
