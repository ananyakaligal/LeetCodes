# Last updated: 9/16/2025, 12:10:04 AM
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # Create a 1D array 'dp' with all elements initialized to 1
        dp = [1] * n
    
        # Fill the dp array for each row
        for i in range(1, m):
            for j in range(1, n):
                dp[j] += dp[j-1]

        return dp[n-1]        
