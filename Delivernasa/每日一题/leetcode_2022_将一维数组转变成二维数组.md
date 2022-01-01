# leetcode 2022   [将一维数组转变成二维数组](https://leetcode-cn.com/problems/convert-1d-array-into-2d-array/)

## 题目

给你一个下标从 0 开始的一维整数数组 original 和两个整数 m 和  n 。你需要使用 original 中 所有 元素创建一个 m 行 n 列的二维数组。

original 中下标从 0 到 n - 1 （都 包含 ）的元素构成二维数组的第一行，下标从 n 到 2 * n - 1 （都 包含 ）的元素构成二维数组的第二行，依此类推。

请你根据上述过程返回一个 m x n 的二维数组。如果无法构成这样的二维数组，请你返回一个空的二维数组。

## 思路

首先判断是否满足num=m*n的需求，如果不满足的话直接返回空数组即可。

然后按照n为周期，修改tmp数组中对应的元素的值，然后将结果加入到ans数组中，没有难度。

## 代码

```c++
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int num = original.size();
        vector<vector<int>> ans;
        vector<int> tmp(n);
        if (num != m * n) {
            return ans;
        }
        tmp[0] = original[0];
        for (int i = 1; i < num; i++) {
            if (i % n == 0) {
                ans.push_back(tmp);
            }
            tmp[i % n] = original[i];
        }
        ans.push_back(tmp);
        return ans;
    }
};
```



