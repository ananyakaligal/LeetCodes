// Last updated: 9/16/2025, 12:01:48 AM
class Solution {
public:
    long long countLessEqual(const vector<int>& A, const vector<int>& B, long long x) {
        long long count = 0;
        int n = A.size(), m = B.size();

        for (int i = 0; i < n; ++i) {
            long long a = A[i];
            if (a == 0) {
                if (x >= 0) count += m; // 0 * b = 0 <= x
            } else if (a > 0) {
                // find largest j such that a * B[j] <= x
                int l = 0, r = m - 1, ans = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (a * 1LL * B[mid] <= x) {
                        ans = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                count += (ans + 1);
            } else { // a < 0
                // find smallest j such that a * B[j] <= x
                int l = 0, r = m - 1, ans = m;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (a * 1LL * B[mid] <= x) {
                        ans = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                count += (m - ans);
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10, high = 1e10, ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (countLessEqual(nums1, nums2, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
