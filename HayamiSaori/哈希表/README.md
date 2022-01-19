#### [217. 存在重复元素](https://leetcode-cn.com/problems/contains-duplicate/)

利用python集合

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        mark = set()
        for n in nums:
            if n in mark:
                return True
            else:
                mark.add(n)
        return False
```

#### [633. 平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers/)

双指针法，对范围$[0, \sqrt{c}]$的整数，设置两个指针`i,j`，当$i^2+j^2>c$时，`j`前移；当小于时`i`后移，当等于时返回`true`

```C++
class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=0, j=(int)sqrt(c), total;
        while(i <= j)
        {
            total = i * i;
            if(total > c - j * j)
                j--;
            else if(total < c - j * j)
                i++;
            else
                return true;
        }
        return false;
    }
};
```

#### [349. 两个数组的交集](https://leetcode-cn.com/problems/intersection-of-two-arrays/)

利用python的集合

```python
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1) & set(nums2))
```

#### [128. 最长连续序列(*)](https://leetcode-cn.com/problems/longest-consecutive-sequence/)

设置一个字典，记录每个数所在的连续区间的长度，遍历数组

* 若数已在字典中，跳过
* 否则，取出字典中相邻两个数（若不存在则算作零），计算当前连续区间长度，与最大值比较替换。并且更新两端长度

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mark = {}
        result = 0
        for n in nums:
            if n in mark:
                continue
            else:
                left = mark.get(n - 1, 0)
                right = mark.get(n + 1, 0)
                cur_len = 1 + left + right
                if cur_len > result:
                    result = cur_len
                mark[n] = cur_len
                mark[n - left] = cur_len
                mark[n + right] = cur_len
        return result
```

#### [202. 快乐数](https://leetcode-cn.com/problems/happy-number/)

设置一个集合，记录过程中产生的各位数平方和，若出现1，则返回`true`，若出现重复，则返回`false`

```python
class Solution:
    def getSum(self, n: int) -> int:
        result = 0
        while(n > 0):
            result += (n % 10) * (n % 10)
            n = n // 10
        return result
    def isHappy(self, n: int) -> bool:
        mark = set()
        temp = self.getSum(n)
        while(temp not in mark):
            mark.add(temp)
            temp = self.getSum(temp)
            if temp == 1:
                return True
        return False
```

#### [500. 键盘行](https://leetcode-cn.com/problems/keyboard-row/)

设置三个集合对应键盘的三行（注意要加上大写字母）

```python
class Solution:
    mark1 = set("qwertyuiopQWERTYUIOP")
    mark2 = set("asdfghjklASDFGHJKL")
    mark3 = set("zxcvbnmZXCVBNM")
    def Check(self, word: str) -> bool:
        flag1, flag2, flag3 = [False] * 3
        for w in word:
            if w in self.mark1:
                flag1 = True
                if flag2 or flag3:
                    return False
            elif w in self.mark2:
                flag2 = True
                if flag1 or flag3:
                    return False
            else:
                flag3 = True
                if flag1 or flag2:
                    return False
        return True

    def findWords(self, words: List[str]) -> List[str]:
        result = []
        for word in words:
            if self.Check(word):
                result.append(word)
        return result
```

#### [290. 单词规律](https://leetcode-cn.com/problems/word-pattern/)

设置一个字典保存映射关系

```python
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        reflect = {}
        mark = set()
        values = s.split(' ')
        if len(values) != len(pattern):
            return False
        for i in range(len(pattern)):
            if pattern[i] in reflect:
                if values[i] != reflect[pattern[i]]:
                    return False
            else:
                if values[i] in mark:
                    return False
                reflect[pattern[i]] = values[i]
                mark.add(values[i])
        return True
```

#### [532. 数组中的 k-diff 数对](https://leetcode-cn.com/problems/k-diff-pairs-in-an-array/)

设置两个字典，分别保存已遍历的数和k-diff数对中的较小数

```python
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0:
            return 0
        mark = set()
        diff = set()
        for n in nums:
            if (n+k) in mark:
                diff.add(n)
            if (n-k) in mark:
                diff.add(n-k)
            mark.add(n)
        return len(diff)
```

#### [205. 同构字符串](https://leetcode-cn.com/problems/isomorphic-strings/)

设置一个字典和集合

```python
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        reflect = {}
        values = set()
        if len(s) != len(t):
            return False
        for i in range(len(s)):
            if s[i] in reflect:
                if t[i] not in values:
                    return False
                elif reflect[s[i]] != t[i]:
                    return False
                else:
                    continue
            else:
                if t[i] in values:
                    return False
                else:
                    reflect[s[i]] = t[i]
                    values.add(t[i])
        return True
```

