# Last updated: 9/16/2025, 12:01:16 AM
class Solution:
    def removeStars(self, s: str) -> str:
        holder = []
        for char in s:
            if char != '*':
                holder.append(char)
            else:
                holder.pop()
        return "".join(holder)