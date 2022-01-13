#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int length = nums.size();
        int step = 0;
        int numssum = 0;
        for (int i = 0; i < length; i++)
        {
            numssum += nums[i] * i;
            step += nums[i];
        }
        int max = numssum;
        for (int i = 0; i < length; i++)
        {
            numssum = numssum + step - length * nums[length - i - 1];
            if (numssum > max)
            {
                max = numssum;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> testnums = {};
    // Solution S;
    // cout << S(testnums) << endl;
    // for (auto num : S(testnums)) cout << num << " ";
    return 0;
}