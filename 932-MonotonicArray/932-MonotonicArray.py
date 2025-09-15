# Last updated: 9/16/2025, 12:04:41 AM
class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        x=True
        y=True

        for i in range(1, len(nums)):
            if not nums[i] >= nums[i - 1]:
                x= False

        for i in range(1, len(nums)):
            if not nums[i] <= nums[i - 1]:
                y= False

        return x or y