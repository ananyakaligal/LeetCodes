// Last updated: 9/16/2025, 12:00:41 AM
class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    // Fast exponentiation
    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp) {
            if (exp % 2) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Precompute factorials and inverse factorials
    void precomputeFactorials(int n) {
        fact.resize(n + 1, 1);
        invFact.resize(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        invFact[n] = modPow(fact[n], MOD - 2); // Fermat's little theorem
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    // nCk modulo MOD
    long long comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        precomputeFactorials(n);  // n-1 is max we need

        long long res = comb(n - 1, k);             // C(n-1, k)
        res = (res * m) % MOD;                      // First element: m options
        res = (res * modPow(m - 1, n - 1 - k)) % MOD; // Remaining non-matching positions

        return res;
    }
};
