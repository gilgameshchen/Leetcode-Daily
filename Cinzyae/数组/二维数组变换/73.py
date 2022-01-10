"""
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

 

示例 1：

输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]

示例 2：

输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]

 

提示：

    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -231 <= matrix[i][j] <= 231 - 1

 

进阶：

    一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
    一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
    你能想出一个仅使用常量空间的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-matrix-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import ContextManager, List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        flag = False
        x, y = -1, -1
        for i in range(m):
            if flag:
                break
            for j in range(n):
                if matrix[i][j] == 0:
                    flag = True
                    x, y = i, j
                    break
        if x < 0:
            return
        print(x, y)

        # for i in range(m):
        #     if matrix[i][y] != 0:
        #         matrix[i][y] = 1
        # for j in range(n):
        #     if matrix[x][j] != 0:
        #         matrix[x][j] = 1

        print(matrix)

        for i in range(x + 1, m):
            for j in range(n):
                if j == y:
                    continue
                elif matrix[i][j] == 0:
                    matrix[i][y] = 0
                    matrix[x][j] = 0

        print(matrix)

        for i in range(m):
            if i == x:
                continue
            if matrix[i][y] == 0:
                for k in range(n):
                    matrix[i][k] = 0
        for j in range(n):
            if j == y:
                continue
            if matrix[x][j] == 0:
                for k in range(m):
                    matrix[k][j] = 0

        for i in range(m):
            matrix[i][y] = 0
        for j in range(n):
            matrix[x][j] = 0


testlist = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
S = Solution()
S.setZeroes(testlist)
print(testlist)
