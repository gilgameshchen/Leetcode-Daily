/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

 

示例 1：

输入：num1 = "11", num2 = "123"
输出："134"

示例 2：

输入：num1 = "456", num2 = "77"
输出："533"

示例 3：

输入：num1 = "0", num2 = "0"
输出："0"

 

 

提示：

    1 <= num1.length, num2.length <= 104
    num1 和num2 都只包含数字 0-9
    num1 和num2 都不包含任何前导零

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        string::iterator pos1 = num1.end() - 1, pos2 = num2.end() - 1;
        string retstr;
        int carry = 0;
        while ((pos1 >= num1.begin()) && (pos2 >= num2.begin())) {
            int acc = (*pos1 - '0') + (*pos2 - '0') + carry;
            if (acc > 9) {
                retstr.insert(retstr.begin(), '0' + (acc - 10));
                carry = 1;
            } else {
                retstr.insert(retstr.begin(), '0' + acc);
                carry = 0;
            }
            pos1--;
            pos2--;
        }
        while (pos1 >= num1.begin()) {
            int acc = (*pos1 - '0') + carry;
            if (acc > 9) {
                retstr.insert(retstr.begin(), '0' + (acc - 10));
                carry = 1;
            } else {
                retstr.insert(retstr.begin(), '0' + acc);
                carry = 0;
            }
            pos1--;
        }
        while (pos2 >= num2.begin()) {
            int acc = (*pos2 - '0') + carry;
            if (acc > 9) {
                retstr.insert(retstr.begin(), '0' + (acc - 10));
                carry = 1;
            } else {
                retstr.insert(retstr.begin(), '0' + acc);
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