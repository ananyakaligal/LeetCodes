// Last updated: 9/16/2025, 12:02:05 AM
class Solution {
public:
    const int MOD = 1e9 + 7;

    // Recursive modular exponentiation
    long long modPow(long long base, long long exp, int mod) {
        if (exp == 0) return 1;  // Base case: x^0 = 1

        long long half = modPow(base, exp / 2, mod);  // Recursive call
        half = (half * half) % mod;  // Square the result

        return (exp % 2 == 0) ? half : (half * base) % mod;  // If odd, multiply by base
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // Number of even-indexed places
        long long oddCount = n / 2;         // Number of odd-indexed places

        long long evenWays = modPow(5, evenCount, MOD); // 5^(evenCount) % MOD
        long long oddWays = modPow(4, oddCount, MOD);   // 4^(oddCount) % MOD

        return (evenWays * oddWays) % MOD;
    }
};
