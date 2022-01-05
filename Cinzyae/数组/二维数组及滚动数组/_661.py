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

        for i in range(n):
            img[i] = [0] + img[i] + [0]
        img = [[0 for i in range(m + 2)]] + img + [[0 for j in range(m + 2)]]
        print(img)
        img2 = []
        for i in range(n):
            img2.append([])
            for j in range(m):
                img2[i].append(
                    int(
                        (
                            img[i][j]
                            + img[i][j + 1]
                            + img[i][j + 2]
                            + img[i + 1][j]
                            + img[i + 1][j + 1]
                            + img[i + 1][j + 2]
                            + img[i + 2][j]
                            + img[i + 2][j + 1]
                            + img[i + 2][j + 2]
                        )
                        / 9
                    )
                )
        return img2

img=[[100,200,100],[200,50,200],[100,200,100]]
S=Solution()
print(S.imageSmoother(img))