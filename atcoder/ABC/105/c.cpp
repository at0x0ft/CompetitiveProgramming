#include <bits/stdc++.h>

using namespace std;

void divMTwo(vector<int> *s, int n) {
    if(n == 0) return;
    else if(n != 0) {
        if(abs(n) % 2 == 1) {
            (*s).push_back(1);
            if(n < 0) n--;
        }
        else {
            (*s).push_back(0);
        }

        divMTwo(s, n / (-2));
    }
} 

int main() {
    int n;
    vector<int> a(1, 0);

    scanf("%d", &n);

    divMTwo(&a, n);

    if(n == 0) {
        printf("%d\n", n);
    }
    else {
        for(int i = a.size() - 1; i > 0; i--) {
            printf("%d", a[i]);
        }
        printf("\n");
    }

    return 0;
}