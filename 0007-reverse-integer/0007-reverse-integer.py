class Solution:
    def reverse(self, x: int) -> int:
        if x>=0:
            SNum=str(x)
            rev_SNum=int(SNum[::-1])
        else:
            SNum=str(abs(x))
            rev_SNum= -int(SNum[::-1]) 

        if rev_SNum>((2**31)-1) or rev_SNum<(-(2**31)):
            return 0
        else:
            return rev_SNum    

        

        