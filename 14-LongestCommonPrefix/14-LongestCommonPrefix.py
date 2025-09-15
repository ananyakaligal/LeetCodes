# Last updated: 9/16/2025, 12:11:02 AM
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        min_length = min(len(s) for s in strs)
        pre = ''
        
        for i in range(min_length):
            char_at_pos = {s[i] for s in strs}
            if len(char_at_pos) == 1:
                pre += strs[0][i]  # Add the common character to the prefix
            else:
                break  # Stop if characters differ
        
        return pre