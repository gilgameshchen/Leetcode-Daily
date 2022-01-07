"""
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

 

示例 1：

输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

示例 2：

输入：n = 1
输出：[[1]]

 

提示：

    1 <= n <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0 for i in range(n)] for j in range(n)]
        left, right, up, down = -1, n, -1, n
        x, y = 0, 0
        direction = 0
        num = 2
        matrix[0][0] = 1
        while num <= n ** 2:
        # times = 0
        # while times <= 11:
        #     times += 1
            print(x, y, num, direction)
            if direction == 0:  # right
                if y + 1 < right:
                    y += 1
                    matrix[x][y] = num
                    num += 1
                else:
                    up += 1
                    direction = 1

            elif direction == 1:  # down
                if x + 1 < down:
                    x += 1
                    matrix[x][y] = num
                    num += 1
                else:
                    right -= 1
                    direction = 2

            elif direction == 2:  # left
                if y - 1 > left:
                    y -= 1
                    matrix[x][y] = num
                    num += 1
                else:
                    down -= 1
                    direction = 3

            elif direction == 3:  # up
                if x - 1 > up:
                    x -= 1
                    matrix[x][y] = num
                    num += 1
                else:
                    left += 1
                    direction = 0

        return matrix


S = Solution()
print(S.generateMatrix(3))
