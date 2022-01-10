"""
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。

 

提示：

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        lenlist = len(strs)
        point = 0
        lenstr = len(strs[0])
        for i in range(lenstr):
            for j in range(lenlist):
                if i >= len(strs[j]):
                    return strs[0][0:point]
                elif strs[0][i] == strs[j][i]:
                    continue
                else:
                    return strs[0][0:point]
            point += 1
        return strs[0]
