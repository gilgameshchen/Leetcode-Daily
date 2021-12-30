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

#### [697. 数组的度](https://leetcode-cn.com/problems/degree-of-an-array/)

空间换时间，遍历3次，第一步给各元素计数，第二步寻找最大值为度数，第三步寻找所有该度数的最小子数组长度。设置`firstpos`和`lastpos`数组，记录每个数的第一次和最后一次出现的位置，两者之差加一，即为包含所有该元素子数组的长度。

```C++
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> count(50000, 0);
        vector<int> firstpos(50000, 0);
        vector<int> lastpos(50000, 0);
        int lenth = nums.size();
        int degree = 0;
        int sublenth = 50001;
        int pos;
        for(int i=0; i<lenth; i++)
        {
            pos = nums[i];
            if(!count[pos])
            {
                firstpos[pos] = i;
            }
            count[pos]++;
            lastpos[pos] = i;
        }
        for(int i=0; i<lenth; i++)
        {
            pos = nums[i];
            if(degree < count[pos])
            {
                degree = count[pos];
            }
        }
        for(int i=0; i<lenth; i++)
        {
            pos = nums[i];
            if(degree == count[pos])
            {
                if(sublenth > lastpos[pos] - firstpos[pos])
                {
                    sublenth = lastpos[pos] - firstpos[pos];
                }
            }
        }
        return sublenth + 1;
    }
};
```

#### [442. 数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)

由于`1 <= n <= lenth`，因此可以将`nums[i]`放在数组的对应位置。遍历数组，碰到一个数，就将它放在原有的位置上，如果该位置被标记为-1，说明该数字重复，将其加入到结果中；如果该位置被标记为0，说明该数字重复，但已经加入到结果中，将其跳过；否则，将该位置的数与当前遍历位置交换，标记为-1，继续循环。

```C++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0, temp, lenth=nums.size();
        vector<int> result;
        while(i < lenth)
        {
            if(nums[i] == -1 || nums[i] == 0)
            {
                i++;
                continue;
            }
            else
            {
                if(nums[nums[i] - 1] == -1)
                {
                    result.push_back(nums[i]);
                    nums[nums[i] - 1] = 0;
                    i++;
                }
                else
                {
                    temp = nums[i];
                    nums[i] = nums[temp - 1];
                    nums[temp - 1] = -1;
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
```

#### [41. 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)

法一，先排序再寻找最小未出现的正数，但复杂度为$O(nlogn)$，不符合要求；

法二，注意到最小未出现正数满足$1 \leq n \leq lenth$，因此将每个大于1且小于数组长度的正数放到原有位置上，然后扫描数组，对应位置为空标记的即为答案；

```C++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int lenth = nums.size();
        sort(nums.begin(), nums.end());
        int i=0, result=0;
        for(i=0; i<lenth&&nums[i]<0; i++);
        if(nums[lenth - 1] <= 0)
        {
            result = 1;
        }
        else if(nums[i] > 1)
        {
            result = 1;
        }
        else
        {
            for(; i<lenth-1; i++)
            {
                if(nums[i+1] - nums[i] > 1)
                {
                    result = nums[i] + 1;
                    break;
                }
            }
        }
        return (result == 0)?nums[i]+1:result;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num: nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
```

