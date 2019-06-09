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

bool cmp(const pair<pair<string, int>, int> &a, const pair<pair<string, int>, int> &b)
{
    if(a.first.first != b.first.first) return a.first.first < b.first.first;
    else return a.first.second > b.first.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<pair<string, int>, int>> v(n);
    REP(i, n) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i + 1;

    }
    sort(ALL(v), cmp);
    REP(i, n) cout << v[i].second << "\n";

    return 0;
}
