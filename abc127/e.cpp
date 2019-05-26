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
    char b;
    cin >> b;
    char ans;
    switch(b) {
    case 'A':
        ans = 'T';
        break;
    case 'T':
        ans = 'A';
        break;
    case 'C':
        ans = 'G';
        break;
    case 'G':
        ans = 'C';
        break;
    default:
        break;
    }

    cout << ans << "\n";

    return 0;
}
