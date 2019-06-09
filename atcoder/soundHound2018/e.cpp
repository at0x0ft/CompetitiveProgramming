#include <bits/stdc++.h>

using namespace std;

long long int cutSgmnt(vector<int> *A, int length, int *idx, double ave) {
    double tmp = LLONG_MAX;
    long long int sum = 0;
    for(; *idx < length; (*idx)++) {
        fprintf(stderr, "debug print : *idx = %d\n", *idx);	// 4debug
        sum += (*A)[*idx];
        if(ave >= sum && tmp > ave - sum) {
            tmp = ave - sum;
        }
        else if(ave < sum && tmp > sum - ave) {
            (*idx)++;
            return sum;
        }
        else if(ave < sum) {
            return sum - (*A)[*idx];
        }
    }
    return sum;
}

int main() {
    int N, idx;
    double ave = 0.0;

    cin>>N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin>>A[i];
        ave += A[i];
    }
    ave /= 4;
    fprintf(stderr, "debug print : ave = %lf\n", ave);	// 4debug

    vector<long long int> b(4);

    for(int i = 0; i < 4; i++) {
        b[i] = cutSgmnt(&A, N, &idx, ave);
        fprintf(stderr, "debug print : b[i] = %lld\n", b[i]);	// 4debug
    }

    sort(b.begin(), b.end());

    printf("%lld\n", b[3] - b[0]);

    return 0;
}
