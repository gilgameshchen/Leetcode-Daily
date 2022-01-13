/*
给定一个非空且只包含非负数的整数数组 nums，数组的 度 的定义是指数组里任一元素出现频数的最大值。

你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

 

示例 1：

输入：nums = [1,2,2,3,1]
输出：2
解释：
输入数组的度是 2 ，因为元素 1 和 2 的出现频数最大，均为 2 。
连续子数组里面拥有相同度的有如下所示：
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组 [2, 2] 的长度为 2 ，所以返回 2 。

示例 2：

输入：nums = [1,2,2,3,1,4,2]
输出：6
解释：
数组的度是 3 ，因为元素 2 重复出现 3 次。
所以 [2,2,3,1,4,2] 是最短子数组，因此返回 6 。

 

提示：

    nums.length 在 1 到 50,000 范围内。
    nums[i] 是一个在 0 到 49,999 范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/degree-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums[i]))
            {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
            else
            {
                mp[nums[i]] = {1, i, i};
            }
        }
        int maxNum = 0, minLen = 0;
        for (auto &[_, vec] : mp)
        {
            if (maxNum < vec[0])
            {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            }
            else if (maxNum == vec[0])
            {
                if (minLen > vec[2] - vec[1] + 1)
                {
                    minLen = vec[2] - vec[1] + 1;
                }
            }
        }
        return minLen;
    }
};

int main()
{
    vector<int> testnums = {1, 2, 2, 3, 1};
    Solution S;
    cout << S.findShortestSubArray(testnums) << endl;
    return 0;
}