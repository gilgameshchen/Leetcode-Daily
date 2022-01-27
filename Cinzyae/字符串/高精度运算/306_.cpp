/*
累加数 是一个字符串，组成它的数字可以形成累加序列。

一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，序列中的每个后续数字必须是它之前两个数字之和。

给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。

说明：累加序列里的数，除数字 0 之外，不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

 

示例 1：

输入："112358"
输出：true 
解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

示例 2：

输入："199100199"
输出：true 
解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199

 

提示：

    1 <= num.length <= 35
    num 仅由数字（0 - 9）组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/additive-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num)
    {
        int n = num.size();
        for (int secondStart = 1; secondStart < n - 1; ++secondStart) {
            if (num[0] == '0' && secondStart != 1) {
                break;
            }
            for (int secondEnd = secondStart; secondEnd < n - 1; ++secondEnd) {
                if (num[secondStart] == '0' && secondStart != secondEnd) {
                    break;
                }
                if (valid(secondStart, secondEnd, num)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool valid(int secondStart, int secondEnd, string num)
    {
        int n = num.size();
        int firstStart = 0, firstEnd = secondStart - 1;
        while (secondEnd <= n - 1) {
            string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
            int thirdStart = secondEnd + 1;
            int thirdEnd = secondEnd + third.size();
            if (thirdEnd >= n || !(num.substr(thirdStart, thirdEnd - thirdStart + 1) == third)) {
                break;
            }
            if (thirdEnd == n - 1) {
                return true;
            }
            firstStart = secondStart;
            firstEnd = secondEnd;
            secondStart = thirdStart;
            secondEnd = thirdEnd;
        }
        return false;
    }

    string stringAdd(string s, int firstStart, int firstEnd, int secondStart, int secondEnd)
    {
        string third;
        int carry = 0, cur = 0;
        while (firstEnd >= firstStart || secondEnd >= secondStart || carry != 0) {
            cur = carry;
            if (firstEnd >= firstStart) {
                cur += s[firstEnd] - '0';
                --firstEnd;
            }
            if (secondEnd >= secondStart) {
                cur += s[secondEnd] - '0';
                --secondEnd;
            }
            carry = cur / 10;
            cur %= 10;
            third.push_back(cur + '0');
        }
        reverse(third.begin(), third.end());
        return third;
    }
};