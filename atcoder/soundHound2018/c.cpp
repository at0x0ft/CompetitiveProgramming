#include <bits/stdc++.h>
    
using namespace std;
    
bool median(vector<int> *A, int length, int *ans) {
    sort((*A).begin(), (*A).end());
    if(length % 2 == 0) {
        *ans = ((*A)[length / 2] + (*A)[length / 2 - 1]) / 2.0;
        return false;
    }
    else {
        *ans = (*A)[length / 2];
        return true;
    }
}

int main() {
    int N, cnd, med;
    long long int ans1 = 0, ans2 = 0;

    scanf("%d %d %d", &n, &m, &d);
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin>>A[i];
        A[i] -= i + 1;
    }

    if(!median(&A, N, &med)) {
        for(int i = 0; i < N; i++) {
            ans1 += abs(A[i] - med);
            ans2 += abs(A[i] - med - 1);
        }
        if(ans1 > ans2) {
            ans1 = ans2;
        }
    }
    else {
        for(int i = 0; i < N; i++) {
            ans1 += abs(A[i] - med);
        }
    }

    printf("%lld\n", ans1);

    return 0;
}