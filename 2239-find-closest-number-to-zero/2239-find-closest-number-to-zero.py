class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        diff=nums[0]

        for i in range(0,len(nums)):
            if abs(nums[i])<=abs(diff):
                diff=nums[i]
                if abs(diff) in nums:
                    diff=abs(nums[i])    

        return diff            



            


