"""
我们定义，在以下情况时，单词的大写用法是正确的：

    全部字母都是大写，比如 "USA" 。
    单词中所有字母都不是大写，比如 "leetcode" 。
    如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。

给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。

 

示例 1：

输入：word = "USA"
输出：true

示例 2：

输入：word = "FlaG"
输出：false

 

提示：

    1 <= word.length <= 100
    word 由小写和大写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/detect-capital
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.isupper():
            return True
        elif word.islower():
            return True
        elif len(word) == 1:
            return True
        elif word[0].isupper():
            length = len(word)
            for i in range(1, length):
                if word[i].islower():
                    continue
                else:
                    return False
            return True
        return False


teststr = "NIy"
S = Solution()
print(S.detectCapitalUse(teststr))
