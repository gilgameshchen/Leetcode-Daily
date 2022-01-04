"""
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

 

示例 1:

输入: rowIndex = 3
输出: [1,3,3,1]

示例 2:

输入: rowIndex = 0
输出: [1]

示例 3:

输入: rowIndex = 1
输出: [1,1]

 

提示:

    0 <= rowIndex <= 33


进阶：

你可以优化你的算法到 O(rowIndex) 空间复杂度吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        mylist = [1]
        numlist = [1]
        rowIndex += 1
        for i in range(1, rowIndex):
            numlist.append(numlist[i - 1] * i)
        for i in range(rowIndex):
            temp = int(numlist[rowIndex - 1] / (numlist[rowIndex - 1 - i] * numlist[i]))
            mylist.append(temp)
        mylist = mylist[1:]
        return mylist


S = Solution()
print(S.getRow(34))
