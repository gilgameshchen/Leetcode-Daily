/*
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "1"
输出: "100"

示例 2:

输入: a = "1010", b = "1011"
输出: "10101"

 

提示：

    每个字符串仅由字符 '0' 或 '1' 组成。
    1 <= a.length, b.length <= 10^4
    字符串如果不是 "0" ，就都不含前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b)
    {
        string::iterator pos1 = a.end() - 1, pos2 = b.end() - 1;
        string retstr;
        int carry = 0;
        while ((pos1 >= a.begin()) && (pos2 >= b.begin())) {
            int acc = (*pos1 - '0') + (*pos2 - '0') + carry;
            // cout << acc << endl;
            if (acc == 3) {
                retstr.insert(retstr.begin(), '1');
                carry = 1;
            } else if (acc == 2) {
                retstr.insert(retstr.begin(), '0');
                carry = 1;
            } else if (acc == 1) {
                retstr.insert(retstr.begin(), '1');
                carry = 0;
            } else {
                retstr.insert(retstr.begin(), '0');
                carry = 0;
            }
            pos1--;
            pos2--;
        }
        while (pos1 >= a.begin()) {
            int acc = (*pos1 - '0') + carry;
            // cout << acc << endl;
            if (acc == 2) {
                retstr.insert(retstr.begin(), '0');
                carry = 1;
            } else if (acc == 1) {
                retstr.insert(retstr.begin(), '1');
                carry = 0;
            } else {
                retstr.insert(retstr.begin(), '0');
                carry = 0;
            }
            pos1--;
        }
        while (pos2 >= b.begin()) {
            int acc = (*pos2 - '0') + carry;
            // cout << acc << endl;
            if (acc == 2) {
                retstr.insert(retstr.begin(), '0');
                carry = 1;
            } else if (acc == 1) {
                retstr.insert(retstr.begin(), '1');
                carry = 0;
            } else {
                retstr.insert(retstr.begin(), '0');
                carry = 0;
            }
            pos2--;
        }
        if (carry) {
            retstr.insert(retstr.begin(), '1');
        }
        return retstr;
    }
};
int main()
{
    Solution S;
    cout << S.addBinary("11", "1") << endl;
    return 0;
}