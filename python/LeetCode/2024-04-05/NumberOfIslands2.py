from typing import *


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited = [[0] * len(grid[0]) for _ in range(len(grid))]
        dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]

        def dfs(x: int, y: int):
            visited[x][y] = 1
            for i in range(len(dx)):
                nx, ny = x + dx[i], y + dy[i]
                if nx < 0 or nx >= len(grid) or ny < 0 or ny >= len(grid[x]):
                    continue
                if grid[nx][ny] == '0' or visited[nx][ny]:
                    continue
                dfs(nx, ny)

        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == '0' or visited[i][j]:
                    continue
                dfs(i, j)
                count += 1

        return count


print(Solution().numIslands([
    ["1", "1", "1", "1", "0"],
    ["1", "1", "0", "1", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "0", "0", "0"]
]))
