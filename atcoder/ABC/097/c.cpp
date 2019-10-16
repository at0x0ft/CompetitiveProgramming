#include <bits/stdc++.h>

using namespace std;

void addSubStr(vector<string> *v, set<string> *st, string *S, int loc)
{
    string sbs;
    for (int i = 1; i <= 5 && i <= (*S).length() - loc; i++)
    {
        sbs = (*S).substr(loc, i);
        if ((*st).find(sbs) == (*st).end())
        {
            (*v).push_back(sbs);
            (*st).insert(sbs);
        }
    }
}

int main()
{
    int K;
    string S;

    cin >> S;
    scanf("%d", &K);

    vector<string> v;
    set<string> st;
    int size = 0;
    string sbs;
    for (char c = 'a'; c <= 'z'; c++)
    {
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == c)
            {
                addSubStr(&v, &st, &S, i);
            }
        }

        if (st.size() > 5)
        {
            break;
        }
    }

    sort(v.begin(), v.end());

    cout << v[K - 1] << "\n";

    return 0;
}
