# Last updated: 9/16/2025, 12:10:18 AM
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        new_dict={}

        for word in strs:
            sort=''.join(sorted(word))

            if sort in new_dict:
                new_dict[sort].append(word) 
            else:
                new_dict[sort] = [word] 

        return list(new_dict.values())