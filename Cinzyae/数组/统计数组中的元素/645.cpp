/*
集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。

给定一个数组 nums 代表了集合 S 发生错误后的结果。

请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

 

示例 1：

输入：nums = [1,2,2,4]
输出：[2,3]

示例 2：

输入：nums = [1,1]
输出：[1,2]

 

提示：

    2 <= nums.length <= 104
    1 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-mismatch
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> errorNums(2);
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            int curr = nums[i];
            if (curr == prev)
            {
                errorNums[0] = prev;
            }
            else if (curr - prev > 1)
            {
                errorNums[1] = prev + 1;
            }
            prev = curr;
        }
        if (nums[n - 1] != n)
        {
            errorNums[1] = n;
        }
        return errorNums;
    }
};

int main()
{
    vector<int> testnums = {1, 2, 2, 4};
    Solution S;
    for (int num : S.findErrorNums(testnums))
        cout << num << " ";
    return 0;
}