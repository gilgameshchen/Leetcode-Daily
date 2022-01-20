/*
给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。

 

示例 1：

输入：timePoints = ["23:59","00:00"]
输出：1

示例 2：

输入：timePoints = ["00:00","23:59","00:00"]
输出：0

 

提示：

    2 <= timePoints.length <= 2 * 104
    timePoints[i] 格式为 "HH:MM"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-time-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        int N = timePoints.size();
        vector<int> timeMinutes;
        int minMinutes = 1440;
        for (auto timePoint : timePoints)
        {
            timeMinutes.push_back(stoi(timePoint) * 60 + stoi(timePoint.substr(3, 2)));
        }
        sort(timeMinutes.begin(), timeMinutes.end());
        for (int i = 1; i < N; i++)
        {
            minMinutes = min(abs(timeMinutes[i] - timeMinutes[i - 1]), minMinutes);
        }
        minMinutes = min(1440 - abs(timeMinutes[0] - timeMinutes[N - 1]), minMinutes);
        return minMinutes;
    }
};
int main()
{
    vector<string> timePoints = {"23:59", "00:00"};
    Solution S;
    cout << S.findMinDifference(timePoints) << endl;
    return 0;
}
/* 每添加一个time与之前添加的所有time比较，耗时较长
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> timeMinutes;
        int minMinutes = 1440;
        for (auto timePoint : timePoints)
        {
            int thistime = stoi(timePoint) * 60 + stoi(timePoint.substr(3, 2));
            for (auto time : timeMinutes)
            {
                int thisminMinutes = min(1440 - abs(thistime - time), abs(thistime - time));
                minMinutes = min(minMinutes, thisminMinutes);
            }
            timeMinutes.push_back(thistime);
        }
        return minMinutes;
    }
};
*/