/*
求解一个给定的方程，将x以字符串"x=#value"的形式返回。该方程仅包含'+'，' - '操作，变量 x 和其对应系数。

如果方程没有解，请返回“No solution”。

如果方程有无限解，则返回“Infinite solutions”。

如果方程中只有一个解，要保证返回值 x 是一个整数。

示例 1：

输入: "x+5-3+x=6+x-2"
输出: "x=2"

示例 2:

输入: "x=x"
输出: "Infinite solutions"

示例 3:

输入: "2x=x"
输出: "x=0"

示例 4:

输入: "2x+3x-6x=x+2"
输出: "x=-1"

示例 5:

输入: "x=x+2"
输出: "No solution"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/solve-the-equation
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
    string solveEquation(string equation)
    {
        int n = equation.size();
        vector<int> left, right;
        int sig = 0, leftx = 0, rightx = 0;
        for (int i = sig; i < n; i++)
        {
            if (equation[i] == '=')
            {
                sig = i + 1;
                break;
            }
            else if (equation[i] == '+')
            {
                sig = i;
            }
            else if (equation[i] == '-')
            {
                sig = i;
            }
            else if (equation[i] == 'x')
            {
                if (sig + 1 < i)
                {
                    leftx += stoi(equation.substr(sig, i + 1));
                }
                else if (isdigit(equation[sig]))
                {
                    leftx += stoi(equation.substr(sig, i + 1));
                }
                else if (equation[sig] == '+' || equation[sig] == 'x')
                {
                    leftx++;
                }
                else if (equation[sig] == '-')
                {
                    leftx--;
                }
                cout << leftx << ' ';
            }
            else if (equation[i + 1] == '=' || equation[i + 1] == '+' || equation[i + 1] == '-')
            {
                left.push_back(stoi(equation.substr(sig, i + 1)));
            }
        }
        cout << endl;
        for (int i = sig; i < n; i++)
        {
            if (equation[i] == '+')
            {
                sig = i;
            }
            else if (equation[i] == '-')
            {
                sig = i;
            }
            else if (equation[i] == 'x')
            {
                if (sig + 1 < i)
                {
                    rightx += stoi(equation.substr(sig, i + 1));
                }
                else if (isdigit(equation[sig]))
                {
                    rightx += stoi(equation.substr(sig, i + 1));
                }
                else if (equation[sig] == '+' || equation[sig] == 'x')
                {
                    rightx++;
                }
                else if (equation[sig] == '-')
                {
                    rightx--;
                }
                cout << rightx << ' ';
            }
            else if (i == n - 1 || equation[i + 1] == '+' || equation[i + 1] == '-')
            {
                right.push_back(stoi(equation.substr(sig, i + 1)));
            }
        }

        // for (auto num : left)
        // {
        //     cout << num << ' ';
        // }
        // cout << leftx;
        // cout << endl;
        // for (auto num : right)
        // {
        //     cout << num << ' ';
        // }
        // cout << rightx;

        int acc = 0;
        for (auto num : left)
        {
            acc -= num;
        }
        for (auto num : right)
        {
            acc += num;
        }

        if (leftx == rightx)
        {
            if (acc)
            {
                return "No solution";
            }
            else
            {
                return "Infinite solutions";
            }
        }
        else
        {
            if (acc)
            {
                acc /= (leftx - rightx);
                return "x=" + to_string(acc);
            }
            else
            {
                return "x=0";
            }
        }
    }
};
int main()
{
    string test = "x+5-3+x=6+x-2";
    Solution S;
    cout << S.solveEquation(test) << endl;
    return 0;
}