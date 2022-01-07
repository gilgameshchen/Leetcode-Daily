"""
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

 

提示：

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])
        outlist = [matrix[0][0]]
        matrix[0][0] = 101
        x, y = 0, 0
        direction = 0
        for _ in range(m * n + 4 * m + 4 * n):
            print(x, y, direction)
            if direction == 0:  # right
                if y + 1 in range(n):
                    if matrix[x][y + 1] != 101:
                        outlist.append(matrix[x][y + 1])
                        matrix[x][y + 1] = 101
                        y += 1
                    else:
                        direction = 1
                else:
                    direction = 1

            elif direction == 1:  # down
                if x + 1 in range(m):
                    if matrix[x + 1][y] != 101:
                        outlist.append(matrix[x + 1][y])
                        matrix[x + 1][y] = 101
                        x += 1
                    else:
                        direction = 2
                else:
                    direction = 2

            elif direction == 2:  # left
                if y - 1 in range(n):
                    if matrix[x][y - 1] != 101:
                        outlist.append(matrix[x][y - 1])
                        matrix[x][y - 1] = 101
                        y -= 1
                    else:
                        direction = 3
                else:
                    direction = 3

            elif direction == 3:  # up
                if x - 1 in range(m):
                    if matrix[x - 1][y] != 101:
                        outlist.append(matrix[x - 1][y])
                        matrix[x - 1][y] = 101
                        x -= 1
                    else:
                        direction = 0
                else:
                    direction = 0

        return outlist


testlist = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
S = Solution()
print(S.spiralOrder(testlist))
