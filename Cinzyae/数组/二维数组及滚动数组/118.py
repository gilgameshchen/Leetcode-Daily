"""
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

 

示例 1:

输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

示例 2:

输入: numRows = 1
输出: [[1]]

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        else:
            mylist = [[1], [1, 1]]
            for i in range(1, numRows-1):
                rowlist = [1]
                for j in range(1, i + 1):
                    rowlist.append(mylist[i][j - 1] + mylist[i][j])
                rowlist.append(1)
                mylist.append(rowlist)
        return mylist


S = Solution()
print(S.generate(3))
