#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> outline;
        int mup = 0, mdown = m - 1, mleft = 0, mright = n - 1;
        for (int _ = 0; _ < m * n / 4 + 1 ; _++)
        {
            if (mup <= mdown)
            {
                for (int i = mleft; i <= mright; i++)
                {
                    outline.push_back(matrix[mup][i]);
                }
                mup++;
            }
            if (mleft <= mright)
            {
                for (int i = mup; i <= mdown; i++)
                {
                    outline.push_back(matrix[i][mright]);
                }
                mright--;
            }
            if (mup <= mdown)
            {
                for (int i = mright; i >= mleft; i--)
                {
                    outline.push_back(matrix[mdown][i]);
                }
                mdown--;
            }
            if (mleft <= mright)
            {
                for (int i = mdown; i >= mup; i--)
                {
                    outline.push_back(matrix[i][mleft]);
                }
                mleft++;
            }
        }
        outline.resize(m * n);
        return outline;
    }
};
int main()
{
    vector<vector<int>> testnums = {{1, 2, 3}};
    Solution S;
    for (auto num : S.spiralOrder(testnums))
        cout << num << " ";
    return 0;
}