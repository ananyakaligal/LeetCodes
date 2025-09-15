# Last updated: 9/16/2025, 12:08:23 AM
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        n=len(nums)
        return nums[n//2]
        