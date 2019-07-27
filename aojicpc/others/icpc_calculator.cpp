#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, n) for(ll i = ((ll) a); i < ((ll) n); ++i)
#define FORR(i, s, g) for(ll i = ((ll)s - 1); i >= ((ll) g); --i)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n, 0)

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SORTALL(v) sort(ALL(v))
#define SZ(a) int((a).size())
#define CLR(a) memset((a), 0, sizeof(a))
#define EACH(i, c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s, e) ((s).find(e)!=(s).end())

#define DMP(x) cerr << #x << " = " << (x) << endl
#define DBG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

struct aaa{
    aaa() {
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
}aaaaaaa;

inline bool is_num(const char c) {
    return c >= '0' && c <= '9';
}

pair<int, char> unpack(const string input) {
    int cnt = 0;
    while(input[cnt] == '.') {
        cnt++;
    }
    char c;
    if(is_num(input[cnt])) c = input[cnt];
    else {
        c = input[cnt];
        cnt++;
    }
    return make_pair(cnt, c);
}

void calc(stack<ll> &stk, const char op) {
    ll res = 0;
    switch(op) {
        case '+': {
            res = 0;
            while(!stk.empty()) {
                res += stk.top();
                stk.pop();
            }
            break;
        }
        case '*': {
            res = 1;
            while(!stk.empty()) {
                res *= stk.top();
                stk.pop();
            }
            break;
        }
        default: break;
    }
    stk.push(res);
}

void exec_op() {
    ;
}

void exec_calc(stack<char> &stk) {
    vector<int> nums;
    while(is_num(stk.top())) {
        nums.push_back(stk.top() - '0');
        stk.pop();
    }

}

ll calc_rec(const int prev_level, const vector<int, char> &exp, int &loc) {
    if(loc == -1) return 0; // atode
    else {

    }
    if(prev_level > exp[loc].first) {
        exec_calc();
    }
    else();
}

int main() {
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        vector<pair<int, char> > ops(n);
        REP(i, n) {
            string buf;
            cin >> buf;
            ops[i] = unpack(buf);
        }
        stack<ll> stk;
        stack<char> st;
        REP(i, n) {
            ;
        }
        // REPR(i, n) {
        //     if(i == 0) stk.push(ops[i].second - '0');
        //     else {
        //         int l = ops[i].first;
        //         while(l == ops[i].first) {
        //             stk.push(ops[i].second - '0');
        //             i--;
        //         }

        //     }
        // }
        ll ans = stk.top();
        stk.pop();
        cout << ans << "\n";
    }
    return 0;
}
