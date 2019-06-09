#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;

    cin>>s;
    cin>>t;
    for(int i = 0; i < s.length(); i++) {
        s.insert(s.begin(), s[s.length() - 1]);
        s.pop_back();
        if(s == t) {
            printf("Yes");
            break;
        }

        if(i == s.length() - 1) {
            printf("No");
            break;
        }
    }

    return 0;
}