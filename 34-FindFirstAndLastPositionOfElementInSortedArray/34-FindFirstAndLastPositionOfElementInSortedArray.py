# Last updated: 9/16/2025, 12:10:35 AM
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l=[]
        for i in range(len(nums)):
            if target==nums[i]:
                l.append(i)
                break
        if len(l) == 0:
            l.append(-1)    
        x=len(nums)-1
        while x>=0:
            if target==nums[x]:
                l.append(x)
                break
            x-=1
        if len(l) == 1:
            l.append(-1)        
        return l         
