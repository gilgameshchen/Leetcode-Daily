"""
包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入) ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。

示例 1:

输入:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
输出:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
解释:
对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0

注意:

    给定矩阵中的整数范围为 [0, 255]。
    矩阵的长和宽的范围均为 [1, 150]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/image-smoother
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import List


class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        n = len(img)
        m = len(img[0])

        img2 = []
        # line 1
        img2.append([])
        img2[0].append(int((img[0][0] + img[0][1] + img[1][0] + img[1][1]) / 4))
        for j in range(1, m - 1):
            img2[0].append(
                int(
                    (
                        img[0][j - 1]
                        + img[0][j]
                        + img[0][j + 1]
                        + img[1][j - 1]
                        + img[1][j]
                        + img[1][j + 1]
                    )
                    / 6
                )
            )
        img2[0].append(
            int((img[0][m - 2] + img[0][m - 1] + img[1][m - 2] + img[1][m - 1]) / 4)
        )
        # line 2 to n-1
        for i in range(1, n - 1):
            img2.append([])
            img2[i].append(
                int(
                    (
                        img[i - 1][0]
                        + img[i - 1][1]
                        + img[i][0]
                        + img[i][1]
                        + img[i + 1][0]
                        + img[i + 1][1]
                    )
                    / 6
                )
            )
            for j in range(1, m - 1):
                img2[i].append(
                    int(
                        (
                            img[i - 1][j - 1]
                            + img[i - 1][j]
                            + img[i - 1][j + 1]
                            + img[i][j - 1]
                            + img[i][j]
                            + img[i][j + 1]
                            + img[i + 1][j - 1]
                            + img[i + 1][j]
                            + img[i + 1][j + 1]
                        )
                        / 9
                    )
                )
            img2[i].append(
                int(
                    (
                        img[i - 1][m - 2]
                        + img[i - 1][m - 1]
                        + img[i][m - 2]
                        + img[i][m - 1]
                        + img[i + 1][m - 2]
                        + img[i + 1][m - 1]
                    )
                    / 6
                )
            )
        # line n
        img2.append([])
        img2[n - 1].append(
            int((img[n - 2][0] + img[n - 2][1] + img[n - 1][0] + img[n - 1][1]) / 4)
        )
        for j in range(1, m - 1):
            img2[n - 1].append(
                int(
                    (
                        img[n - 2][j - 1]
                        + img[n - 2][j]
                        + img[n - 2][j + 1]
                        + img[n - 1][j - 1]
                        + img[n - 1][j]
                        + img[n - 1][j + 1]
                    )
                    / 6
                )
            )
        img2[n - 1].append(
            int(
                (
                    img[n - 2][m - 2]
                    + img[n - 2][m - 1]
                    + img[n - 1][m - 2]
                    + img[n - 1][m - 1]
                )
                / 4
            )
        )
        return img2


img = [[1],[1],[1],[1]]

S = Solution()
print(S.imageSmoother(img))
