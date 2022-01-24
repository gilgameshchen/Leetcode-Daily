/*
给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，
该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。

 

示例 1：

输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"

示例 2：

输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"

 

提示：

    1 <= s.length <= 1000
    1 <= dictionary.length <= 1000
    1 <= dictionary[i].length <= 1000
    s 和 dictionary[i] 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary)
    {
        int dicsize = dictionary.size();
        sort(dictionary.begin(), dictionary.end(), [&](string& a, string& b) {
            if (a.size() == b.size())
                return a < b;
            return a.size() < b.size();
        });
        // for (int i = 0; i < dicsize; i++) {
        //     if (dictionary[i].size() > s.size()) {
        //         dicsize = i;
        //         cout << dicsize << endl;
        //         break;
        //     }
        // }
        vector<int> pos(dicsize, 0);
        int spos = 0, slength = s.size();
        while (spos < slength) {
            char tmp = s[spos];
            for (int i = 0; i < dicsize; i++) {
                if (pos[i] >= dictionary[i].size()) {
                    continue;
                }
                if (dictionary[i][pos[i]] == tmp) {
                    pos[i]++;
                }
            }
            spos++;
        }
        // for (auto p : pos) {
        //     cout << p << ' ';
        // }
        int maxpos = 0, maxmark = 0;
        for (int i = 0; i < dicsize; i++) {
            if(pos[i]<dictionary[i].size()){
                continue;
            }
            if (maxpos < pos[i]) {
                maxpos = pos[i];
                maxmark = i;
            } else if (maxpos == pos[i]) {
                if (dictionary[maxmark].size() < dictionary[i].size()) {
                    maxpos = pos[i];
                    maxmark = i;
                }
            }
        }
        if(maxpos==0){
            return "";
        }
        return dictionary[maxmark];
    }
};
int main()
{
    Solution S;
    string s = "aewfafwafjlwajflwajflwafj";
    vector<string> dictionary = { "apple", "ewaf", "awefawfwaf", "awef", "awefe", "ewafeffewafewf" };
    cout << S.findLongestWord(s, dictionary) << endl;
    return 0;
}

