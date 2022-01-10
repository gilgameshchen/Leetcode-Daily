"""
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]

示例 2：

输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

示例 3：

输入：matrix = [[1]]
输出：[[1]]

示例 4：

输入：matrix = [[1,2],[3,4]]
输出：[[3,1],[4,2]]

 

提示：

    matrix.length == n
    matrix[i].length == n
    1 <= n <= 20
    -1000 <= matrix[i][j] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        halfn = int(n / 2)
        print(halfn)
        for i in range(n):
            for j in range(halfn):
                print(i,halfn+1-j)
                matrix[i][j], matrix[i][halfn + 1 - j] = (
                    matrix[i][halfn + 1 - j],
                    matrix[i][j],
                )
        print(matrix)
        for i in range(halfn + 1):
            for j in range(halfn + 1):
                matrix[i][j], matrix[n - 1 - j][n - 1 - i] = (
                    matrix[n - 1 - j][n - 1 - i],
                    matrix[i][j],
                )
        if n / 2 == halfn:
            matrix[halfn - 1][halfn - 1], matrix[halfn][halfn] = (
                matrix[halfn][halfn],
                matrix[halfn - 1][halfn - 1],
            )
        print(matrix)


testlist = [[1,2],[3,4]]

S = Solution()
S.rotate(testlist)
# print(testlist)

'''
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for i in range(len(matrix)//2):
            for j in range(len(matrix[0])):
                matrix[i][j],matrix[len(matrix)-1-i][j] = matrix[len(matrix)-1-i][j],matrix[i][j]

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i!=j and i<j:
                    matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
'''