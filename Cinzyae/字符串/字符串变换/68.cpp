/*
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

    单词是指由非空格字符组成的字符序列。
    每个单词的长度大于 0，小于等于 maxWidth。
    输入单词数组 words 至少包含一个单词。

示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

示例 2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。

示例 3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/text-justification
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> ret;
        int linesize = 0;
        int count = -1;
        int start = 0;
        for (int i = 0; i < words.size(); i++) {
            // cout << linesize << " " << i << endl;
            if (linesize + words[i].size() + 1 <= maxWidth + 1) {
                linesize += words[i].size() + 1;
                count++;
            } else {
                if (count == 0) {
                    string tmp = words[start];
                    while (tmp.size() < maxWidth) {
                        tmp += ' ';
                    }

                    ret.push_back(tmp);
                    start = i;
                    linesize = words[i].size() + 1;
                    count = 0;
                    continue;
                }
                string tmp;
                int a = (maxWidth - linesize + 1) / count + 1;
                int b = (maxWidth - linesize + 1) % count;
                // cout << "a:" << a << " b:" << b << " count:" << count << endl;
                for (int j = 0; j < b; j++) {
                    tmp += words[start + j];
                    for (int k = 0; k < a + 1; k++) {
                        tmp += ' ';
                    }
                }
                for (int j = b; j < count; j++) {
                    tmp += words[start + j];
                    for (int k = 0; k < a; k++) {
                        tmp += ' ';
                    }
                }
                tmp += words[start + count];
                // cout << tmp.size() << ' ' << tmp << endl;
                ret.push_back(tmp);

                start = i;
                linesize = words[i].size() + 1;
                count = 0;
            }
        }
        string tmp;
        for (int i = start; i < words.size(); i++) {
            tmp += words[i];
            tmp += ' ';
        }
        tmp = tmp.substr(0, tmp.size() - 1);
        while (tmp.size() < maxWidth) {
            tmp += ' ';
        }
        ret.push_back(tmp);
        return ret;
    }
};
int main()
{
    Solution S;
    vector<string> words = { "What", "must", "be", "acknowledgment", "shall", "be" };
    int maxWidth = 16;
    for (auto s : S.fullJustify(words, maxWidth)) {
        cout << s << endl;
    };
    return 0;
}