"""
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

 

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串

示例 2:

输入: "race a car"
输出: false
解释："raceacar" 不是回文串

 

提示：

    1 <= s.length <= 2 * 105
    字符串 s 由 ASCII 字符组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s2 = ""
        for c in s:
            if c.isalnum():
                s2 += c.lower()
        strlen = len(s2)
        halflen = int(len(s2) / 2)
        for i in range(halflen):
            if s2[i] == s2[strlen - 1 - i]:
                continue
            else:
                return False
        return True
