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

#### [41. 缺失的第一个正数(*)](https://leetcode-cn.com/problems/first-missing-positive/)

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

#### [274. H 指数(*)](https://leetcode-cn.com/problems/h-index/)

先排序，如果当前H 指数为 `h` 并且在遍历过程中找到当前值 `citations[i]>h`，则说明我们找到了一篇被引用了至少 `h+1` 次的论文，所以将现有的 `h` 值加 1。继续遍历直到 `h` 无法继续增大。最后返回 `h` 作为最终答案

```C++
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] > h) {
            h++;
            i--;
        }
        return h;
    }
};
```

#### [453. 最小操作次数使数组元素相等](https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/)

除了自己外其它所有元素加一，等价于自己减一，因此，需要计算数组所有元素需要进行多少次操作能与最小元素相等。

```C++
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int i=0, min=nums[0];
        int lenth = nums.size();
        int result = 0;
        for(i=0; i<lenth; i++)
        {
            if(min > nums[i])
                min = nums[i];
        }
        for(i=0; i<lenth; i++)
        {
            result += nums[i] - min;
        }
        return result;
    }
};
```

#### [665. 非递减数列(*)](https://leetcode-cn.com/problems/non-decreasing-array/)

相当于计算给定数组的逆序数

```C++
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int lenth = nums.size();
        for (int i = 1; i < lenth; i++) {
            if (nums[i] < nums[i - 1]) 
            {
                if (i == 1 || nums[i] >= nums[i - 2]) 
                {
                    nums[i - 1] = nums[i];
                } 
                else
                {
                    nums[i] = nums[i - 1];
                }
                count ++;
            }
        }
        return count>1?false:true;
    }
};
```

#### [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/)

设置一个步长`step`记录零的数目，如果步长不为0（即存在零元素）则将之后的非零元素与前`step`个交换即可

```C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int step = 0;
        int lenth = nums.size();
        for(int i=0; i<lenth; i++)
        {
            if(nums[i] == 0)
                step++;
            else if(step == 0)
                continue;
            else
                swap(nums[i], nums[i - step]);
        }
    }
};
```

#### [118. 杨辉三角](https://leetcode-cn.com/problems/pascals-triangle/)

除了第一个和最后一个元素，三角中的元素等于它正上方和左上方两数之和（左对齐）

```C++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i=0; i<numRows; i++)
        {
            result[i].resize(i+1);
            result[i][0] = 1;
            result[i][i] = 1;
            for(int j=1; j<i; j++)
            {
                result[i][j] = result[i-1][j] + result[i-1][j-1];
            }
        }
        return result;
    }
};
```

#### [119. 杨辉三角 II(*)](https://leetcode-cn.com/problems/pascals-triangle-ii/)

利用递推公式

```C++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        row[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            row[i] = (long long)1 * row[i - 1] * (rowIndex - i + 1) / i;
        }
        return row;
    }
};
```

#### [661. 图片平滑器](https://leetcode-cn.com/problems/image-smoother/)

```python
class Solution(object):
    def imageSmoother(self, M):
        R, C = len(M), len(M[0])
        ans = [[0] * C for _ in M]

        for r in xrange(R):
            for c in xrange(C):
                count = 0
                for nr in (r-1, r, r+1):
                    for nc in (c-1, c, c+1):
                        if 0 <= nr < R and 0 <= nc < C:
                            ans[r][c] += M[nr][nc]
                            count += 1
                ans[r][c] /= count

        return ans
```

#### [598. 范围求和 II](https://leetcode-cn.com/problems/range-addition-ii/)

等价于寻找所有操作覆盖的最小行和最小列

```C++
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int opnum = ops.size();
        if(opnum == 0)
            return m * n;
        int min_m=40001, min_n=40001;
        for(int i=0; i<opnum; i++)
        {
            min_m = (ops[i][0] < min_m) ? ops[i][0] : min_m;
            min_n = (ops[i][1] < min_n) ? ops[i][1] : min_n;
        }
        return min_m * min_n;
    }
};
```

#### [419. 甲板上的战舰](https://leetcode-cn.com/problems/battleships-in-a-board/)

事实上，一条战舰的数量等于甲板上所有左边和上方都不是`X`的`X`格子的数量。

```C++
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int i=0, j=0, result=0;
        int x=board.size(), y=board[0].size();
        bool up=false, left=true;
        for(i=0; i<x; i++)
        {
            for(j=0; j<y; j++)
            {
                up = false;
                left = false;
                if(board[i][j] == 'X')
                {
                    if(i==0 || (i>0 && board[i-1][j]=='.'))
                        up = true;
                    if(j==0 || (j>0 && board[i][j-1]=='.'))
                        left = true;
                }
                result = (up && left) ? result+1 : result;
            }
        }
        return result;
    }
};
```

#### [189. 轮转数组](https://leetcode-cn.com/problems/rotate-array/)

要对序列$p_1p_2...p_n$循环右移$k$次，等价于将序列的右边$k$子序列和左边$n-k$子序列分别逆转，然后对整个序列再进行一次逆转。即

$p_1p_2...p_{n-k}\to p_{n-k}...p_2p_1$

$p_{n-k+1}...p_n\to p_n...p_{n-k+1}$

$p_{n-k}...p_2p_1p_n...p_{n-k+1}\to p_{n-k+1}...p_np_1p_2...p{n-k}$

```C
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int lenth = nums.size();
        int mid = k % lenth;
        if(mid==0)return;
        int low=0, high=lenth-mid-1;
        while(low<high)
        {
            swap(nums[low], nums[high]);
            low++;high--;
        }
        low = lenth - mid;
        high = lenth - 1;
        while(low<high)
        {
            swap(nums[low], nums[high]);
            low++;high--;
        }
        low = 0;
        high = lenth - 1;
        while(low<high)
        {
            swap(nums[low], nums[high]);
            low++;high--;
        }    
    }
};
```

#### [396. 旋转函数](https://leetcode-cn.com/problems/rotate-function/)

以`[4, 3, 2, 6]`为例，列出每轮运算的系数如下

|  4   |  3   |  2   |  6   |
| :--: | :--: | :--: | :--: |
|  0   |  1   |  2   |  3   |
|  1   |  2   |  3   |  0   |
|  2   |  3   |  0   |  1   |
|  3   |  0   |  1   |  2   |

由图可知，每一轮运算都等于上一轮结果加上数列之和，再减去系数为0的元素的`n`倍（`n`为数组长度）。即$F(i)=F(i-1)+\Sigma x_i - nx_{zero}$。而每一轮运算过后，系数为零的位置往左移动一位。

```C++
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int lenth = nums.size();
        int i=0, max=0, sum=0;
        for(i=0; i<lenth; i++)
        {
            max += i * nums[i];
            sum += nums[i];
        }
        int zero_pos = lenth - 1;
        int temp = max;
        for(i=1; i<lenth; i++)
        {
            temp = temp + sum - lenth * nums[zero_pos];
            if(temp > max)
                max = temp;
            zero_pos--;
        }
        return max;
    }
};
```



