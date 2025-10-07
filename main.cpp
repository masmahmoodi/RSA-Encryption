#include <iostream>
#include <climits>      
#include <cstdlib>      
#include "RSA.h"

int main() {
    unsigned long long p, q, n, lambda, d, e, m, c;
    unsigned int seed;

    std::cout << "Enter a seed: ";
    std::cin >> seed;
    srand(seed);                 

    
    p = getPrime(UCHAR_MAX, USHRT_MAX);
    q = getPrime(UCHAR_MAX, USHRT_MAX);

    std::cout << "p: " << p << "\n";
    std::cout << "q: " << q << "\n";

    n = p * q;
    std::cout << "n: " << n << "\n";

    lambda = lcm(p - 1ULL, q - 1ULL);
    std::cout << "lambda: " << lambda << "\n";

    
    if (lambda <= 3ULL) {
        std::cerr << "lambda too small\n";
        return 1;
    }
    e = getPrime(2ULL, lambda - 1ULL);
    while (lambda % e == 0ULL) {
        e = getPrime(2ULL, lambda - 1ULL);
    }
    std::cout << "e: " << e << "\n";

    d = modInverse(e, lambda);
    std::cout << "d: " << d << "\n";

    std::cout << "Public key: n = " << n << " e = " << e << "\n";
    std::cout << "Private key: n = " << n << " d = " << d << "\n";

    std::cout << "Enter a positive number less than " << n << ":\n";
    std::cin >> m;
    if (m >= n) {
        std::cerr << "Message must be less than n.\n";
        return 1;
    }

    c = modExp(m, e, n);
    std::cout << "Cipher: " << c << "\n";

    unsigned long long decrypted = modExp(c, d, n);
    std::cout << "Decrypted cipher: " << decrypted << "\n";

    return 0;
}

