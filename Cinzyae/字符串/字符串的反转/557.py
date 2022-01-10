"""
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 

示例：

输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"

 

提示：

    在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution:
    def reverseWords(self, s: str) -> str:
        # s = list(s.split(" "))
        # s1 = []
        # for word in s:
        #     word = list(word)
        #     word[:] = reversed(word[:])
        #     word = "".join(word)
        #     s1.append(word)
        # return " ".join(s1)

        # s = list(s)
        # point = 0
        # for i in range(len(s)):
        #     if s[i] == " ":
        #         s[point:i] = reversed(s[point:i])
        #         point = i + 1
        # s[point:len(s)] = reversed(s[point:len(s)])
        # return "".join(s)

        # s1 = []
        # for word in s.split(" "):
        #     word = word[::-1]
        #     s1.append(word)
        # return " ".join(s1)

        return " ".join(word[::-1] for word in s.split(" "))

teststr = "Let's take LeetCode contest"
S = Solution()
print(S.reverseWords(teststr))
