#### [605. 种花问题](https://leetcode-cn.com/problems/can-place-flowers/)

贪心算法，在原数组头尾各加一个0，遍历数组，若该位置前后及其自己都是零，则将其置一，表示这里可以种一朵花

```python
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if n == 0:
            return True
        temp = [0] + flowerbed + [0]
        count = 0
        for i in range(1, len(temp) - 1):
            if temp[i-1] == 0 and temp[i] == 0 and temp[i+1] == 0:
                count += 1
                temp[i] = 1
            if count == n:
                return True
        return False
```

#### [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

动态规划，$前i天最大收益=max\{前i-1天最大收益，第i天价格-前i-1天最低价格\}$

`DP[i] = max( DP[i-1], prices[i] - min)`

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lenth=prices.size(), min=prices[0], max=0;
        prices[0] = 0;
        for(int i=1; i<lenth; i++)
        {
            int price = prices[i];
            prices[i] = (prices[i-1] > prices[i] - min) ? prices[i-1] : prices[i] - min;
            min = (price < min) ? price : min;
            max = (prices[i] > max) ? prices[i] : max;
        }
        return max;
    }   
};
```

#### [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

脑筋急转弯，只要今天的价格比昨天的高，就可以交易

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lenth=prices.size(), result=0;
        for(int i=0; i<lenth-1; i++)
            if(prices[i] < prices[i+1])
                result += prices[i+1] - prices[i];
        return result;
    }
};
```

#### [561. 数组拆分 I](https://leetcode-cn.com/problems/array-partition-i/)

先排序，然后从头两两分组，将较小值加入即可

```C++
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lenth=nums.size(), result=0;
        for(int i=0; i<lenth; i+=2)
            result += nums[i];
        return result;
    }
};
```

#### [455. 分发饼干](https://leetcode-cn.com/problems/assign-cookies/)

先排序，尽可能用小饼干满足胃口小的孩子

```C++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0, j=0, glen=g.size(), slen=s.size(), result=0;
        while(i<glen && j<slen)
        {
            if(g[i] <= s[j])
            {
                i++;
                j++;
                result++;
            }
            else
                j++;
        }
        return result;
    }
};
```

#### [575. 分糖果](https://leetcode-cn.com/problems/distribute-candies/)

假设有`n`个糖果，`m`种类型，则结果为`min(n/2, m)`

```C++
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> candy_set(candyType.begin(), candyType.end());
        return min(candy_set.size(), candyType.size()/2);
    }
};
```

#### [135. 分发糖果](https://leetcode-cn.com/problems/candy/)

从左到右扫描，碰到上升的糖果数为前一个加一；

从右到左扫描，同理

结果为相同位置的较大值之和

```C++
class Solution {
public:
    int candy(vector<int>& ratings) {
        int lenth=ratings.size(), result=0;
        vector<int> left(lenth, 1);
        vector<int> right(lenth, 1);
        for(int i=1; i<lenth; i++)
            left[i] = (ratings[i] > ratings[i-1]) ? left[i-1] + 1 : 1;
        for(int i=lenth-2; i>=0; i--)
            right[i] = (ratings[i] > ratings[i+1]) ? right[i+1] + 1 : 1;
        for(int i=0; i<lenth; i++)
            result += max(left[i], right[i]);
        return result;
    }
};
```

#### [409. 最长回文串](https://leetcode-cn.com/problems/longest-palindrome/)

设置计数字典，若某个字母出现次数为偶数，可以全部用来凑成回文串；但是，在所有奇数个的字母中，只能选一个全部加入（中间位），其余的必须去掉一个

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        count = {}
        for i in s:
            if i in count:
                count[i] += 1
            else:
                count[i] = 1
        flag = False
        result = 0
        for v in count.values():
            if v % 2 == 1:
                flag = True
            result += (v // 2) * 2
        if flag:
            result += 1
        return result
```

