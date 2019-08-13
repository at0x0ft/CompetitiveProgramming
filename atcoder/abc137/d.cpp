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
#define DMP(x)  cerr << #x << " = " << (x) << endl
#define DBG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

// Aliases
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// I/O Asynchronizing
struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
}aaaaaaa;

bool cmp(const pii a, const pii b) {
    return (a.first == b.first ? a.second > b.second : a.first < b.first);
}

int idx_bs(const vector<pii> &ab, const int key) {
    int l = 0, r = ab.size();
    while(abs(l - r) > 1) {
        int mid = (l + r) / 2;
        if(ab[mid].first >= key) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    return r;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pii> ab(n);
    vi a(n);
    REP(i, n) {
        cin >> ab[i].first >> ab[i].second;
        a[i] = ab[i].first;
    }
    sort(ALL(ab), cmp);
    sort(ALL(a));
    REP(i, n) {
        DBG(ab[i].first);
        DBG(ab[i].second);
    }
    auto litr = upper_bound(ALL(a), 2);
    auto up_lim = distance(a.begin(), litr);
    auto mx = max_element(ab.begin(), ab.begin() + up_lim);
    DBG(*mx);
    // ll ans = 0;
    // FOR(i, 1, m + 1) {
    //     auto max_b = get_max_ab_pair(pq_list, i);
    //     ans += max_b;
    // }

    // cout << ans << "\n";

    return 0;
}
