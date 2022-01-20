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

#### [166. 分数到小数(*)](https://leetcode-cn.com/problems/fraction-to-recurring-decimal/)

```C++
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long numeratorLong = numerator;
        long denominatorLong = denominator;
        if (numeratorLong % denominatorLong == 0) {
            return to_string(numeratorLong / denominatorLong);
        }

        string ans;
        if (numeratorLong < 0 ^ denominatorLong < 0) {
            ans.push_back('-');
        }

        // 整数部分
        numeratorLong = abs(numeratorLong);
        denominatorLong = abs(denominatorLong);
        long integerPart = numeratorLong / denominatorLong;
        ans += to_string(integerPart);
        ans.push_back('.');

        // 小数部分
        string fractionPart;
        unordered_map<long, int> remainderIndexMap;
        long remainder = numeratorLong % denominatorLong;
        int index = 0;
        while (remainder != 0 && !remainderIndexMap.count(remainder)) {
            remainderIndexMap[remainder] = index;
            remainder *= 10;
            fractionPart += to_string(remainder / denominatorLong);
            remainder %= denominatorLong;
            index++;
        }
        if (remainder != 0) { // 有循环节
            int insertIndex = remainderIndexMap[remainder];
            fractionPart = fractionPart.substr(0,insertIndex) + '(' + fractionPart.substr(insertIndex);
            fractionPart.push_back(')');
        }
        ans += fractionPart;

        return ans;
    }
};
```

#### [466. 统计重复个数(*)](https://leetcode-cn.com/problems/count-the-repetitions/)

```C++
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) {
            return 0;
        }
        int s1cnt = 0, index = 0, s2cnt = 0;
        // recall 是我们用来找循环节的变量，它是一个哈希映射
        // 我们如何找循环节？假设我们遍历了 s1cnt 个 s1，此时匹配到了第 s2cnt 个 s2 中的第 index 个字符
        // 如果我们之前遍历了 s1cnt' 个 s1 时，匹配到的是第 s2cnt' 个 s2 中同样的第 index 个字符，那么就有循环节了
        // 我们用 (s1cnt', s2cnt', index) 和 (s1cnt, s2cnt, index) 表示两次包含相同 index 的匹配结果
        // 那么哈希映射中的键就是 index，值就是 (s1cnt', s2cnt') 这个二元组
        // 循环节就是；
        //    - 前 s1cnt' 个 s1 包含了 s2cnt' 个 s2
        //    - 以后的每 (s1cnt - s1cnt') 个 s1 包含了 (s2cnt - s2cnt') 个 s2
        // 那么还会剩下 (n1 - s1cnt') % (s1cnt - s1cnt') 个 s1, 我们对这些与 s2 进行暴力匹配
        // 注意 s2 要从第 index 个字符开始匹配
        unordered_map<int, pair<int, int>> recall;
        pair<int, int> pre_loop, in_loop;
        while (true) {
            // 我们多遍历一个 s1，看看能不能找到循环节
            ++s1cnt;
            for (char ch: s1) {
                if (ch == s2[index]) {
                    index += 1;
                    if (index == s2.size()) {
                        ++s2cnt;
                        index = 0;
                    }
                }
            }
            // 还没有找到循环节，所有的 s1 就用完了
            if (s1cnt == n1) {
                return s2cnt / n2;
            }
            // 出现了之前的 index，表示找到了循环节
            if (recall.count(index)) {
                auto [s1cnt_prime, s2cnt_prime] = recall[index];
                // 前 s1cnt' 个 s1 包含了 s2cnt' 个 s2
                pre_loop = {s1cnt_prime, s2cnt_prime};
                // 以后的每 (s1cnt - s1cnt') 个 s1 包含了 (s2cnt - s2cnt') 个 s2
                in_loop = {s1cnt - s1cnt_prime, s2cnt - s2cnt_prime};
                break;
            } else {
                recall[index] = {s1cnt, s2cnt};
            }
        }
        // ans 存储的是 S1 包含的 s2 的数量，考虑的之前的 pre_loop 和 in_loop
        int ans = pre_loop.second + (n1 - pre_loop.first) / in_loop.first * in_loop.second;
        // S1 的末尾还剩下一些 s1，我们暴力进行匹配
        int rest = (n1 - pre_loop.first) % in_loop.first;
        for (int i = 0; i < rest; ++i) {
            for (char ch: s1) {
                if (ch == s2[index]) {
                    ++index;
                    if (index == s2.size()) {
                        ++ans;
                        index = 0;
                    }
                }
            }
        }
        // S1 包含 ans 个 s2，那么就包含 ans / n2 个 S2
        return ans / n2;
    }
};
```

#### [138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)

设置一个字典，保存新老节点地址的对应关系

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> reflect;
        Node *p, *temp;
        for(p=head; p!=nullptr; p=p->next)
        {
            temp = new Node(p -> val);
            reflect[p] = temp;
        }
        for(p=head; p!=nullptr; p=p->next)
        {
            temp = p -> next;
            if(temp != nullptr)
                reflect[p] -> next = reflect[temp];
            temp = p -> random;
            if(temp != nullptr)
                reflect[p] -> random = reflect[temp];
        }
        return reflect[head];
    }
};
```

#### [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> numset;
        vector<int> result;
        int lenth = nums.size();
        for(auto n:nums)
        {
            if(numset.find(target - n) != numset.end())
            {
                for(int i=0; i<lenth && result.size()!=2; i++)
                {
                    if(nums[i] == n)
                        result.push_back(i);
                    else if(nums[i] == target - n)
                        result.push_back(i);
                    else
                        continue;
                }
                break;
            }
            numset.insert(n);
        }
        return result;
    }
};
```

#### [167. 两数之和 II - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

设置头尾双指针向中间靠拢

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0, high=numbers.size()-1;
        while(low < high) 
        {
            int sum = numbers[low] + numbers[high];
            if (sum == target)
                return {low + 1, high + 1};
            else if (sum < target)
                low++;
            else
                high--;
        }
        return {-1, -1};
    }
};
```

#### [599. 两个列表的最小索引总和](https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists/)

```C++
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        for (int i = 0; i < list1.size(); i++) {
            map.insert(pair<string, int>(list1[i], i));
        }
        vector<string> result;
        int min_sum = INT16_MAX;
        int sum;
        for (int j = 0; j < list2.size() && j <= min_sum; ++j) {
            if (map.count(list2[j])) {
                sum = j + map[list2[j]];
                if (sum < min_sum) {
                    result.clear();
                    result.push_back(list2[j]);
                    min_sum = sum;
                } else if (sum == min_sum) {
                    result.push_back(list2[j]);
                }
            }
        }
        return result;
    }
};
```

#### [219. 存在重复元素 II](https://leetcode-cn.com/problems/contains-duplicate-ii/)

设置一个哈希表，保存某个数`n`在遍历位置之前出现的最大下标

```C++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        int lenth=nums.size();
        for(int i=0; i<lenth; i++)
        {
            if(mymap.find(nums[i]) == mymap.end())
                mymap[nums[i]] = i;
            else if(abs(mymap[nums[i]] - i) <= k)
                return true;
            else
                mymap[nums[i]] = i;
        }
        return false;
    }
};
```

#### [220. 存在重复元素 III(*)](https://leetcode-cn.com/problems/contains-duplicate-iii/)

利用桶，以$t+1$为桶大小，则符合条件的两个元素只可能出现在同一个桶或者相邻桶中

```C++
class Solution {
public:
    int getID(int x, long w) {
        return x < 0 ? (x + 1ll) / w - 1 : x / w;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long x = nums[i];
            int id = getID(x, t + 1ll);
            if (mp.count(id)) {
                return true;
            }
            if (mp.count(id - 1) && abs(x - mp[id - 1]) <= t) {
                return true;
            }
            if (mp.count(id + 1) && abs(x - mp[id + 1]) <= t) {
                return true;
            }
            mp[id] = x;
            if (i >= k) {
                mp.erase(getID(nums[i - k], t + 1ll));
            }
        }
        return false;
    }
};
```

#### [594. 最长和谐子序列](https://leetcode-cn.com/problems/longest-harmonious-subsequence/)

设置一个字典记录出现次数

```python
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        count = {}
        result = 0
        for n in nums:
            if n in count:
                count[n] += 1
            else:
                count[n] = 1
            if n-1 in count and count[n] + count[n-1] > result:
                result = count[n] + count[n-1]
            if n+1 in count and count[n] + count[n+1] > result:
                result = count[n] + count[n+1]
        return result
```

#### [350. 两个数组的交集 II](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/)

```python
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        count1 = {}
        count2 = {}
        for n in nums1:
            if n in count1:
                count1[n] += 1
            else:
                count1[n] = 1
        for n in nums2:
            if n in count2:
                count2[n] += 1
            else:
                count2[n] = 1
        interset = set(nums1) & set(nums2)
        for n in interset:
            result += [n] * min(count1[n], count2[n])
        return result
```

