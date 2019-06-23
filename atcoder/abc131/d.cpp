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
#define DMP(x)  cerr << #x << " = " << (x) << endl;
#define DBG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

// Aliases
#define PB push_back
#define MP make_pair
#define FST first
#define SND second
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<string> vs;

// I/O Asynchronizing
struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
}aaaaaaa;

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
    return x.SND == y.SND ? x.FST > y.FST : x.SND < y.SND;
}

int main() {
    int n, t = 0;
    cin >> n;
    vector<pair<int, int>> ab(n);
    REP(i, n) {
        cin >> ab[i].FST >> ab[i].SND;
    }
    sort(ALL(ab),cmp);
    bool j = true;
    REP(i, n) {
        t += ab[i].FST;
        if(t > ab[i].SND) {
            j = false;
            break;
        }
    }

    cout << (j ? "Yes" : "No") << "\n";

    return 0;
}
