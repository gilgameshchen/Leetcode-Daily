"""
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

 

示例 1：

输入：nums = [1,2,0]
输出：3

示例 2：

输入：nums = [3,4,-1,1]
输出：2

示例 3：

输入：nums = [7,8,9,11,12]
输出：1

 

提示：

    1 <= nums.length <= 5 * 105
    -231 <= nums[i] <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


"""
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        mynums = [0] * (2 ** 31 - 1)
        for num in nums:
            if num < 0:
                continue
            else:
                mynums[num] = 1
        for mynum in mynums:
            if mynums[mynum] == 0:
                return mynum
"""


from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        Maxnum = 2 ** 32
        nums.append(0) # 鸵鸟
        lennums = len(nums)

        for i, num in enumerate(nums):
            if num <= 0:
                nums[i] = Maxnum
            if num % Maxnum > lennums:
                nums[i] = Maxnum

        for i, num in enumerate(nums):
            nums[num % Maxnum - 1] += Maxnum

        for i, num in enumerate(nums):
            if num <= Maxnum:
                return i + 1
        return lennums


llist = []
llist.append([-1])
llist.append([-1, 1])
llist.append([1, 2, 0, 0])
llist.append([1, 2, 0])
llist.append([1, 2])
llist.append([1])

S = Solution()
for i in range(len(llist)):
    tmplist = llist.pop()
    print("\n", tmplist)
    print(S.firstMissingPositive(tmplist))
