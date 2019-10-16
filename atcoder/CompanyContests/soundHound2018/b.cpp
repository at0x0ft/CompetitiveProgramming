#include <bits/stdc++.h>

using namespace std;

int main() {
    string S, a;
    int w;

    cin>>S;
    cin>>w;
    for(int i = 0; i < S.length(); i++) {
        if(i % w == 0) printf("%c", S[i]);
    }

    printf("\n");

    return 0;
}