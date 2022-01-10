"""
给定一个二维矩阵 matrix，以下类型的多个请求：

    计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。

实现 NumMatrix 类：

    NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
    int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、右下角 (row2, col2) 所描述的子矩阵的元素 总和 。

 

示例 1：

输入: 
["NumMatrix","sumRegion","sumRegion","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
输出: 
[null, 8, 11, 12]

解释:
NumMatrix numMatrix = new NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)

 

提示：

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 200
    -105 <= matrix[i][j] <= 105
    0 <= row1 <= row2 < m
    0 <= col1 <= col2 < n
    最多调用 104 次 sumRegion 方法

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-2d-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import List, Match


class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        self.localmatrix = []
        self.localmatrix[:] = matrix
        self.m = len(matrix)
        self.n = len(matrix[0])
        last = 0
        for i in range(self.m):
            for j in range(self.n):
                self.localmatrix[i][j] += last
                last = self.localmatrix[i][j]
        print(self.localmatrix)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        if col1 > 0:  # col1>0
            acc = 0
            for i in range(row1, row2 + 1):
                acc += self.localmatrix[i][col2] - self.localmatrix[i][col1 - 1]
        else:
            if row1 > 0:  # col1=0,row1>0
                acc = 0
                if row1 == row2:
                    return (
                        self.localmatrix[row1][col2]
                        - self.localmatrix[row1 - 1][self.n - 1]
                    )
                else:
                    for i in range(row1, row2 + 1):
                        acc += (
                            self.localmatrix[i][col2]
                            - self.localmatrix[i - 1][self.n - 1]
                        )
            else:  # col1=0,row1=0
                acc = self.localmatrix[0][col2]
                if row2 == 1:
                    acc += self.localmatrix[1][col2] - self.localmatrix[0][self.n - 1]
                    return acc
                else:
                    for i in range(1, row2 + 1):
                        acc += (
                            self.localmatrix[i][col2]
                            - self.localmatrix[i - 1][col1 - 1]
                        )
        return acc


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)

matrix = [[7,7,0],[-4,-7,7],[-4,0,-2],[-8,-5,6]]
row1, col1, row2, col2 = [1,0,2,2]
obj = NumMatrix(matrix)
param_1 = obj.sumRegion(row1, col1, row2, col2)
print(param_1)
