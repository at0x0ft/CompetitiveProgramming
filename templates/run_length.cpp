#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(ll i = ((ll) a); i < ((ll) n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define MP make_pair
typedef long long ll;
typedef string str;


// 文字列sをランレングス圧縮し, 結果のpair-vectorを返す;
// pair : pair.first = 文字 : char, pair.second = 出現回数 : int
// 計算量 : O(|S|)
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


#define DBG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
// AtCoder ABC 143 C Slimes
// URL: https://atcoder.jp/contests/abc143/tasks/abc143_c
int main() {
    int n;
    cin >> n;
    str s;
    cin >> s;
    auto v = run_length(s);
    
    for(auto i : v) {
        DBG(i.first);
        DBG(i.second);
    }

    cout << v.size() << "\n";
    return 0;
}
