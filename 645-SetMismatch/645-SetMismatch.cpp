// Last updated: 9/16/2025, 12:05:41 AM
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        long long s11 = 0, s12 = 0;

        for (int i = 0; i < n; i++) {
            s11 +=1LL * nums[i];
            s12 += 1LL * nums[i] * nums[i]; // Cast here too
        }

        long long s21 = 1LL * n * (n + 1) / 2;
        long long s22 = 1LL * n * (n + 1) * (2 * n + 1) / 6;

        long long D = s11 - s21;        // y - x
        long long sqD = s12 - s22;      // y^2 - x^2

        long long sum = sqD / D;        // y + x

        long long y = (sum + D) / 2;    // duplicate
        long long x = y - D;            // missing

        return { (int)y, (int)x };
    }
};
