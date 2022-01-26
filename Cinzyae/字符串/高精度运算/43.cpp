/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。

 

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"

 

提示：

    1 <= num1.length, num2.length <= 200
    num1 和 num2 只能由数字组成。
    num1 和 num2 都不包含任何前导零，除了数字0本身。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
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
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        auto ansArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto& c : ans) {
            c += '0';
        }
        return ans;
    }
};

int main()
{
    Solution S;
    string s1 = "139";
    string s2 = "203";
    cout << S.multiply(s1, s2) << endl;
    return 0;
}
/* 复杂度高
class Solution {
private:
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
    string stepmultiply(string num1, char num2)
    {
        string retstr;
        string carrystr = "0";
        string::iterator pos1 = num1.end() - 1;
        while (pos1 >= num1.begin()) {
            int mult = (*pos1 - '0') * (num2 - '0');
            retstr.insert(retstr.begin(), mult % 10 + '0');
            carrystr.insert(carrystr.begin(), mult / 10 + '0');
            pos1--;
        }
        if (*(carrystr.begin()) == '0') {
            carrystr = carrystr.substr(1);
        }
        retstr = addStrings(retstr, carrystr);
        return retstr;
    }

public:
    string multiply(string num1, string num2)
    {
        if (((num1.compare("0")) == 0) || ((num2.compare("0")) == 0)) {
            return "0";
        }
        string retstr = "0";
        for (int i = num2.size() - 1; i >= 0; i--) {
            string tmpstr = stepmultiply(num1, num2[i]);
            for (int j = num2.size() - 1 - i; j > 0; j--) {
                tmpstr.push_back('0');
            }
            retstr = addStrings(retstr, tmpstr);
        }
        return retstr;
    }
};
*/