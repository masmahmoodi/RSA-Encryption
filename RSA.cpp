#include "RSA.h"
#include <cstdlib>   
#include <climits>  
#include <cmath>

bool isPrime(unsigned long long n) {
    if (n < 2ULL) return false;
    if (n % 2ULL == 0ULL) return n == 2ULL;
    for (unsigned long long i = 3ULL; i * i <= n; i += 2ULL) {
        if (n % i == 0ULL) return false;
    }
    return true;
}

unsigned long long getPrime(unsigned long long min, unsigned long long max) {
    if (min < 2ULL) min = 2ULL;
    unsigned long long range = max - min + 1ULL;

    
    while (true) {
        unsigned long long candidate = min + (static_cast<unsigned long long>(rand()) % range);
        if (isPrime(candidate)) return candidate;
    }
}

unsigned long long gcd(unsigned long long x, unsigned long long y) {
    while (y != 0ULL) {
        unsigned long long r = x % y;
        x = y;
        y = r;
    }
    return x;
}

unsigned long long lcm(unsigned long long x, unsigned long long y) {
    if (x == 0ULL || y == 0ULL) return 0ULL;
    return (x / gcd(x, y)) * y;
}

unsigned long long modInverse(unsigned long long e, unsigned long long lam) {
   
    for (unsigned long long d = 1ULL; d <= lam; ++d) {
        if (((d * e) % lam) == 1ULL) return d;
    }
    return 0ULL; 
}

unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long n) {
    unsigned long long ans = 1ULL;
    for (unsigned long long i = 0ULL; i < exp; ++i)
        ans = (ans * base) % n;
    return ans;
}
