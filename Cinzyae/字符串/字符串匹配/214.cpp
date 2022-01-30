/*
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

 

示例 1：

输入：s = "aacecaaa"
输出："aaacecaaa"

示例 2：

输入：s = "abcd"
输出："dcbabcd"

 

提示：

    0 <= s.length <= 5 * 104
    s 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = fail[i - 1];
            while (j != -1 && s[j + 1] != s[i]) {
                j = fail[j];
            }
            if (s[j + 1] == s[i]) {
                fail[i] = j + 1;
            }
        }
        int best = -1;
        for (int i = n - 1; i >= 0; --i) {
            while (best != -1 && s[best + 1] != s[i]) {
                best = fail[best];
            }
            if (s[best + 1] == s[i]) {
                ++best;
            }
        }
        string add = (best == n - 1 ? "" : s.substr(best + 1, n));
        reverse(add.begin(), add.end());
        return add + s;
    }
};
int main()
{
    string s = "abcd";
    Solution S;
    cout << S.shortestPalindrome(s) << endl;
    return 0;
}
/*
class Solution {
public:
    string shortestPalindrome(string s)
    {
        if(s == ""){
            return "";
        }
        int mark = 0;
        for (int i = 0; i < s.size() / 2; i++) {
            if (ishuiwen(s, (i + 1) * 2 - 1)) {
                mark = (i + 1) * 2 - 1;
            }
            if (ishuiwen(s, (i + 1) * 2)) {
                mark = (i + 1) * 2;
            }
        }
        string tmpstr = s.substr(mark + 1);
        reverse(tmpstr.begin(), tmpstr.end());
        return tmpstr + s;
    }
    bool ishuiwen(string& s, int endpos)
    {
        cout << endpos << endl;
        for (int pos = 0; pos <= endpos; pos++, endpos--) {
            cout << pos << " " << endpos << endl;
            if (s[pos] != s[endpos]) {
                return false;
            }
        }
        return true;
    }
};
*/