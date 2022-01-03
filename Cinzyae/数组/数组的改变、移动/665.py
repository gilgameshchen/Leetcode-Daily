"""
给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。

 

示例 1:

输入: nums = [4,2,3]
输出: true
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。

示例 2:

输入: nums = [4,2,1]
输出: false
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。

 

提示：

    1 <= n <= 10 ^ 4
    - 10 ^ 5 <= nums[i] <= 10 ^ 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-decreasing-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import List


"""class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        # nums.append(10 ** 5 + 1)
        flag = 0
        flag2 = 0
        mark = [-1, -1]
        nnums = [0, 0]
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                flag += 1
                # if i == 0:
                #     continue
                flag2 = 1
                nnums[0] = nums[i]
                nnums[1] = nums[i + 1]

            elif nums[i] < nums[i + 1]:
                if flag2 == 0:
                    mark[0] = nums[i]
                else:
                    mark[1] = nums[i + 1]
                    # mark[0] = nums[i + 1] if mark[0] == -1 else mark[0]
                    equal = mark[0] + mark[1]
                    print(mark[0], nnums[0], equal, nnums[1], mark[1])
                    if (2 * nnums[0] < equal) | (equal < 2 * nnums[1]) == False:
                        return False
        return True if flag <= 1 else False"""


class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        flag1 = 0
        flag2 = 0
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                flag2 += 1

                numL = nums[i]
                numR = nums[i + 1]

                nums[i] = numR
                for j in range(len(nums) - 1):
                    if nums[j] > nums[j + 1]:
                        flag1 += 1

                nums[i] = numL
                nums[i + 1] = numL
                for j in range(len(nums) - 1):
                    if nums[j] > nums[j + 1]:
                        flag1 += 1

                if flag1 > 1:
                    return False
                else:
                    flag1 = 0
                    nums[i] = numL
                    nums[i + 1] = numR

        return True if flag2 <= 1 else False


# [3,4,2,3]
# [4,2,3]
# [5,7,1,8]
# [2,3,3,2,2]
list1 = [2,3,3,2,2]

S = Solution()
print(S.checkPossibility(list1))
