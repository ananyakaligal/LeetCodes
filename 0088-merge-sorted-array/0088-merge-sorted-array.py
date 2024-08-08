class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        nums1[:] = filter(lambda x: x != 0, nums1)
        nums1.extend(nums2)
        diff=(m+n)-len(nums1)
        nums1.extend([0]*diff)
        nums1.sort()

        