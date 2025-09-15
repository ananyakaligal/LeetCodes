# Last updated: 9/16/2025, 12:05:38 AM
class Solution:
    def calPoints(self, operations: List[str]) -> int:
        res=[]
        for i in operations:
            if i=='C':
                res.pop()
            elif i=='D':
                res.append(int(res[-1])*2)
            elif i=='+':
                res.append(int(res[-1])+int(res[-2]))
            else:
                res.append(i)
        ans=0
        for i in res:
            ans+=int(i)
        return ans