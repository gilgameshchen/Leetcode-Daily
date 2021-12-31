# leetcode 507   [完美数](https://leetcode-cn.com/problems/perfect-number/)

## 题目

对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。

给定一个 整数 n， 如果是完美数，返回 true，否则返回 false

## 思路

遍历从2到sqrt(num)的所有数，把能够整除的加上即可。

## 代码

```c++
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if (num == 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                sum = sum + i + num / i;
            }
        }
        if (sum == num - 1) {
            return true;
        } else {
            return false;
        }
    }
};
```



