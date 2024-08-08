class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        newarr = []
        intervals.sort(key=lambda x: x[0])

        for x in intervals:
            if not newarr or newarr[-1][1] < x[0]:
                newarr.append(x)
            else:
                newarr[-1][1] = max(newarr[-1][1], x[1])

        return newarr