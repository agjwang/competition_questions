class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        cur = 0
        temp = 0

        for y in range(0, (n + 1) / 2):
            for x in range(y, (n - y + 1) / 2):
                temp = matrix[y][x]
                matrix[y][x] = matrix[n - x - 1][y]
                matrix[n - x - 1][y] = matrix[n - y - 1][n - x - 1]
                matrix[n - y - 1][n - x - 1] = matrix[x][n - y - 1]
                matrix[x][n - y - 1] = temp