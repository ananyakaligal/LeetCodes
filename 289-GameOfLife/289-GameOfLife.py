# Last updated: 9/16/2025, 12:07:11 AM
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = len(board)
        cols = len(board[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]
        
        def valid(r, c):
            return 0 <= r < rows and 0 <= c < cols

        for r in range(rows):
            for c in range(cols):
                liveCount = 0
                for dr, dc in directions:
                    newRow, newCol = r + dr, c + dc
                    if valid(newRow, newCol) and board[newRow][newCol] in {1, 2}:
                        liveCount += 1
                if board[r][c] == 1:
                    if liveCount < 2 or liveCount > 3:
                        board[r][c] = 2  # 2 means it will die
                else:
                    if liveCount == 3:
                        board[r][c] = -1  # -1 means it will become alive

        for r in range(rows):
            for c in range(cols):
                if board[r][c] == 2:
                    board[r][c] = 0  # Cell dies
                elif board[r][c] == -1:
                    board[r][c] = 1  # Cell becomes alive