# leetcode 390   [消除游戏](https://leetcode-cn.com/problems/elimination-game/)

## 题目

列表 arr 由在范围 [1, n] 中的所有整数组成，并按严格递增排序。请你对 arr 应用下述算法：

从左到右，删除第一个数字，然后每隔一个数字删除一个，直到到达列表末尾。
重复上面的步骤，但这次是从右到左。也就是，删除最右侧的数字，然后剩下的数字每隔一个删除一个。
不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
给你整数 n ，返回 arr 最后剩下的数字。

## 思路

采用双指针的方式，左指针left指向当前数组的第一个数，右指针right指向当前数组的最后一个数。

设立步长stride，表示在需要删除当前元素的情况下需要移动的距离。

设立间隔interval，大小为步长的2倍，用于之后的取模。

在奇数轮，首先必定删除的就是left，然后判断right需不需要删除，删除的条件是left和right之间是否同模于interval，即：

$$
left \ \% \ interval = right \ \% \ interval
$$
如果满足等式，那就要把左右指针都向中间移动stride，否则只移动左指针。

在偶数论，执行类似的操作，只不过必须移动的只有右指针。

## 代码

```c++
class Solution {
public:
    int lastRemaining(int n) {
        // 采用双指针
        int left = 1, right = n;
        int round = 0, stride = 1, interval = stride * 2;
        while (left < right) {
            // 从左边开始
            if (round % 2 == 0) {
                if (right % interval == (left % interval)) {
                    right -= stride;
                }
                left += stride;
            } else {
                if (left % interval == (right % interval)) {
                    left += stride;
                }
                right -= stride;
            }
            stride *= 2;
            interval *= 2;
            round++;
        }
        return left;
    }
};
```



