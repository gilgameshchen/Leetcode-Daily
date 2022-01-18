/*
把字符串 s 看作是“abcdefghijklmnopqrstuvwxyz”的无限环绕字符串，所以 s 看起来是这样的："...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....". 

现在我们有了另一个字符串 p 。你需要的是找出 s 中有多少个唯一的 p 的非空子串，尤其是当你的输入是字符串 p ，你需要输出字符串 s 中 p 的不同的非空子串的数目。 

注意: p 仅由小写的英文字母组成，p 的大小可能超过 10000。

 

示例 1:

输入: "a"
输出: 1
解释: 字符串 S 中只有一个"a"子字符。

 

示例 2:

输入: "cac"
输出: 2
解释: 字符串 S 中的字符串“cac”只有两个子串“a”、“c”。

 

示例 3:

输入: "zab"
输出: 6
解释: 在字符串 S 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-substrings-in-wraparound-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;
// 记录以每个字符结尾字串的最长长度
class Solution {
public:
    bool isContinous(char prev, char curr) {
        if (prev == 'z') return curr == 'a';
        return prev + 1 == curr;
    }
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int N = p.size();
        int k = 0;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && isContinous(p[i - 1], p[i])) {
                ++k;
            } else {
                k = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
int main()
{
    string test = "cac";
    Solution S;
    cout << S.findSubstringInWraproundString(test) << endl;
    return 0;
}
/* 超时
class Solution
{
public:
    int findSubstringInWraproundString(string p)
    {
        map<string, int> mp;
        int start = 0, end = 0;
        for (int i = 1; i < p.size(); i++)
        {
            if ((int(p[i]) == int(p[i - 1]) + 1) || ((p[i] == 'a') && (p[i - 1] == 'z')))
            {
                ;
            }
            else
            {
                for (int j = 0; j < i - start; j++)
                {
                    for (int k = 0; k <= i - start - j; k++)
                    {
                        // cout << j << ' ' << k << endl;
                        mp[p.substr(start + j, k)]++;
                    }
                }
                start = i;
            }
        }
        for (int j = 0; j < p.size() - start; j++)
        {
            for (int k = 0; k <= p.size() - start - j; k++)
            {
                // cout << j << ' ' << k << endl;
                mp[p.substr(start + j, k)]++;
            }
        }
        // for (auto s : mp)
        // {
        //     cout << s.first << endl;
        // }
        return mp.size() - 1;
    }
};
*/