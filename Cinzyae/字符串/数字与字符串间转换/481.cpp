/*
神奇字符串 s 仅由 '1' 和 '2' 组成，并需要遵守下面的规则：

    神奇字符串 s 的神奇之处在于，串联字符串中 '1' 和 '2' 的连续出现次数可以生成该字符串。

s 的前几个元素是 s = "1221121221221121122……" 。如果将 s 中连续的若干 1 和 2 进行分组，
可以得到 "1 22 11 2 1 22 1 22 11 2 11 22 ......" 。
每组中 1 或者 2 的出现次数分别是 "1 2 2 1 1 2 1 2 2 1 2 2 ......" 。上面的出现次数正是 s 自身。

给你一个整数 n ，返回在神奇字符串 s 的前 n 个数字中 1 的数目。

 

示例 1：

输入：n = 6
输出：3
解释：神奇字符串 s 的前 6 个元素是 “122112”，它包含三个 1，因此返回 3 。 

示例 2：

输入：n = 1
输出：1

 

提示：

    1 <= n <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/magical-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    int magicalString(int n)
    {
        string str = "122";
        int mark = 1, acc = 1;
        for (int i = 2; str.size() < n; i++) {
            if (str[i] == '1') {
                str.append(to_string(mark));
                acc += 1 - mark / 2;
            } else if (str[i] == '2') {
                str.append(to_string(mark));
                str.append(to_string(mark));
                acc += 2 * (1 - mark / 2);
            }
            mark = 3 - mark;
        }
        cout << str << endl;
        if (str.size() == n + 1) {
            if (str[n] == '1') {
                acc--;
            }
        }
        return acc;
    }
};

int main()
{
    Solution S;
    cout << S.magicalString(4) << endl;
    return 0;
}
/*
class Solution {
public:
    int magicalString(int n)
    {
        vector<int> num = { 1, 2, 2 };
        int mark = 1, acc = 1;
        for (int i = 2; num.size() < n; i++) {
            if (num[i] == 1) {
                num.push_back(mark);
                acc += 1 - mark / 2;
            } else if (num[i] == 2) {
                num.push_back(mark);
                num.push_back(mark);
                acc += 2 * (1 - mark / 2);
            }
            mark = 3 - mark;
        }
        if (num.size() == n + 1) {
            if (num[n] == 1) {
                acc--;
            }
        }
        return acc;
    }
};
*/