#include <bits/stdc++.h>
    
using namespace std;
    
int main() {
    vector<int> a(3);
    for(int i = 0; i < 3; i++) {
        scanf("%d", &(a[i]));
    }
    
    sort(a.begin(), a.end());
    
    printf("%d", a[2] - a[0]);
    
    return 0;
}