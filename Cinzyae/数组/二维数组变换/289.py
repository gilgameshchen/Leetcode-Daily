"""
根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

    如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
    如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
    如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
    如果死细胞周围正好有三个活细胞，则该位置死细胞复活；

下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。

 

示例 1：

输入：board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
输出：[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

示例 2：

输入：board = [[1,1],[1,0]]
输出：[[1,1],[1,1]]

 

提示：

    m == board.length
    n == board[i].length
    1 <= m, n <= 25
    board[i][j] 为 0 或 1

 

进阶：

    你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
    本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/game-of-life
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


from typing import List


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])

        for i in range(m):
            for j in range(n):
                live = 0
                print(board)
                for k1 in (i - 1, i, i + 1):
                    for k2 in (j - 1, j, j + 1):
                        if (k1 == i) & (k2 == j):
                            continue
                        if (0 <= k1 < m) & (0 <= k2 < n):
                            live += board[k1][k2] % 2
                print(i, j, live)
                if board[i][j] == 0:
                    if live == 3:
                        board[i][j] = 2  # 10
                    else:
                        board[i][j] = 0  # 00
                elif board[i][j] == 1:
                    if live < 2:
                        board[i][j] = 1  # 01
                    elif live > 3:
                        board[i][j] = 1  # 01
                    else:
                        board[i][j] = 3  # 11

        for i in range(m):
            for j in range(n):
                board[i][j] = int(board[i][j] / 2)


testlist = [[0, 1, 0], [0, 0, 1], [1, 1, 1], [0, 0, 0]]
S = Solution()
S.gameOfLife(testlist)
print(testlist)
