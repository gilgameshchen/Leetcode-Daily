/*
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。

 

示例 1：

输入：[3, 2, 1]
输出：1
解释：第三大的数是 1 。

示例 2：

输入：[1, 2]
输出：2
解释：第三大的数不存在, 所以返回最大的数 2 。

示例 3：

输入：[2, 2, 3, 1]
输出：1
解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。

提示：

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/third-maximum-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for (auto num : nums)
        {
            if (num > a)
            {
                c = b;
                b = a;
                a = num;
            }
            else if (num > b && num < a)
            {
                c = b;
                b = num;
            }
            else if (num > c && num < b)
            {
                c = num;
            }
        }
        if (c == LONG_MIN)
        {
            return a;
        }
        return c;
    }
};
*/
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<>());
        int numssize = nums.size();
        for (int i = 1, diff = 1; i < numssize; ++i)
        {
            if (nums[i] != nums[i - 1] && ++diff == 3)
            { // 此时 nums[i] 就是第三大的数
                return nums[i];
            }
        }
        return nums[0];
    }
};

int main()
{
    vector<int> testnums = {3, 2, 1};
    Solution S;
    cout << S.thirdMax(testnums) << endl;
    return 0;
}