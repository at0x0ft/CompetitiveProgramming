#include <bits/stdc++.h>
#define FOR(i, s, g) for(int i = s; i < g; i++)
#define FORR(i, s, g) for(int i = s - 1; i >= g; i--)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n, 0)
#define ALL(v) v.begin(), v.end()
#define pb push_back
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

int main() {
    int n;
    cin >> n;
    vi a(n), b(n);
    vector<vi> e;
    int sum = 0;
    bool j = true;
    REP(i, n) {
        cin >> a[i];
        vi r;
        REP(j, n) {
            if(j < i) r.pb(1);
            else r.pb(0);
        }
        FOR(j, sum, a[i] + sum) {
            e.pb(r);
        }
        sum += a[i];
    }
    j &= sum == n;
    sum = 0;
    REP(i, n) {
        cin >> b[i];
        sum += b[i];
    }
    j &= sum == n;


    return 0;
}
