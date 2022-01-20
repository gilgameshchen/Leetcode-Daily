/*
给你一个长度为 n 的整数数组 score ，其中 score[i] 是第 i 位运动员在比赛中的得分。所有得分都 互不相同 。

运动员将根据得分 决定名次 ，其中名次第 1 的运动员得分最高，名次第 2 的运动员得分第 2 高，依此类推。运动员的名次决定了他们的获奖情况：

    名次第 1 的运动员获金牌 "Gold Medal" 。
    名次第 2 的运动员获银牌 "Silver Medal" 。
    名次第 3 的运动员获铜牌 "Bronze Medal" 。
    从名次第 4 到第 n 的运动员，只能获得他们的名次编号（即，名次第 x 的运动员获得编号 "x"）。

使用长度为 n 的数组 answer 返回获奖，其中 answer[i] 是第 i 位运动员的获奖情况。

 

示例 1：

输入：score = [5,4,3,2,1]
输出：["Gold Medal","Silver Medal","Bronze Medal","4","5"]
解释：名次为 [1st, 2nd, 3rd, 4th, 5th] 。

示例 2：

输入：score = [10,3,8,9,4]
输出：["Gold Medal","5","Bronze Medal","Silver Medal","4"]
解释：名次为 [1st, 5th, 3rd, 2nd, 4th] 。

 

提示：

    n == score.length
    1 <= n <= 104
    0 <= score[i] <= 106
    score 中的所有值 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/relative-ranks
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
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<int> scorelist = score;
        map<int, int> mp;
        vector<string> retvec;
        sort(scorelist.begin(), scorelist.end(), greater<int>()); // scorelist (rank,sortedscore)
        for (int i = 0; i < n; i++)
        {
            mp[scorelist[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int rank = mp[score[i]];
            if (rank == 0)
            {
                retvec.push_back("Gold Medal");
            }
            else if (rank == 1)
            {
                retvec.push_back("Silver Medal");
            }
            else if (rank == 2)
            {
                retvec.push_back("Bronze Medal");
            }
            else
            {
                retvec.push_back(to_string(rank + 1));
            }
        }
        // for(auto r:retvec){cout << r << ' ';}
        return retvec;
    }
};
int main()
{
    vector<int> score = {10, 3, 8, 9, 4};
    Solution S;
    for (auto s:S.findRelativeRanks(score)){cout << s << ' ';}
    return 0;
}

/* pair
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int N = score.size();
        vector<string> res(N);
        vector<pair<int, int>> ranks;
        for (int i = 0; i < N; ++i) {
            ranks.push_back({score[i], i});
        }
        sort(ranks.begin(), ranks.end(), std::greater<>());
        for (int i = 0; i < ranks.size(); ++i) {
            auto& rank = ranks[i];
            if (i == 0) {
                res[rank.second] = "Gold Medal";
            } else if (i == 1) {
                res[rank.second] = "Silver Medal";
            } else if (i == 2) {
                res[rank.second] = "Bronze Medal";
            } else {
                res[rank.second] = to_string(i + 1);
            }
        }
        return res;
    }
};
*/

/* 反查表：数据过大
        vector<int> scorelist = score;
        vector<int> scorelist2(score.size());
        vector<string> retstring;
        sort(scorelist.begin(), scorelist.end(), greater<int>()); // scorelist (rank,sortedscore)
        for (auto s : scorelist)
        {
            cout << s << ' ';
        }
        cout << endl;

        for (int i = 0; i < score.size(); i++)
        {
            scorelist2[score[i]] = i; // scorelist2 (sortedscore,rank)
        }
        for (auto s : scorelist2)
        {
            cout << s << ' ';
        }
        cout << endl;

        for (int i = 0; i < score.size(); i++)
        {
            scorelist[i] = scorelist2[score[i]]; // scorelist (unsortedscore,rank)
        }
        for (auto s : scorelist)
        {
            cout << s << ' ';
        }
        cout << endl;
*/