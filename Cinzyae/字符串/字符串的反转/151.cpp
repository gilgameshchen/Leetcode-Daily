/*
给你一个字符串 s ，逐个翻转字符串中的所有 单词 。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。

说明：

    输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
    翻转后单词间应当仅用一个空格分隔。
    翻转后的字符串中不应包含额外的空格。

 

示例 1：

输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：

输入：s = "  hello world  "
输出："world hello"
解释：输入字符串可以在前面或者后面包含多余的空格，但是翻转后的字符不能包括。

示例 3：

输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，将翻转后单词间的空格减少到只含一个。

示例 4：

输入：s = "  Bob    Loves  Alice   "
输出："Alice Loves Bob"

示例 5：

输入：s = "Alice does not even like bob"
输出："bob like even not does Alice"

 

提示：

    1 <= s.length <= 104
    s 包含英文大小写字母、数字和空格 ' '
    s 中 至少存在一个 单词

 

进阶：

    请尝试使用 O(1) 额外空间复杂度的原地解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string
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
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        int length = s.size();
        int point = 0;
        int i = 0;
        while (i < length)
        {
            while (i < length && s[i] == ' ')
            {
                i++;
            }
            if(i==length){break;}
            int start = i;
            while (i < length && s[i] != ' ')
            {
                i++;
            }
            reverse(s.begin() + start, s.begin() + i);
            for (int j = 0; j < i - start; j++)
            {
                s[point + j] = s[start + j];
            }
            point += i - start;
            s[point] = ' ';
            cout << s << " " << point << endl;
            point++;
        }
        s.resize(point - 1);
        return s;
    }
};

int main()
{
    string test = "     sky  ";
    Solution S;
    cout << S.reverseWords(test) << endl;
    return 0;
}