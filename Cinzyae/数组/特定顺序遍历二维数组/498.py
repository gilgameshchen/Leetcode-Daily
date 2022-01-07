"""
给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。

 

示例 1：

输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,4,7,5,3,6,8,9]

示例 2：

输入：mat = [[1,2],[3,4]]
输出：[1,2,3,4]

 

提示：

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    -105 <= mat[i][j] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diagonal-traverse
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import List


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m = len(mat)
        n = len(mat[0])
        outlist = []
        direction = False
        maxmn = m + n - 1
        for sum in range(maxmn):
            if direction:
                for i in range(sum + 1):
                    if (i < m) and (sum - i < n):
                        outlist.append(mat[i][sum - i])
            else:
                for i in range(sum + 1):
                    if (sum - i < m) and (i < n):
                        outlist.append(mat[sum - i][i])
            direction = not direction
        return outlist


testlist = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
S = Solution()
print(S.findDiagonalOrder(testlist))
