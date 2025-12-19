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

    c = modExp(m, e, n);
    std::cout << "Cipher: " << c << "\n";

    unsigned long long decrypted = modExp(c, d, n);
    std::cout << "Decrypted cipher: " << decrypted << "\n";

    
    //  EXTRA CREDIT 
    
    

    std::cout << "\n--- Extra Credit: Brute-force cracking n ---\n";

    unsigned long long p2, q2, lambda2, d2;

    if (crackRSA(n, e, p2, q2, lambda2, d2)) {
        std::cout << "Recovered p: " << p2 << "\n";
        std::cout << "Recovered q: " << q2 << "\n";
        std::cout << "Recovered lambda: " << lambda2 << "\n";
        std::cout << "Recovered d: " << d2 << "\n";

        unsigned long long cracked = modExp(c, d2, n);
        std::cout << "Decrypted using cracked key: " << cracked << "\n";
    } else {
        std::cout << "Failed to crack RSA key.\n";
    }

    return 0;
}
