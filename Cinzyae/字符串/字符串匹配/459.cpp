/*
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

 

示例 1:

输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。

示例 2:

输入: s = "aba"
输出: false

示例 3:

输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)

 

提示：

    1 <= s.length <= 104
    s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/repeated-substring-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        int pos1max = s.size() / 2;
        for (int pos1 = 1; pos1 <= pos1max; pos1++) {
            // cout << s.substr(0, pos1) << "__" << s.substr(pos1, pos1) << endl;
            // cout << "0 " << pos1 << "__" << pos1 << " " << pos1 << endl;
            if (s.substr(0, pos1) == s.substr(pos1, pos1)) {
                int i = pos1;
                while ((i < s.size()) && (s.substr(0, pos1) == s.substr(i, pos1))) {
                    i += pos1;
                }
                if (i == s.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution S;
    string test = "abab";
    cout << S.repeatedSubstringPattern(test) << endl;
    return 0;
}

/* find
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};


作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/repeated-substring-pattern/solution/zhong-fu-de-zi-zi-fu-chuan-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

/* KMP
class Solution {
public:
    bool kmp(const string& pattern) {
        int n = pattern.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = fail[i - 1];
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = fail[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                fail[i] = j + 1;
            }
        }
        return fail[n - 1] != -1 && n % (n - fail[n - 1] - 1) == 0;
    }

    bool repeatedSubstringPattern(string s) {
        return kmp(s);
    }
};


作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/repeated-substring-pattern/solution/zhong-fu-de-zi-zi-fu-chuan-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/