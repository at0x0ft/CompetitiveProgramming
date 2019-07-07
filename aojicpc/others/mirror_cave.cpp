#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, n) for(ll i = ((ll) a); i < ((ll) n); ++i)
#define FORR(i, a, n) for(ll i = ((ll) s - 1); i >= ((ll) g); --i)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n, 0)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<string> vs;

#define BOARD_WIDTH 8

char board[BOARD_WIDTH][BOARD_WIDTH];

inline bool is_range(const int x, const int y) {
    return 0 <= x && x <= BOARD_WIDTH && 0 <= y && y <= BOARD_WIDTH;
}

bool can_put(const int x, const int y, const char c) {
    int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
    int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    bool res = false;
    REP(i, BOARD_WIDTH) {
        res |= is_range(x + dx[i], y + dy[i]) && board[x + dx[i]][y + dy[i]] != '.' && c != board[x + dx[i]][y + dy[i]];
    }
    return res;
}

int solve() {
    ;

    return 0;
}

int main() {
    REP(i, BOARD_WIDTH) {
        REP(j, BOARD_WIDTH) cin >> board[i][j];
    }

    int ans = solve();

    return 0;
}
