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
using ll = long long;
using ld = long double;
using str = string;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vs = vector<str>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

// Constant variables
const ld PI = (acos(-1));
const ll MOD = 1000000007;

// I/O Asynchronizing
struct __io_async{
    __io_async(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
};

vs cut_k(const str t, const int k) {
    int sslen = min(k, (int)t.length());
    vs ss(sslen);
    REP(i, sslen) {
        for(int j = 0; i + k * j < t.length(); j++) {
            ss[i] += t[i + k * j];
        }
    }
    return ss;
}

str convert(const str t) {
    str ans = "";
    REP(i, t.length()) {
        switch (t[i])
        {
        case 'r':
            ans += 'p';
            break;
        case 's':
            ans += 'r';
            break;
        case 'p':
            ans += 's';
            break;
        default:
            break;
        }
    }
    return ans;
}

vector<pair<char, int>> run_length(const str &s) {
    vector<pair<char, int>> res;

    // 前の文字列と比較するため, 1からスタートする.
    REP(i, s.length()) {
        int cnt = 1;

        // 前の文字と等しかったら等しい間だけカウントを続け, iも進める.
        // ※ s[i] == s[i + 1] としている理由は, s[i - 1] == s[i] とすると,
        //   sの末尾1文字のみが長さ位置のランレングスだった場合に,
        //   独立してif文で処理を書く必要が出てくるため, こちらの比較を採用.
        while(i + 1 < s.length() && s[i] == s[i + 1]) {
            cnt++;
            i++;
        }
        res.push_back(MP(s[i], cnt));
    }
    return res;
}

int main() {
    int n, k, r, s, p;
    str t;
    cin >> n >> k >> r >> s >> p >> t;
    auto ls = cut_k(convert(t), k);
    ll ans = 0;
    REP(i, ls.size()) {
        auto pls = run_length(ls[i]);
        REP(j, pls.size()) {
            // DBG(pls[j].first);
            // DBG(pls[j].second);
            switch (pls[j].first)
            {
            case 'r':
                ans += r * (int)((pls[j].second + 1) / 2);
                break;
            case 's':
                ans += s * (int)((pls[j].second + 1) / 2);
                break;
            case 'p':
                ans += p * (int)((pls[j].second + 1) / 2);
                break;
            default:
                break;
            }
            // DBG(ans);
        }
    }
    cout << ans << "\n";

    return 0;
}
