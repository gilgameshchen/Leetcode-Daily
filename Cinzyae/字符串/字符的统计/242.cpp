/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

 

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true

示例 2:

输入: s = "rat", t = "car"
输出: false

 

提示:

    1 <= s.length, t.length <= 5 * 104
    s 和 t 仅包含小写字母

 

进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> alphas(26, 0);
        for (auto alpha : s)
        {
            int intalpha = int(alpha) - 97;
            if (intalpha >= 0 && intalpha < 26)
            {
                alphas[intalpha]++;
            }
        }
        for (auto alpha : t)
        {
            int intalpha = int(alpha) - 97;
            if (intalpha >= 0 && intalpha < 26)
            {
                alphas[intalpha]--;
            }
        }
        // for (auto alpha : alphas)
        // {
        //     cout << alpha << " ";
        // }
        for (int i = 0; i < alphas.size(); i++)
        {
            if (alphas[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    string test = "";
    Solution S;
    cout << S.isAnagram("anagram", "nagaram") << endl;
    return 0;
}