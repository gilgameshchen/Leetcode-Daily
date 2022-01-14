/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。

 

提示：

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
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
    string longestCommonPrefix(vector<string> &strs)
    {
        string retstr = "";
        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (i > strs[j].size())
                {
                    return retstr;
                }
                if (strs[j][i] == strs[0][i])
                {
                    continue;
                }
                else
                {
                    return retstr;
                }
            }
            retstr.push_back(strs[0][i]);
        }
        return retstr;
    }
};

int main()
{
    vector<string> strs = {"dog","racecar","car"};
    Solution S;
    cout << S.longestCommonPrefix(strs) << endl;
    return 0;
}