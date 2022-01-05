#### [520. 检测大写字母](https://leetcode-cn.com/problems/detect-capital/)

状态机解法

```C++
class Solution {
public:
    bool detectCapitalUse(string word) {
        char cur_s = 'a';
        int lenth = word.size();
        int i=0;
        bool is_upper;
        while(i < lenth)
        {
            is_upper = word[i]>='A' && word[i]<='Z';
            switch(cur_s)
            {
                case 'a':
                {
                    cur_s = is_upper ? 'b' : 'c';
                    break;
                }
                case 'b':
                {
                    cur_s = is_upper ? 'd' : 'c';
                    break;
                }
                case 'c':
                {
                    if(is_upper)
                        return false;
                    break;
                }
                case 'd':
                {
                    if(!is_upper)
                        return false;
                    break;
                }
            }
            i++;
        }
        if(cur_s == 'a')
            return false;
        else
            return true;
    }
};
```

#### [125. 验证回文串](https://leetcode-cn.com/problems/valid-palindrome/)

注意考虑所给条件。设置头尾两个指针，向中间靠拢。

* 若遇到非字母且非数字，跳过；
* 若头尾相等，则继续循环；
* 若不相等，判断头尾是否为字母且ASCII绝对值差为32，若是则继续循环，否则该字符串不是回文串。

```C++
class Solution {
public:
    bool isPalindrome(string s) {
        bool result = true;
        int lenth = s.size();
        int head=0, tail=lenth-1;
        while(head < tail)
        {
            while(!isalnum(s[head]) && head<lenth)
                head++;
            while(!isalnum(s[tail]) && tail>head)
                tail--;
            if(tail < head)
                break;
            if(s[head]==s[tail] || 
                (isalpha(s[head]) && isalpha(s[tail]) && abs(s[head]-s[tail])==32))
            {
                head++;
                tail--;
            }
            else
            {
                result = false;
                break;
            }
        }
        return result;
    }
};
```

#### [14. 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)

纵向扫描，以第一个为基准。

```C++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        bool loopflag = true;
        int strnum=strs.size(), i=0;
        vector<int> pos(strnum, 0);
        for(string str:strs)
        {
            if(str == "")
                return result;
        }
        char temp = strs[0][0];
        while(loopflag)
        {
            for(i=0; i<strnum; i++)
            {
                if(temp == strs[i][pos[i]])
                {
                    pos[i]++;
                    if(pos[i] == strs[i].size())
                        loopflag = false;
                }
                else
                    return result;
            }
            result += temp;
            if(pos[0] == strs[0].size())
                loopflag = false;
            else
                temp = strs[0][pos[0]];
        }
        return result;
    }
};
```

#### [434. 字符串中的单词数](https://leetcode-cn.com/problems/number-of-segments-in-a-string/)

状态机解法

```C++
class Solution {
public:
    int countSegments(string s) {
        int count=0, lenth=s.size();
        char cur_s = 'A';
        for(int i=0; i<lenth; i++)
        {
            switch(cur_s)
            {
                case 'A':
                {
                    if(s[i] != ' ')
                    {
                        cur_s = 'B';
                        count++;
                    }
                    break;
                }
                case 'B':
                {
                    if(s[i] == ' ')
                        cur_s = 'A';
                    break;
                }
            }
        }
        return count;
    }
};
```

#### [58. 最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word/)

从后往前遍历即可

```C++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int lenth=s.size(), result=0;
        int i = lenth - 1;
        while(!isalpha(s[i]))
            i--;
        result = i;
        while(i>=0 && isalpha(s[i]))
            i--;
        return result - i;
    }
};
```

#### [344. 反转字符串](https://leetcode-cn.com/problems/reverse-string/)

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0, j=s.size()-1;
        while(i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
```

#### [541. 反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)

与上题类似，只不过需要处理翻转的范围

```C++
class Solution {
public:
    string reverseStr(string s, int k) {
        int lenth=s.size(), i=0, left, right, full, remain;
        string result = s;
        full = lenth / (2 * k);
        remain = lenth % (2 * k);
        for(i=0; i<full; i++)
        {
            left = i * k * 2;
            right = left + k - 1;
            while(left < right)
            {
                swap(result[left], result[right]);
                left++;
                right--;
            }
        }
        left = i * k * 2;
        right = (remain < k) ? lenth - 1 : left + k - 1;
        while(left < right)
        {
            swap(result[left], result[right]);
            left++;
            right--;
        }
        return result;
    }
};
```

#### [557. 反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

扫描原字符串，截取单词，然后从后往前将字符加入到`result`中，除了末尾，再加一个空格。需要注意边界条件

```C++
class Solution {
public:
    string reverseWords(string s) {
        int i=0, left, right, lenth=s.size();
        string result = "";
        bool mode = false;
        while(i < lenth)
        {
            if(s[i]==' ' || i==lenth-1)
            {
                if(mode)
                {
                    mode = false;
                    right = (s[i]!=' ') ? i : i - 1;
                    while(left <= right)
                    {
                        result += s[right];
                        right--;
                    }
                    if(i != lenth - 1) result += ' ';
                }
                else if(i == lenth - 1)
                    result += s[i];
            }
            else
            {
                if(!mode)
                {
                    mode = true;
                    left = i;
                }
            }
            i++;
        }
        return result;
    }
};
```

#### [151. 翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)

先将整个字符串翻转，然后使用上题的方法即可

```C++
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) 
        {
            if (s[start] != ' ') 
            {
                if (idx != 0) s[idx++] = ' ';
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};
```

#### [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

利用散列存储，设置标记数组，存储每个字母的出现情况，当它为-1时，对应字母没有出现；当它为-2时，对应字母重复出现；当它非负时，为第一次出现的位置。

```C++
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mark(26, -1);
        int lenth=s.size(), i, index;
        for(i=0; i<lenth; i++)
        {
            index = s[i] - 97;
            if(mark[index] > -1)
                mark[index] = -2;
            else if(mark[index] == -1)
                mark[index] = i;
            else
                continue;
        }
        int result = lenth;
        for(i=0; i<26; i++)
        {
            if(result>mark[i] && mark[i]>-1)
                result=mark[i];
        }
        return (result==lenth) ? -1 : result;
    }
};
```

#### [389. 找不同](https://leetcode-cn.com/problems/find-the-difference/)

设置计数数组，对两个字符串出现次数计数，其中为奇数的对应字母是被添加的字母

```C++
    char findTheDifference(string s, string t) {
        int slenth=s.size(), i=0;
        int count[26] = {0};
        for(i=0; i<slenth; i++)
        {
            count[s[i] - 97]++;
            count[t[i] - 97]++;
        }
        count[t[i] - 97]++;
        i=0;
        while(count[i] % 2 == 0)i++;
        return (char)(i + 97);
    }
};
```

#### [383. 赎金信](https://leetcode-cn.com/problems/ransom-note/)

设置计数数组，记录杂志每个字母的数量，然后遍历赎金信，每使用一个字母，对应计数减一，若某个字母不够用，则返回`false`

```C++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        int m_lenth=magazine.size(), r_lenth=ransomNote.size();
        for(int i=0; i<m_lenth; i++)
            count[magazine[i] - 97]++;
        for(int i=0; i<r_lenth; i++)
        {
            if(count[ransomNote[i] - 97] > 0)
                count[ransomNote[i] - 97]--;
            else
                return false;
        }
        return true;
    }
};
```

#### [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)

设置计数数组，若两个字符串长度不一，则返回`false`，遍历两个数组，一个对应字母计数自增，另一个对应字母计数自减。遍历计数数组，若存在不为零的字母则返回`false`

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen=s.size(), tlen=t.size();
        int mark[26]={0};
        if(slen != tlen)
            return false;
        for(int i=0; i<slen; i++)
        {
            mark[s[i] - 'a']++;
            mark[t[i] - 'a']--;
        }
        for(int i=0; i<26; i++)
        {
            if(mark[i] != 0)
                return false;
        }
        return true;
    }
};
```

#### [49. 字母异位词分组(*)](https://leetcode-cn.com/problems/group-anagrams/)

哈希

```C++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
```

#### [451. 根据字符出现频率排序](https://leetcode-cn.com/problems/sort-characters-by-frequency/)

设置字典计数

```python
class Solution:
    def frequencySort(self, s: str) -> str:
        dict = {}
        for i in s:
            if(i in dict):
                dict[i] = dict[i] + 1
            else:
                dict[i] = 1
        dict_order = sorted(dict.items(), key=lambda x:x[1], reverse=True)
        result = ""
        for d in dict_order:
            result += d[0] * d[1]
        return result
```

#### [423. 从英文中重建数字(*)](https://leetcode-cn.com/problems/reconstruct-original-digits-from-english/)

必须将拥有唯一字母的数字排在前面筛选，否则会出现错误

```C++
class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> c;
        for (char ch: s) {
            ++c[ch];
        }
        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[6] = c['x'];
        cnt[8] = c['g'];
        
        cnt[3] = c['h'] - cnt[8];
        cnt[5] = c['f'] - cnt[4];
        cnt[7] = c['s'] - cnt[6];

        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += char(i + '0');
            }
        }
        return ans;
    }
};
```

#### [657. 机器人能否返回原点](https://leetcode-cn.com/problems/robot-return-to-origin/)

判断上与下、左与右的步数是否相等即可

```C++
class Solution {
public:
    bool judgeCircle(string moves) {
        int UD=0, LR=0;
        for(auto move:moves)
        {
            switch(move)
            {
                case 'U':
                    UD++;
                    break;
                case 'D':
                    UD--;
                    break;
                case 'L':
                    LR++;
                    break;
                case 'R':
                    LR--;
                    break;
                default:
                    break;
            }
        }
        if(UD==0 && LR==0)
            return true;
        else
            return false;
    }
};
```

#### [551. 学生出勤记录 I](https://leetcode-cn.com/problems/student-attendance-record-i/)

遍历字符串即可，注意判断条件

```C++
class Solution {
public:
    bool checkRecord(string s) {
        bool A_count = false;
        char L_count = 0;
        for(auto x:s)
        {
            if(x =='A')
            {
                if(A_count)
                    return false;
                else
                    A_count = true;
                L_count = 0;
            }
            else if(x == 'L')
            {
                if(L_count == 2)
                    return false;
                else
                    L_count++;
            }
            else
                L_count = 0;
        }
        return true;
    }
};
```

