#### [485. 最大连续 1 的个数](https://leetcode-cn.com/problems/max-consecutive-ones/)

遍历数组，设置一个`temp`记录当前连续1的个数，设置一个`max`记录当前连续1最大的个数。

```C++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0,temp = 0;
        int i = 0;
        int lenth = nums.size();
        while(i<lenth)
        {
            if(nums[i])		// 8ms less than nums[i] == 1
                temp++;
            else
            {
                if(temp > max)
                    max = temp;
                temp = 0;
            }
            i++;
        }
        return temp>max?temp:max;
    }
};
```

#### [495. 提莫攻击](https://leetcode-cn.com/problems/teemo-attacking/)

遍历数组，设置一个当前终止时间`endtime`，每次将`endtime`与下一次中毒时间`timeSeries[i+1]`比较。

```C++
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result=0, i=0, endtime;
        int lenth = timeSeries.size();
        while(i<lenth)
        {
            endtime = timeSeries[i] + duration;
            if(i == lenth - 1 || timeSeries[i+1] > endtime)
            {
                result += duration;
            }
            else
            {
                result += (timeSeries[i+1] - timeSeries[i]);
            }
            i++;
        }
        return result;
    }
};
```

#### [414. 第三大的数](https://leetcode-cn.com/problems/third-maximum-number/)

设置3个变量保存前三大的数，同时设置两个有效位

```C
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int i=0, lenth=nums.size();
        bool flag2=false, flag3=false;
        int max_1 = nums[0];
        int max_2 = -2147483648;
        int max_3 = -2147483648;
        for(i=1; i<lenth; i++)
        {
            if(nums[i] > max_1)
            {
                max_3 = max_2;
                flag3 = flag2?true:false;
                max_2 = max_1;
                flag2 = true;
                max_1 = nums[i];
            }
            else if(nums[i] < max_1)
            {
                if(nums[i] > max_2 || (nums[i] == -2147483648 && flag2 == false))
                {
                    max_3 = max_2;
                    flag3 = flag2?true:false;
                    max_2 = nums[i];
                    flag2 = true;
                }
                else if(nums[i] < max_2)
                {
                    if(nums[i] > max_3 || nums[i] == -2147483648)
                    {
                        max_3 = nums[i];
                        flag3 = flag2?true:false;
                    }
                }
                else
                    continue;
            }
            else
                continue;
        }
        return flag3?max_3:max_1;
    }
};
```

#### [628. 三个数的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-three-numbers/)

只可能有两种情况：三个全正和两负一正

```C++
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int lenth = nums.size();
        int max_1 = -1001, max_2 = -1002, max_3 = -1003;
        int min_1 = 1001, min_2 = 1002;
        for(int i=0; i<lenth; i++)
        {
            // 3-max
            if(nums[i] >= max_1)
            {
                max_3 = max_2;
                max_2 = max_1;
                max_1 = nums[i];
            }
            else if(nums[i] >= max_2)
            {
                max_3 = max_2;
                max_2 = nums[i];
            }
            else if(nums[i] >= max_3)
            {
                max_3 = nums[i];
            }
            // 2-min
            if(nums[i] < min_1)
            {
                min_2 = min_1;
                min_1 = nums[i];
            }
            else if(nums[i] < min_2)
            {
                min_2 = nums[i];
            }
        }
        int result_1 = max_1 * max_2 * max_3;
        int result_2 = max_1 * min_1 * min_2;
        return result_1>result_2?result_1:result_2;
    }
};
```

#### [645. 错误的集合](https://leetcode-cn.com/problems/set-mismatch/)

空间换时间，设置一个`n`长度的向量，记录数字出现的标记

```C++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int lenth = nums.size();
        vector<bool> mark(lenth, false);
        int errnum, lostnum;
        for(int i=0; i<lenth; i++)
        {
            if(mark[nums[i] - 1])
                errnum = nums[i];
            else
                mark[nums[i] - 1] = true;
        }
        for(int i=0; i<lenth; i++)
        {
            if(!mark[i])
                lostnum = i + 1;
        }
        vector<int> result{errnum, lostnum};
        return result;
    }
};
```

