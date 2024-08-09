from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
    
        def spiral(matrix: List[List[int]]) -> List[int]:
            if not matrix:
                return []
            
            m, n = len(matrix), len(matrix[0])
            newarr = []

            if m == 0 or n == 0:
                return newarr

            newarr.extend(matrix[0])

            for j in range(1, m):
                newarr.append(matrix[j][n-1])

            if m > 1:
                newarr.extend(matrix[m-1][::-1][1:])

            if n > 1:
                for l in range(m-2, 0, -1):
                    newarr.append(matrix[l][0])

            new_matrix = [row[1:n-1] for row in matrix[1:m-1]]

            return newarr + spiral(new_matrix)

        return spiral(matrix)
