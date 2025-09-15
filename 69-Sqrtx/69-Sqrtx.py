# Last updated: 9/16/2025, 12:09:56 AM
class Solution:
    def mySqrt(self, x: int) -> int:
        if x<=1:
            return x
        i=1
        z=i*i
        while z<=x:
            i+=1
            z=i*i
        return i-1   

              
        