#include MOD 10e9+7

long long int add(long long int a, long long int b) {
    return (a + b) % MOD;
}

long long int sub(long long int a, long long int b) {
    return (a - b) % MOD;
}

long long int mul(long long int a, long long int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

long long int power(long long int a, long long int x) {
    if(x == 0) {
        return 1;
    }
    else if(x == 1) {
        return a % MOD;
    }
    long long int tmp = power(a, x / 2) % MOD;
    if(x % 2 == 0) {
        return tmp * tmp % MOD;
    }
    else {
        return ((tmp * tmp) % MOD) * x % MOD;
    }
}

long long int dvs(long long int a, long long int b) {
    return mul(a, power(b, MOD - 2));
}