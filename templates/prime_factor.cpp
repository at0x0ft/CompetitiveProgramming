#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


// 整数nを素因数分解し, 分解結果のmapを返す;
// key = 素因数, value = 素因数の指数
// required : n >= 2
// 計算量 : 最悪 ~ O(2^(n/2))
map<ll, int> trial_division(ll n) {
    map<ll, int> res;
    // 2の場合のみ先行して処理 (次以降の更新効率を上げるため)
    while(n % 2 == 0) {
        res[2]++;
        n /= 2;
    }

    // 以降, 奇数のみ試し割りを行う
    for(ll factor = 3; factor * factor <= n; factor += 2) {
        while(n % factor == 0) {
            res[factor]++;
            n /= factor;
        }
    }

    // 5以上の素数の場合, 上記までに一切割り切れないため, ここでresへ追加する.
    if(n != 1) res[n] = 1;

    return res;
}


#define FOR(i,a,n) for(ll i = ((ll) a); i < ((ll) n); ++i)
#define REP(i, n) FOR(i, 0, n)
// AOJ NTL 1 A 素因数分解
// URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=jp
int main() {
    int n;
    cin >> n;
    cout << n << ":";
    for (auto i : trial_division(n)) {
        while(i.second > 0) {
            cout << " " << i.first;
            i.second--;
        }
    }
    cout << "\n";
    return 0;
}
