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

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    REP(i, n) {
        int a;
        cin >> a;
        pq.push(a);
    }

    vector<pair<int, int>> bc(m);
    REP(i, m) {
        cin >> bc[i].second >> bc[i].first;
    }
    sort(ALL(bc), greater<pair<int, int>>());

    REP(i, m) {
        for(; bc[i].second > 0; (bc[i].second)--) {
            int t = pq.top();
            if(t >= bc[i].first) goto END;
            pq.pop();
            pq.push(bc[i].first);
        }
    }

END:
    ll sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << "\n";

    return 0;
}
