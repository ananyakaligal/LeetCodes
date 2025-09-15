# Last updated: 9/16/2025, 12:06:48 AM
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        count_dict={}
        for char1 in magazine:
            if char1 in count_dict:
                count_dict[char1]+=1
            else:
                count_dict[char1]=1

        for char2 in ransomNote:
            if char2 in count_dict and count_dict[char2]>0:
                count_dict[char2]-=1
            else:
                return False

        return True            




        