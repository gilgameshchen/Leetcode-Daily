"""
在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。

给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。

重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。

如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

 

示例 1：

输入：mat = [[1,2],[3,4]], r = 1, c = 4
输出：[[1,2,3,4]]

示例 2：

输入：mat = [[1,2],[3,4]], r = 2, c = 4
输出：[[1,2],[3,4]]

 

提示：

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 100
    -1000 <= mat[i][j] <= 1000
    1 <= r, c <= 300

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reshape-the-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import List


class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
        if m * n != r * c:
            return mat
        outlist = [[0 for _1 in range(c)] for _2 in range(r)]
        x, y = 0, 0
        for i in range(m):
            for j in range(n):
                outlist[x][y] = mat[i][j]
                y += 1
                if y == c:
                    x += 1
                    y = 0
        return outlist


testlist = [[1, 2], [3, 4]]
r, c = 1, 4
S = Solution()
print(S.matrixReshape(testlist, r, c))
