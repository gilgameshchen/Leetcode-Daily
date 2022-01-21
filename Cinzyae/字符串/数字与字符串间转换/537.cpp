/*
复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：

    实部 是一个整数，取值范围是 [-100, 100]
    虚部 也是一个整数，取值范围是 [-100, 100]
    i2 == -1

给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符串。

 

示例 1：

输入：num1 = "1+1i", num2 = "1+1i"
输出："0+2i"
解释：(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。

示例 2：

输入：num1 = "1+-1i", num2 = "1+-1i"
输出："0+-2i"
解释：(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 

 

提示：

    num1 和 num2 都是有效的复数表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complex-number-multiplication
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
    string complexNumberMultiply(string num1, string num2)
    {
        int n1a = stoi(num1), n1b = stoi(num1.substr(num1.find('+') + 1)), n2a = stoi(num2), n2b = stoi(num2.substr(num2.find('+') + 1));
        return to_string(n1a * n2a - n1b * n2b) + "+" + to_string(n1a * n2b + n1b * n2a) + "i";
    }
};
int main()
{
    Solution S;
    cout << S.complexNumberMultiply("1+1i", "1+1i") << endl;
    return 0;
}
/*
        int n1a = stoi(num1), n1b = stoi(num1.substr(2)), n2a = stoi(num2), n2b = stoi(num2.substr(2));
        int A = n1a * n2a - n1b * n2b;
        int B = n1a * n2b + n1b * n2a;
        return to_string(A)+"+"+to_string(B)+"i";
*/