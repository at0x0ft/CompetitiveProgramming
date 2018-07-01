#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    cin>>N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin>>A[i];
    }

    sort(A.begin(), A.end());

    printf("%d\n", A[N - 1] - A[0]);

    return 0;
}