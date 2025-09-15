# Last updated: 9/16/2025, 12:03:41 AM
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        new_dict={'b':0,'a':0,'l':0,'o':0,'n':0}

        for char in text:
            if char in new_dict:
                new_dict[char]+=1

        return min(new_dict['b'],new_dict['a'],(new_dict['l']//2),(new_dict['o']//2),new_dict['n'])

    