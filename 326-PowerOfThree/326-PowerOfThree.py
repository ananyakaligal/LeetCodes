# Last updated: 9/16/2025, 12:07:00 AM
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        
        # Calculate the base-3 logarithm
        log_n_base3 = math.log(n) / math.log(3)
        
        # Convert to integer
        exponent = int(round(log_n_base3))
        
        # Calculate 3 raised to the power of this integer
        power_of_three = 3 ** exponent
        
        # Check if the result is equal to n
        return power_of_three == n

            
                