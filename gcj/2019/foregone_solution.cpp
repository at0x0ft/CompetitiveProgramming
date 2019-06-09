#include <bits/stdc++.h>

using namespace std;

bool isNotFour(const int a, const int b)
{
    return a != 4 && b != 4;
}

pair<vector<int>, vector<int>> solve(long long int n)
{
    pair<vector<int>, vector<int>> ans;
    bool bPosFlg = false;
    do
    {
        int d = n % 10;
        d += 10;
        n /= 10;
        for (int da = 1; da < 10; da++)
        {
            int db = (d - da) % 10;
            if (!bPosFlg && db == 0)
                continue;

            if (isNotFour(da, db))
            {
                ans.first.push_back(da);
                ans.second.push_back(db);
                bPosFlg = true;

                if (da + db >= 10)
                    n--;

                break;
            }
        }
    } while (n > 0);
    return ans;
}

void printAns(vector<int> &a)
{
    bool zeroShowFlg = false;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] != 0 || (a[i] == 0 && zeroShowFlg))
        {
            zeroShowFlg = true;
            printf("%d", a[i]);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        long long int n;
        scanf("%lld", &n);
        auto ans = solve(n);
        printf("Case #%d: ", i + 1);
        printAns(ans.first);
        printf(" ");
        printAns(ans.second);
        printf("\n");
    }

    return 0;
}
