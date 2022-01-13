/*
给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

 

示例 1：

输入：nums = [1,2,3]
输出：6

示例 2：

输入：nums = [1,2,3,4]
输出：24

示例 3：

输入：nums = [-1,-2,-3]
输出：-6

 

提示：

    3 <= nums.length <= 104
    -1000 <= nums[i] <= 1000

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<>());
        int n = nums.size();
        return max(*(nums.begin()) * (*(nums.begin() + 1)) * (*(nums.begin() + 2)), *(nums.begin()) * (*(nums.end() - 1)) * (*(nums.end() - 2)));
        // return max(nums[0] * nums[1] * nums[2], nums[0] * nums[n - 2] * nums[n - 1]);
    }
};

int main()
{
    vector<int> testnums = {1, 2, 3, 4};
    Solution S;
    cout << S.maximumProduct(testnums) << endl;
    return 0;
}