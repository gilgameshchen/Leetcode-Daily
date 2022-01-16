/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

 

示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false

示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false

示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true

 

提示：

    1 <= ransomNote.length, magazine.length <= 105
    ransomNote 和 magazine 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ransom-note
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
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> alphas(26, 0);
        for (auto alpha : magazine)
        {
            int intalpha = int(alpha) - 97;
            if (intalpha >= 0 && intalpha < 26)
            {
                alphas[intalpha]++;
            }
        }
        for (auto alpha : ransomNote)
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
            if (alphas[i] < 0)
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
    cout << S.canConstruct("aa","ab") << endl;
    return 0;
}