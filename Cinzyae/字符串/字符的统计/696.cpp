/*
给定一个字符串 s，统计并返回具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是成组连续的。

重复出现（不同位置）的子串也要统计它们出现的次数。
 

示例 1：

输入：s = "00110011"
输出：6
解释：6 个子串满足具有相同数量的连续 1 和 0 ："0011"、"01"、"1100"、"10"、"0011" 和 "01" 。
注意，一些重复出现的子串（不同位置）要统计它们出现的次数。
另外，"00110011" 不是有效的子串，因为所有的 0（还有 1 ）没有组合在一起。

示例 2：

输入：s = "10101"
输出：4
解释：有 4 个子串："10"、"01"、"10"、"01" ，具有相同数量的连续 1 和 0 。

 

提示：

    1 <= s.length <= 105
    s[i] 为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-binary-substrings
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
    int countBinarySubstrings(string s)
    {
        int pre = 0, mark = 1, acc = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                mark++;
            }
            else
            {
                acc += min(pre, mark);
                pre = mark;
                mark = 1;
            }
        }
        acc += min(pre, mark);
        return acc;
    }
};
int main()
{
    string test = "00110011";
    Solution S;
    cout << S.countBinarySubstrings(test) << endl;
    return 0;
}

// 想复杂了
// class Solution
// {
// public:
//     int countBinarySubstrings(string s)
//     {
//         map<vector<int>, int> mp;
//         bool turn = (s[0] == '1');
//         int pre = 0, mark = 1;
//         for (int i = 1; i < s.size(); i++)
//         {
//             if (s[i] == s[i - 1])
//             {
//                 mark++;
//             }
//             else
//             {
//                 for (int i = min(pre, mark); i > 0; i--)
//                 {
//                     mp[vector<int>{i, i, turn}]++;
//                 }
//                 pre = mark;
//                 mark = 1;
//                 turn = !turn;
//             }
//         }
//         for (int i = min(pre, mark); i > 0; i--)
//         {
//             mp[vector<int>{i, i, turn}]++;
//         }
//         for (auto e : mp)
//         {
//             for (auto v : e.first)
//             {
//                 cout << v << ' ';
//             }
//             cout << endl;
//         }
//         mark = 0;
//         for (auto e : mp)
//         {
//             mark += e.second;
//         }
//         return mark;
//     }
// };