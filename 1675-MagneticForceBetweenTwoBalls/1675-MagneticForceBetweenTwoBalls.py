# Last updated: 9/16/2025, 12:02:53 AM
class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        n = len(position)
        
        def canPlaceBalls(min_dist):
            count = 1  # Place the first ball in the first basket
            last_position = position[0]
            
            for i in range(1, n):
                if position[i] - last_position >= min_dist:
                    count += 1
                    last_position = position[i]
                    if count == m:
                        return True
            return False
        
        low, high = 1, position[-1] - position[0]
        best = 0
        
        while low <= high:
            mid = (low + high) // 2
            if canPlaceBalls(mid):
                best = mid  # We can place all balls with at least `mid` distance
                low = mid + 1
            else:
                high = mid - 1
        
        return best
