class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Create a dictionary to store the numbers and their indices
        nums_index={}

        #Iterate over each element
        for index,num in enumerate(nums):
            complement = target - num

            if complement in nums_index:
                return [nums_index[complement],index]

            nums_index[num] = index
        