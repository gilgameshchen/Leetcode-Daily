# leetcode 1995   [统计特殊四元组](https://leetcode-cn.com/problems/count-special-quadruplets/)

## 题目

给你一个 下标从 0 开始 的整数数组 nums ，返回满足下述条件的 不同 四元组 (a, b, c, d) 的 数目 ：

> nums[a] + nums[b] + nums[c] == nums[d] ，且
> a < b < c < d

## 思路

一开始以为没有下标大小要求，即遍历所有的三元组之和，导致结果错误

发现有下标要求后，求解的复杂度降低了不少

基本解法是使用hash表存储三元组的和，然后每遍历到一个新的元素都在表中查找，如果存在对应的值，就进行计数，否则不做处理。

在个人的解法中还使用一个列表保存二元组的值，方便三元组和的计算（实际证明不仅浪费了空间，在时间降低效果上没有明显改进，可舍弃）

## 代码

```c++
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        // 题目中还有一个要求就是a<b<c<d
        // nums[a] + nums[b] + nums[c] = nums[d]
        // 保存所有的二元组的和（列表）
        // 保存所有的三元组的和（字典）
        unordered_map<int, int> dict;
        int tmp, n = nums.size(), ans = 0;
        vector<int> couple;
        for (int i = 1; i < n; i++) {
            if (dict.count(nums[i])) {
                ans += dict[nums[i]];
            }
            // 更新三元组的组合
            for (int j = 0; j < couple.size(); j++) {
                tmp = nums[i] + couple[j];
                if (!dict.count(tmp)) {
                    dict[tmp] = 1;
                } else {
                    dict[tmp]++;
                }
            }
            // 更新二元组列表
            for (int j = 0; j < i; j++) {
                tmp = nums[i] + nums[j];
                couple.push_back(tmp);
            }
        }
        return ans;
    }
};
```



