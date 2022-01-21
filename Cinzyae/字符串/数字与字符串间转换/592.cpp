/*
给定一个表示分数加减运算表达式的字符串，你需要返回一个字符串形式的计算结果。 这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2 应该被转换为 2/1。

示例 1:

输入:"-1/2+1/2"
输出: "0/1"

 示例 2:

输入:"-1/2+1/2+1/3"
输出: "1/3"

示例 3:

输入:"1/3-1/2"
输出: "-1/6"

示例 4:

输入:"5/3+1/3"
输出: "2/1"

说明:

    输入和输出字符串只包含 '0' 到 '9' 的数字，以及 '/', '+' 和 '-'。 
    输入和输出分数格式均为 ±分子/分母。如果输入的第一个分数或者输出的分数是正数，则 '+' 会被省略掉。
    输入只包含合法的最简分数，每个分数的分子与分母的范围是  [1,10]。 如果分母是1，意味着这个分数实际上是一个整数。
    输入的分数个数范围是 [1,10]。
    最终结果的分子与分母保证是 32 位整数范围内的有效整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fraction-addition-and-subtraction
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
    string fractionAddition(string expression)
    {
        vector<int> fz, fm;
        int sig = 0, flag = 0;
        int n = expression.size();
        for (int i = 0; i < n; i++)
        {
            if (expression[i] == '+')
                sig = i;
            if (expression[i] == '-')
                sig = i;
            else if (expression[i] == '/')
                flag = i + 1;
            else if (i == n - 1 || expression[i + 1] == '+' || expression[i + 1] == '-')
            {
                fz.push_back(stoi(expression.substr(sig, i)));
                fm.push_back(stoi(expression.substr(flag, i)));
            }
        }
        // for (int i = 0; i < fz.size(); i++)
        // {
        //     cout << fz[i] << '/' << fm[i] << endl;
        // }
        int ffz = fz[0], ffm = fm[0];
        for (int i = 1; i < fz.size(); i++)
        {
            // cout << ffz << ffm << fz[i] << fm[i] << endl;
            ffz = ffz * fm[i] + ffm * fz[i];
            ffm *= fm[i];
            // cout << ffz << ffm << endl;
        }
        int retsig = 1;
        if (((ffz < 0) && (ffm > 0)) || ((ffz > 0) && (ffm < 0)))
        {
            retsig = -1;
        }
        // cout << retsig << endl;
        ffz = abs(ffz);
        ffm = abs(ffm);
        int gcdnum = gcd(ffz, ffm);
        return to_string(retsig * (ffz / gcdnum)) + '/' + to_string(ffm / gcdnum);
    }
    int gcd(int a, int b)
    {
        int r;
        while (b > 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
};
int main()
{
    string test = "4/1+6/5-1/8-9/2-1/1+6/7-10/7-3/4-3/2-1/1";
    Solution S;
    cout << S.fractionAddition(test) << endl;
    return 0;
}