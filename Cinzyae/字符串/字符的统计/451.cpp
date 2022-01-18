/*
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:

输入:
"tree"

输出:
"eert"

解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。

示例 2:

输入:
"cccaaa"

输出:
"cccaaa"

解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。

示例 3:

输入:
"Aabb"

输出:
"bbAa"

解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-characters-by-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> mp;
        for (auto ch : s)
        {
            mp[ch]++;
        }
        vector<pair<char, int>> vec;
        for (auto &it : mp)
        {
            vec.emplace_back(it);
        }
        sort(vec.begin(), vec.end(), [](const pair<char, int> &a, const pair<char, int> &b)
             { return a.second > b.second; });
        string out;
        for (auto &[ch, num] : vec)
        {
            for (int i = 0; i < num; i++)
            {
                out.push_back(ch);
            }
        }
        cout << out << endl;
        return out;
    }
    // bool cmpsecond(const pair<char, int> &left, const pair<char, int> &right)
    // {
    //     return left.second > right.second;
    // }
};
int main()
{
    string test = "aaabb";
    Solution S;
    S.frequencySort(test);
    return 0;
}

/* 桶排序
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        int length = s.size();
        for (auto &ch : s) {
            maxFreq = max(maxFreq, ++mp[ch]);
        }
        vector<string> buckets(maxFreq + 1);
        for (auto &[ch, num] : mp) {
            buckets[num].push_back(ch);
        }
        string ret;
        for (int i = maxFreq; i > 0; i--) {
            string &bucket = buckets[i];
            for (auto &ch : bucket) {
                for (int k = 0; k < i; k++) {
                    ret.push_back(ch);
                }
            }
        }
        return ret;
    }
};
*/