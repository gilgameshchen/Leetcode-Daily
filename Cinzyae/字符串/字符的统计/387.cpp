/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

 

示例：

s = "leetcode"
返回 0

s = "loveleetcode"
返回 2

 

提示：你可以假定该字符串只包含小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
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
    int firstUniqChar(string s)
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
        // for (auto alpha : alphas)
        // {
        //     cout << alpha << " ";
        // }
        for (int i = 0; i < s.size(); i++)
        {
            if (alphas[int(s[i]) - 97] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    string test = "abcda";
    Solution S;
    cout << S.firstUniqChar(test) << endl;
    return 0;
}