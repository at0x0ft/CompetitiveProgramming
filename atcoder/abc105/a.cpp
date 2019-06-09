#include <bits/stdc++.h>
    
using namespace std;
    
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    printf("%d\n", n % k == 0 ? 0 : 1);
    
    return 0;
}