# Last updated: 9/16/2025, 12:07:50 AM
class Solution:
    def countPrimes(self, n: int) -> int:
        a=[0]*n
        ans=0
        for i in range(2,n):
            if a[i]:
                continue
            ans += 1
            a[i*i:n:i] = [1] * ((n-1) // i - i + 1)
        return ans
        
        