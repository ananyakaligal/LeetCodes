# Last updated: 9/16/2025, 12:09:53 AM
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        x=int(''.join(map(str, digits)))
        y=str(x+1)
        z=[int(i) for i in y]
        return z
        