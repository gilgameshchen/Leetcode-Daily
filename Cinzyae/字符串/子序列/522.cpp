/*
给定字符串列表，你需要从它们中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。

子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。

输入将是一个字符串列表，输出是最长特殊序列的长度。如果最长特殊序列不存在，返回 -1 。

 

示例：

输入: "aba", "cdc", "eae"
输出: 3

 

提示：

    所有给定的字符串长度不会超过 10 。
    给定字符串列表的长度将在 [2, 50 ] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-uncommon-subsequence-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <string.h>
#include <vector>
using namespace std;
class Solution {
public:
    /*
    很重要的一个性质: 如果一个字符串s的子序列s1是特殊序列 则该字符串s也是特殊序列

    反证法: 若字符串s不是特殊序列的话 则该字符串一定是其它某个字符串t的子序列 
    那么就可以通过删除t使得t的某个子序列是s1,则s1不是特殊序列 矛盾 故s一定是特殊序列

    性质的使用:那就提示我们特殊序列只需要考虑整个字符串即可 不需要枚举子串 ,
              因为若子串是特殊 那么字符串s本身也是特殊 且更长 

    因此只需要对每个字符串s 判断其是否为其它字符串的子串即可
    */
    bool isSubStr(string& a, string& b)
    { //判断a是否为b的子串
        int i = 0;
        for (auto c : b)
            if (i < a.size() && c == a[i])
                i++;
        return i == a.size();
    }
    int findLUSlength(vector<string>& strs)
    {
        sort(strs.begin(), strs.end(), [](string a, string b) { //按照长度从大到小排
            return a.size() > b.size();
        });
        for (int i = 0; i < strs.size(); i++) { //按照长度从大到小枚举串i 判断i会否是特殊序列
            bool isSub = false; //先假设i不是任何串的子串
            for (int j = 0; j < strs.size() && strs[i].size() <= strs[j].size(); j++) { //判断i是否为j的子串
                if (i != j && isSubStr(strs[i], strs[j])) { //若i是j的子串 则i不是特殊序列 跳出即可
                    isSub = true;
                    break;
                }
            }
            if (!isSub)
                return strs[i].size(); //i不是任何串的子串 则为特殊序列 直接返回即可
        }
        return -1;
    }
};
int main()
{
    Solution S;
    vector<string> strs = { "aabbcc", "aabbcc", "cb" };
    cout << S.findLUSlength(strs) << endl;
    return 0;
}
/*
        int mark = 0;
        bool flag = true;
        for (int i = 1; i < strs.size(); i++) {
            if (strcmp(strs[i].c_str(), strs[mark].c_str()) == 0) {
                flag = true;
                continue;
            } else {
                if (strs[i].size() >= strs[mark].size()) {
                    flag = false;
                    mark = i;
                }
            }
        }
        return flag ? -1 : strs[mark].size();
*/