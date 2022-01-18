/*
给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。

 

示例 1：

输入：s = "owoztneoer"
输出："012"

示例 2：

输入：s = "fviefuro"
输出："45"

 

提示：

    1 <= s.length <= 105
    s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"] 这些字符之一
    s 保证是一个符合题目要求的字符串

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-original-digits-from-english
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
    string originalDigits(string s)
    {
        map<char, int> mp;
        for (auto ch : s)
        {
            mp[ch]++;
        }
        vector<int> vec(10, 0);
        vec[0] = mp['z'];
        vec[2] = mp['w'];
        vec[4] = mp['u'];
        vec[6] = mp['x'];
        vec[8] = mp['g'];

        vec[3] = mp['h'] - vec[8];
        vec[5] = mp['f'] - vec[4];
        vec[7] = mp['s'] - vec[6];

        vec[1] = mp['o'] - vec[0] - vec[2] - vec[4];

        vec[9] = mp['i'] - vec[5] - vec[6] - vec[8];
        // for (auto v : vec)
        // {
        //     cout << v << ' ';
        // }
        string ans;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < vec[i]; j++)
            {
                ans.push_back(char(i + '0'));
            }
        }
        return ans;
    }
};
int main()
{
    string test = "owoztneoer";
    Solution S;
    cout << S.originalDigits(test) << endl;
    return 0;
}