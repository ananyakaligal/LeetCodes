# Last updated: 9/16/2025, 12:10:21 AM
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n=len(matrix)

        for  i in range(n):
            for j in range(i+1,n):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]

        for i in range(n):
            for j in range(n//2):
                matrix[i][j],matrix[i][n-1-j]=matrix[i][n-1-j],matrix[i][j]

        