#include <bits/stdc++.h>

using namespace std;
struct CinInit
{
    CinInit()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
    };
} CinInit;
typedef long long int lli;
typedef long double ld;
template <typename T>
inline void printLn(const T v) { printf("\n"); }
template <>
inline void printLn<int>(const int i) { printf("%d\n", i); }
template <>
inline void printLn<double>(const double d) { printf("%f\n", d); }
template <>
inline void printLn<char>(const char c) { printf("%c\n", c); }
template <>
inline void printLn<lli>(const lli lli) { printf("%lld\n", lli); }
template <>
inline void printLn<ld>(const ld ld) { printf("%Lf\n", ld); }
template <>
inline void printLn<std::string>(const string s) { cout << s << "\n"; }
template <typename T, typename...>
inline void printLn(const T v1, ...) { printf("\n"); }
template <>
inline void printLn<int, ...>(const int i, ...) { printf("%d\n", i); }
template <>
inline void printLn<double>(const double d) { printf("%f\n", d); }
template <>
inline void printLn<char>(const char c) { printf("%c\n", c); }
template <>
inline void printLn<lli>(const lli lli) { printf("%lld\n", lli); }
template <>
inline void printLn<ld>(const ld ld) { printf("%Lf\n", ld); }
template <>
inline void printLn<std::string>(const string s) { cout << s << "\n"; }
template <typename T>
inline void printLn(const T v) { printf("\n"); }
template <>
inline void printLn<int>(const int i) { printf("%d\n", i); }
template <>
inline void printLn<double>(const double d) { printf("%f\n", d); }
template <>
inline void printLn<char>(const char c) { printf("%c\n", c); }
template <>
inline void printLn<lli>(const lli lli) { printf("%lld\n", lli); }
template <>
inline void printLn<ld>(const ld ld) { printf("%Lf\n", ld); }
template <>
inline void printLn<std::string>(const string s) { cout << s << "\n"; }

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = ((int)(n)-1); i >= 0; i--)

#define MAX_SUM 10000

int n;
int dp[MAX_SUM];

vector<std::string> split(const string &input, char delimiter)
{
    std::istringstream stream(input);

    std::string field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter))
    {
        result.push_back(field);
    }
    return result;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // cin >> n;

    // vector<int> v(n), w(n);
    // REP(i, n)
    // {
    //     string vw;
    //     getline(cin, vw);
    //     auto vws = split(vw, ' ');
    //     v[i] = stoi(vws[0]);
    //     w[i] = stoi(vws[1]);
    // }

    // memset(dp, -1, sizeof(dp));
    // dp[0] = 0;

    // int ans = INT_MIN;
    // REP(i, n)
    // {
    //     RREP(j, sw + 1)
    //     {
    //         if (dp[j] >= 0 && isRange(w[i] + j))
    //         {
    //             dp[w[i] + j] = max(dp[j] + v[i], dp[w[i] + j]);
    //             ans = max(dp[w[i] + j], ans);
    //         }
    //     }
    // }

    double ans = 114514;
    string a("yaju");
    printLn(a);

    return 0;
}
