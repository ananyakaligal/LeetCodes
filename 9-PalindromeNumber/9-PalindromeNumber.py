# Last updated: 9/16/2025, 12:11:09 AM
class Solution:
    def isPalindrome(self, x: int) -> bool:
        z = x
        y = 0
        
        if x < 0:
            return False

        elif x // 10 == 0:
            return True

        else:
            while (1):
                y = (x % 10) + (y * 10)
                x = x // 10

                if x==0:
                    break
            
            if y == z:
                return True
            else:
                return False
