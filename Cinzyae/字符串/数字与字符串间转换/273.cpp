/*
将非负整数 num 转换为其对应的英文表示。

 

示例 1：

输入：num = 123
输出："One Hundred Twenty Three"

示例 2：

输入：num = 12345
输出："Twelve Thousand Three Hundred Forty Five"

示例 3：

输入：num = 1234567
输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

示例 4：

输入：num = 1234567891
输出："One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

 

提示：

    0 <= num <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-to-english-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> singles = { "Zero ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine " };
    vector<string> teens = { "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
    vector<string> tens = { "", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };
    vector<string> thousands = { "", "Thousand ", "Million ", "Billion " };

    string numberToWords(int num)
    {
        string retstr;
        while (1) {
            if (num >= 1000000000) {
                retstr.append(numtoword1k(num / 1000000000));
                retstr.append(thousands[3]);
                num %= 1000000000;
                if (num == 0) {
                    retstr.resize(retstr.size() - 1);
                    return retstr;
                }
            } else if (num >= 1000000) {
                retstr.append(numtoword1k(num / 1000000));
                retstr.append(thousands[2]);
                num %= 1000000;
                if (num == 0) {
                    retstr.resize(retstr.size() - 1);
                    return retstr;
                }
            } else if (num >= 1000) {
                retstr.append(numtoword1k(num / 1000));
                retstr.append(thousands[1]);
                num %= 1000;
                if (num == 0) {
                    retstr.resize(retstr.size() - 1);
                    return retstr;
                }
            } else {
                retstr.append(numtoword1k(num));
                retstr.resize(retstr.size() - 1);
                return retstr;
            }
        }
    }
    string numtoword1k(int num)
    {
        cout << num << endl;
        string retstr;
        while (1) {
            if (num >= 100) {
                retstr.append(singles[num / 100]);
                retstr.append("Hundred ");
                num %= 100;
                if (num == 0) {
                    return retstr;
                }
            } else if (num >= 20) {
                retstr.append(tens[num / 10]);
                num %= 10;
                if (num == 0) {
                    return retstr;
                }
            } else if (num >= 10) {
                retstr.append(teens[num % 10]);
                return retstr;
            } else {
                retstr.append(singles[num]);
                return retstr;
            }
        }
    }
};
int main()
{
    Solution S;
    cout << S.numberToWords(50) << endl;
    return 0;
}