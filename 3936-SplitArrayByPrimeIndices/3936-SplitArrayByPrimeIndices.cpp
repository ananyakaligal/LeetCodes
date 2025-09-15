// Last updated: 9/16/2025, 12:00:35 AM
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(n, true);

        if (n > 0) isPrime[0] = false;
        if (n > 1) isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        long long sumA = 0, sumB = 0;

        for (int i = 0; i < n; i++) {
            if (isPrime[i]) sumA += nums[i];
            else sumB += nums[i];
        }

        return llabs(sumA - sumB);
    }
};
